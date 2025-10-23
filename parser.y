
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

typedef struct symbol {
    char *name;
    char *type;
    int scope;  // 0: global, 1: local
    struct symbol *next;
} symbol_t;

symbol_t *symbol_table = NULL;

void add_symbol(char *name, char *type, int scope);
int lookup_symbol(char *name, int scope);
void clear_local_symbols();

%}

%union {
  int integer;
  double double_val;
  char char_val;
  char *string;
}

%token <integer> INTEGER_LITERAL
%token <double_val> DOUBLE_LITERAL
%token <char_val> CHAR_LITERAL
%token <string> STRING_LITERAL IDENTIFIER
%token PUBLIC PRIVATE CLASS INT CHAR DOUBLE BOOLEAN STRING VOID NEW RETURN IF ELSE WHILE DO FOR SWITCH CASE DEFAULT BREAK TRUE FALSE PRINT
%token LBRACE RBRACE LPAREN RPAREN LBRACK RBRACK SEMICOLON COMMA DOT ASSIGN PLUS MINUS MULTIPLY DIVIDE GREATER LESS EQUALS NOT_EQUALS AND OR
%token COLON BOOLEAN_LITERAL

%type <string> data_type identifier parameter_list 

%left OR
%left AND
%left EQUALS NOT_EQUALS
%left LESS GREATER
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left INT CHAR DOUBLE BOOLEAN STRING
%left IDENTIFIER

%left SEMICOLON
%left LPAREN


%start program

%%

program:
    class_list
    ;

class_list:
    class
    | class_list class
    ;

class:
    PUBLIC CLASS identifier LBRACE class_body RBRACE {
        clear_local_symbols();  // Clear local scope symbols after class definition
    }
    ;

class_body:
    class_element
    | class_body class_element
    ;

class_element:
    variable_declaration
    | method_declaration
    ;


/* class_definition:
    PUBLIC CLASS IDENTIFIER LBRACE class_body RBRACE {
        printf("Parsed class '%s' successfully at line %d.\n", $3, yylineno);
    }
; */



variable_declaration:
    /*opt_modifier*/ data_type identifier opt_assignment SEMICOLON {
        add_symbol($<string>3, $<string>2, 1);  // Add the variable to the symbol table
    }
    | /*opt_modifier*/ data_type identifier_list SEMICOLON {
        // Add all identifiers in identifier_list to the symbol table
    }
    ;

identifier_list:
    identifier opt_assignment
    | identifier opt_assignment COMMA identifier_list
    ;

method_declaration:
    opt_modifier return_type identifier LPAREN opt_parameter_list RPAREN LBRACE method_body RBRACE {
        clear_local_symbols();  // Clear local scope symbols after method definition
    }
    ;

return_type:
    data_type
    | VOID
    ;

  opt_modifier:
    PUBLIC
    | PRIVATE
    | ; 
    

data_type:
    INT { $$ = strdup("int"); }
    | CHAR { $$ = strdup("char"); }
    | DOUBLE { $$ = strdup("double"); }
    | BOOLEAN { $$ = strdup("boolean"); }
    | STRING { $$ = strdup("String"); }
    ;

 opt_assignment:
    ASSIGN expression
    | /* empty */
    ;

 opt_parameter_list:
    parameter_list
    | /* empty */
    ;

parameter_list:
    data_type identifier {
        add_symbol($<string>2, $<string>1, 1);  // Add parameter to symbol table
    }
    | parameter_list COMMA data_type identifier {
        add_symbol($<string>4, $<string>3, 1);  // Add parameter to symbol table
    }
    ;

method_body:
    /* empty */
    | statement_list
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    variable_declaration 
    | assignment_statement 
    | loop_statement
    | control_statement
    | print_statement
    | return_statement
    | break_statement
    ;

assignment_statement:
    identifier ASSIGN expression SEMICOLON {
        if (!lookup_symbol($1, 1) && !lookup_symbol($1, 0)) {
            printf("Error: Variable '%s' not declared at line %d.\n", $1, yylineno);
        } else {
            printf("Assignment to variable '%s' successful at line %d.\n", $1, yylineno);
        }
    }


 loop_statement:
    do_while_loop
    | for_loop
    ;

do_while_loop:
    DO LBRACE statement_list RBRACE WHILE LPAREN condition RPAREN SEMICOLON
    ;

for_loop:
    FOR LPAREN assignment_statement condition SEMICOLON assignment_statement RPAREN LBRACE statement_list RBRACE
    ;

control_statement:
    if_statement
    | switch_statement
    ;

if_statement:
    IF LPAREN condition RPAREN LBRACE statement_list RBRACE opt_else_clause
    ;

opt_else_clause:
    ELSE LBRACE statement_list RBRACE
    | /* empty */
    ;

switch_statement:
    SWITCH LPAREN expression RPAREN LBRACE case_list opt_default_case RBRACE
    ;

case_list:
    /* empty */
    | case_list CASE expression COLON statement_list
    ;

opt_default_case:
    DEFAULT COLON statement_list
    | /* empty */
    ;

print_statement:
    PRINT LPAREN STRING_LITERAL opt_print_var RPAREN SEMICOLON
    ;

opt_print_var:

    COMMA identifier
    | /* empty */
    ;

return_statement:
    RETURN opt_expression SEMICOLON
    ;

opt_expression:
    expression
    | /* empty */
    ;

break_statement:
    BREAK SEMICOLON
    ;

expression:
    literal
    | identifier
    | expression PLUS expression
    | expression MINUS expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | LPAREN expression RPAREN
    | method_call
    | object_creation
    ;

method_call:
    identifier DOT identifier LPAREN opt_argument_list RPAREN
    ;

object_creation:
    NEW identifier LPAREN RPAREN
    ;

opt_argument_list:
    argument_list
    | /* empty */
    ;

argument_list:
    expression
    | argument_list COMMA expression
    ;

condition:
    expression relational_operator expression
    | boolean_literal
    | condition logical_operator condition
    | LPAREN condition RPAREN
    ;

relational_operator:
    GREATER
    | LESS
    | EQUALS
    | NOT_EQUALS
    ;

logical_operator:
    AND
    | OR
    ;

literal:
    INTEGER_LITERAL
    | CHAR_LITERAL
    | DOUBLE_LITERAL
    | BOOLEAN_LITERAL
    | STRING_LITERAL
    ;

boolean_literal:
    TRUE
    | FALSE
    ;

identifier:
    IDENTIFIER
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, near '%s'\n", s, yylineno, yytext);
}

void add_symbol(char *name, char *type, int scope) {
    // Add symbol to the symbol table
    // Implementation needed here
}

int lookup_symbol(char *name, int scope) {
    // Lookup symbol in the symbol table
    // Implementation needed here
    return 0;  // Return 0 if not found, 1 if found
}

void clear_local_symbols() {
    // Clear all symbols from the local scope
    // Implementation needed here
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}

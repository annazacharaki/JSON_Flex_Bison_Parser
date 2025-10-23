%{
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno 
%x comment   	

digit           [0-9]
letter          [A-Za-z]
capital_letter  [A-Z]
identifier      {letter}({letter}|{digit}|_)*

%%

"public"        { return PUBLIC; }
"class"         { return CLASS; }


"int" {
    printf("Lexer recognized 'int' at line %d\n", yylineno);
    return INT;
}


"char"          { return CHAR; }
"double"        { return DOUBLE; }
"boolean"       { return BOOLEAN; }
"String"        { return STRING; }
"void"          { return VOID; }
"new"           { return NEW; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"do"            { return DO; }
"for"           { return FOR; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"break"         { return BREAK; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"private"       { return PRIVATE; }
"out.print"     { return PRINT; }

{identifier}    { yylval.string = strdup(yytext); return IDENTIFIER; }
{digit}+        { yylval.integer = atoi(yytext); return INTEGER_LITERAL; }
{digit}+"d"     { yylval.double_val = atof(yytext); return DOUBLE_LITERAL; }
\'[^\']\'       { yylval.char_val = yytext[1]; return CHAR_LITERAL; }
\"[^\"]*\"      { yylval.string = strdup(yytext); return STRING_LITERAL; }

"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"."             { return DOT; }
"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
">"             { return GREATER; }
"<"             { return LESS; }
"=="            { return EQUALS; }
"!="            { return NOT_EQUALS; }
"&&"            { return AND; }
"||"            { return OR; }






[ \t\n\r]+      { /* ignore whitespace */ }

"//".*          { /* ignore single-line comments */ }
"/*"			{ BEGIN(comment); }  /* Έναρξη πολυγραμμικού σχολίου */
<comment>"*/"   { BEGIN(INITIAL); }  /* Τέλος πολυγραμμικού σχολίου */
<comment>.      { /* Αγνόησε όλους τους άλλους χαρακτήρες */ }
<comment>\n     { /* Αγνόησε τις νέες γραμμές */ }

"/*"([^*]|\*+[^*/])*\*+"/"   { /* ignore multi-line comments */ }

.               { printf("Unexpected character: %s\n", yytext); exit(1); }

%%

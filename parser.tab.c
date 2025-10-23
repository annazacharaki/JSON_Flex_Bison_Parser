/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

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


#line 97 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER_LITERAL = 3,            /* INTEGER_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 4,             /* DOUBLE_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 5,               /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_PUBLIC = 8,                     /* PUBLIC  */
  YYSYMBOL_PRIVATE = 9,                    /* PRIVATE  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 13,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 14,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 15,                    /* STRING  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_NEW = 17,                       /* NEW  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_TRUE = 28,                      /* TRUE  */
  YYSYMBOL_FALSE = 29,                     /* FALSE  */
  YYSYMBOL_PRINT = 30,                     /* PRINT  */
  YYSYMBOL_LBRACE = 31,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 32,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 33,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 34,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 35,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 36,                    /* RBRACK  */
  YYSYMBOL_SEMICOLON = 37,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_DOT = 39,                       /* DOT  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 41,                      /* PLUS  */
  YYSYMBOL_MINUS = 42,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 43,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 44,                    /* DIVIDE  */
  YYSYMBOL_GREATER = 45,                   /* GREATER  */
  YYSYMBOL_LESS = 46,                      /* LESS  */
  YYSYMBOL_EQUALS = 47,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 48,                /* NOT_EQUALS  */
  YYSYMBOL_AND = 49,                       /* AND  */
  YYSYMBOL_OR = 50,                        /* OR  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_BOOLEAN_LITERAL = 52,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_class_list = 55,                /* class_list  */
  YYSYMBOL_class = 56,                     /* class  */
  YYSYMBOL_class_body = 57,                /* class_body  */
  YYSYMBOL_class_element = 58,             /* class_element  */
  YYSYMBOL_variable_declaration = 59,      /* variable_declaration  */
  YYSYMBOL_identifier_list = 60,           /* identifier_list  */
  YYSYMBOL_method_declaration = 61,        /* method_declaration  */
  YYSYMBOL_return_type = 62,               /* return_type  */
  YYSYMBOL_opt_modifier = 63,              /* opt_modifier  */
  YYSYMBOL_data_type = 64,                 /* data_type  */
  YYSYMBOL_opt_assignment = 65,            /* opt_assignment  */
  YYSYMBOL_opt_parameter_list = 66,        /* opt_parameter_list  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_method_body = 68,               /* method_body  */
  YYSYMBOL_statement_list = 69,            /* statement_list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_assignment_statement = 71,      /* assignment_statement  */
  YYSYMBOL_loop_statement = 72,            /* loop_statement  */
  YYSYMBOL_do_while_loop = 73,             /* do_while_loop  */
  YYSYMBOL_for_loop = 74,                  /* for_loop  */
  YYSYMBOL_control_statement = 75,         /* control_statement  */
  YYSYMBOL_if_statement = 76,              /* if_statement  */
  YYSYMBOL_opt_else_clause = 77,           /* opt_else_clause  */
  YYSYMBOL_switch_statement = 78,          /* switch_statement  */
  YYSYMBOL_case_list = 79,                 /* case_list  */
  YYSYMBOL_opt_default_case = 80,          /* opt_default_case  */
  YYSYMBOL_print_statement = 81,           /* print_statement  */
  YYSYMBOL_opt_print_var = 82,             /* opt_print_var  */
  YYSYMBOL_return_statement = 83,          /* return_statement  */
  YYSYMBOL_opt_expression = 84,            /* opt_expression  */
  YYSYMBOL_break_statement = 85,           /* break_statement  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_method_call = 87,               /* method_call  */
  YYSYMBOL_object_creation = 88,           /* object_creation  */
  YYSYMBOL_opt_argument_list = 89,         /* opt_argument_list  */
  YYSYMBOL_argument_list = 90,             /* argument_list  */
  YYSYMBOL_condition = 91,                 /* condition  */
  YYSYMBOL_relational_operator = 92,       /* relational_operator  */
  YYSYMBOL_logical_operator = 93,          /* logical_operator  */
  YYSYMBOL_literal = 94,                   /* literal  */
  YYSYMBOL_boolean_literal = 95,           /* boolean_literal  */
  YYSYMBOL_identifier = 96                 /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   325

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    67,    68,    72,    78,    79,    83,    84,
      97,   100,   106,   107,   111,   117,   118,   122,   123,   124,
     128,   129,   130,   131,   132,   136,   137,   141,   142,   146,
     149,   154,   156,   160,   161,   165,   166,   167,   168,   169,
     170,   171,   175,   185,   186,   190,   194,   198,   199,   203,
     207,   208,   212,   215,   217,   221,   222,   226,   231,   232,
     236,   240,   241,   245,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   261,   265,   269,   270,   274,   275,   279,
     280,   281,   282,   286,   287,   288,   289,   293,   294,   298,
     299,   300,   301,   302,   306,   307,   311
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER_LITERAL",
  "DOUBLE_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "PUBLIC", "PRIVATE", "CLASS", "INT", "CHAR", "DOUBLE", "BOOLEAN",
  "STRING", "VOID", "NEW", "RETURN", "IF", "ELSE", "WHILE", "DO", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "TRUE", "FALSE", "PRINT", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "SEMICOLON", "COMMA",
  "DOT", "ASSIGN", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "GREATER",
  "LESS", "EQUALS", "NOT_EQUALS", "AND", "OR", "COLON", "BOOLEAN_LITERAL",
  "$accept", "program", "class_list", "class", "class_body",
  "class_element", "variable_declaration", "identifier_list",
  "method_declaration", "return_type", "opt_modifier", "data_type",
  "opt_assignment", "opt_parameter_list", "parameter_list", "method_body",
  "statement_list", "statement", "assignment_statement", "loop_statement",
  "do_while_loop", "for_loop", "control_statement", "if_statement",
  "opt_else_clause", "switch_statement", "case_list", "opt_default_case",
  "print_statement", "opt_print_var", "return_statement", "opt_expression",
  "break_statement", "expression", "method_call", "object_creation",
  "opt_argument_list", "argument_list", "condition", "relational_operator",
  "logical_operator", "literal", "boolean_literal", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     5,    23,     0,  -104,    10,  -104,  -104,  -104,    24,
     297,  -104,  -104,  -104,  -104,  -104,  -104,  -104,   115,  -104,
    -104,  -104,   279,    10,  -104,  -104,  -104,    10,  -104,     4,
      26,    34,  -104,   108,   -32,   310,  -104,  -104,  -104,  -104,
      10,   108,  -104,    78,  -104,  -104,  -104,    32,  -104,    10,
      10,    39,    42,    44,    16,   108,   108,   108,   108,    10,
    -104,    26,  -104,    51,   310,    50,  -104,   -31,   -31,  -104,
    -104,    55,    56,   255,    10,  -104,   108,   108,    63,    66,
      67,    70,    61,    71,  -104,    84,   255,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,    77,  -104,
      78,    97,    94,    98,    78,    58,   255,    10,   108,  -104,
     128,  -104,  -104,   108,  -104,   108,  -104,  -104,  -104,    58,
     256,   -20,  -104,   167,    58,    65,    99,   276,    78,   110,
     -18,  -104,  -104,  -104,  -104,   108,   105,  -104,  -104,    58,
     118,     3,   109,    10,   111,  -104,  -104,    78,   255,   -16,
     116,    10,  -104,  -104,   122,   189,    58,   114,    17,  -104,
     141,   -13,   131,   108,    91,   133,   132,  -104,   130,   255,
     245,   255,  -104,   255,  -104,   211,   255,   255,   233,  -104,
     255,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,    96,     0,
      19,    17,    18,    20,    21,    22,    23,    24,    19,     6,
       8,     9,     0,     0,     5,     7,    16,     0,    15,     0,
      26,     0,    11,     0,     0,    28,    89,    91,    90,    93,
       0,     0,    92,    25,    71,    72,    64,    65,    10,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      13,    26,    29,     0,     0,     0,    70,    66,    67,    68,
      69,     0,    12,    31,     0,    74,    76,    62,     0,     0,
       0,     0,     0,     0,    35,     0,    32,    33,    36,    37,
      43,    44,    38,    47,    48,    39,    40,    41,     0,    30,
      77,     0,    75,     0,    61,     0,     0,     0,     0,    63,
       0,    14,    34,     0,    73,     0,    60,    94,    95,     0,
       0,     0,    80,     0,     0,     0,    59,     0,    78,     0,
       0,    83,    84,    85,    86,     0,     0,    87,    88,     0,
       0,     0,     0,     0,     0,    42,    82,    79,     0,    81,
       0,     0,    53,    58,     0,     0,     0,     0,    56,    57,
      51,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,    52,     0,    45,     0,     0,    55,     0,    46,
      54,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,   166,  -104,   158,    -8,   134,  -104,  -104,
    -104,   -15,   123,  -104,  -104,  -104,   -97,   -85,  -103,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,   -30,  -104,  -104,  -104,  -104,  -100,  -104,
    -104,  -104,  -104,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    18,    19,    84,    29,    21,    27,
      22,    23,    34,    51,    52,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   167,    94,   158,   165,    95,   144,
      96,   103,    97,   120,    44,    45,   101,   102,   121,   135,
     139,    46,   122,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,   112,    20,    43,   124,    48,    49,    28,     1,   123,
      20,    54,    57,    58,   136,     5,   146,     8,    30,   130,
      50,   168,    31,     6,   141,    67,    68,    69,    70,   137,
     138,   137,   138,   137,   138,    53,   137,   138,   112,   149,
     151,    32,   163,   164,    61,    62,   100,   104,   157,    74,
      66,   155,   137,   138,    71,    10,   161,    55,    56,    57,
      58,    36,    37,    38,    39,     8,    33,    35,    98,    99,
     112,    59,   175,    63,   177,    40,   178,    65,   125,   180,
      64,    98,    73,   127,    75,   128,   117,   118,    76,   129,
     112,   119,   112,   112,    49,   112,   105,   106,   109,   142,
     107,    98,    98,   108,   110,   147,    55,    56,    57,    58,
      42,    36,    37,    38,    39,     8,   111,   113,    98,    55,
      56,    57,    58,    11,    12,    40,    13,    14,    15,    16,
      17,   114,   115,   170,   126,   116,   148,   143,   153,   150,
     152,    41,   171,    98,    66,   154,    98,    24,   162,   156,
      98,    55,    56,    57,    58,   131,   132,   133,   134,   159,
      42,   166,   169,   173,    98,   172,    98,   174,    98,     7,
      98,    98,    98,    98,     8,    98,    25,     0,    13,    14,
      15,    16,    17,    60,    72,    77,    78,     0,     0,    79,
      80,    81,     0,     0,    82,     0,     8,    83,     0,   140,
      13,    14,    15,    16,    17,     0,     0,    77,    78,     0,
       0,    79,    80,    81,     0,     0,    82,     0,     8,    83,
       0,   160,    13,    14,    15,    16,    17,     0,     0,    77,
      78,     0,     0,    79,    80,    81,     0,     0,    82,     0,
       8,    83,     0,   179,    13,    14,    15,    16,    17,     0,
       0,    77,    78,     0,     0,    79,    80,    81,     0,     0,
      82,     0,     8,    83,     0,   181,    13,    14,    15,    16,
      17,     0,     0,    77,    78,     0,     0,    79,    80,    81,
       0,     0,    82,     0,     0,    83,    55,    56,    57,    58,
      13,    14,    15,    16,    17,    26,   176,    55,    56,    57,
      58,   131,   132,   133,   134,    11,    12,     0,    13,    14,
      15,    16,    17,   145,     0,     0,     0,    55,    56,    57,
      58,    13,    14,    15,    16,    17
};

static const yytype_int16 yycheck[] =
{
       5,    86,    10,    33,   107,    37,    38,    22,     8,   106,
      18,    41,    43,    44,    34,    10,    34,     7,    23,   119,
      35,    34,    27,     0,   124,    55,    56,    57,    58,    49,
      50,    49,    50,    49,    50,    40,    49,    50,   123,   139,
      37,    37,    25,    26,    49,    50,    76,    77,   151,    64,
      34,   148,    49,    50,    59,    31,   156,    41,    42,    43,
      44,     3,     4,     5,     6,     7,    40,    33,    73,    74,
     155,    39,   169,    34,   171,    17,   173,    33,   108,   176,
      38,    86,    31,   113,    34,   115,    28,    29,    33,   119,
     175,    33,   177,   178,    38,   180,    33,    31,    37,    34,
      33,   106,   107,    33,    33,   135,    41,    42,    43,    44,
      52,     3,     4,     5,     6,     7,    32,    40,   123,    41,
      42,    43,    44,     8,     9,    17,    11,    12,    13,    14,
      15,    34,    38,   163,     6,    37,    31,    38,   143,    21,
      31,    33,    51,   148,    34,    34,   151,    32,    34,    33,
     155,    41,    42,    43,    44,    45,    46,    47,    48,    37,
      52,    20,    31,    31,   169,    32,   171,    37,   173,     3,
     175,   176,   177,   178,     7,   180,    18,    -1,    11,    12,
      13,    14,    15,    49,    61,    18,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    27,    -1,     7,    30,    -1,    32,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    -1,
      -1,    22,    23,    24,    -1,    -1,    27,    -1,     7,    30,
      -1,    32,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    -1,    27,    -1,
       7,    30,    -1,    32,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    22,    23,    24,    -1,    -1,
      27,    -1,     7,    30,    -1,    32,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    30,    41,    42,    43,    44,
      11,    12,    13,    14,    15,    16,    51,    41,    42,    43,
      44,    45,    46,    47,    48,     8,     9,    -1,    11,    12,
      13,    14,    15,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    54,    55,    56,    10,     0,    56,     7,    96,
      31,     8,     9,    11,    12,    13,    14,    15,    57,    58,
      59,    61,    63,    64,    32,    58,    16,    62,    64,    60,
      96,    96,    37,    40,    65,    33,     3,     4,     5,     6,
      17,    33,    52,    86,    87,    88,    94,    96,    37,    38,
      64,    66,    67,    96,    86,    41,    42,    43,    44,    39,
      60,    96,    96,    34,    38,    33,    34,    86,    86,    86,
      86,    96,    65,    31,    64,    34,    33,    18,    19,    22,
      23,    24,    27,    30,    59,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    81,    83,    85,    96,    96,
      86,    89,    90,    84,    86,    33,    31,    33,    33,    37,
      33,    32,    70,    40,    34,    38,    37,    28,    29,    33,
      86,    91,    95,    69,    71,    86,     6,    86,    86,    86,
      91,    45,    46,    47,    48,    92,    34,    49,    50,    93,
      32,    91,    34,    38,    82,    37,    34,    86,    31,    91,
      21,    37,    31,    96,    34,    69,    33,    71,    79,    37,
      32,    91,    34,    25,    26,    80,    20,    77,    34,    31,
      86,    51,    32,    31,    37,    69,    51,    69,    69,    32,
      69,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    72,    73,    74,    75,    75,    76,
      77,    77,    78,    79,    79,    80,    80,    81,    82,    82,
      83,    84,    84,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    95,    95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     1,     2,     1,     1,
       4,     3,     2,     4,     9,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     2,     0,     1,     0,     2,
       4,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     9,    10,     1,     1,     8,
       4,     0,     8,     0,     5,     3,     0,     6,     2,     0,
       3,     1,     0,     2,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     6,     4,     1,     0,     1,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* class: PUBLIC CLASS identifier LBRACE class_body RBRACE  */
#line 72 "parser.y"
                                                     {
        clear_local_symbols();  // Clear local scope symbols after class definition
    }
#line 1343 "parser.tab.c"
    break;

  case 10: /* variable_declaration: data_type identifier opt_assignment SEMICOLON  */
#line 97 "parser.y"
                                                                   {
        add_symbol((yyvsp[-1].string), (yyvsp[-2].string), 1);  // Add the variable to the symbol table
    }
#line 1351 "parser.tab.c"
    break;

  case 11: /* variable_declaration: data_type identifier_list SEMICOLON  */
#line 100 "parser.y"
                                                           {
        // Add all identifiers in identifier_list to the symbol table
    }
#line 1359 "parser.tab.c"
    break;

  case 14: /* method_declaration: opt_modifier return_type identifier LPAREN opt_parameter_list RPAREN LBRACE method_body RBRACE  */
#line 111 "parser.y"
                                                                                                   {
        clear_local_symbols();  // Clear local scope symbols after method definition
    }
#line 1367 "parser.tab.c"
    break;

  case 20: /* data_type: INT  */
#line 128 "parser.y"
        { (yyval.string) = strdup("int"); }
#line 1373 "parser.tab.c"
    break;

  case 21: /* data_type: CHAR  */
#line 129 "parser.y"
           { (yyval.string) = strdup("char"); }
#line 1379 "parser.tab.c"
    break;

  case 22: /* data_type: DOUBLE  */
#line 130 "parser.y"
             { (yyval.string) = strdup("double"); }
#line 1385 "parser.tab.c"
    break;

  case 23: /* data_type: BOOLEAN  */
#line 131 "parser.y"
              { (yyval.string) = strdup("boolean"); }
#line 1391 "parser.tab.c"
    break;

  case 24: /* data_type: STRING  */
#line 132 "parser.y"
             { (yyval.string) = strdup("String"); }
#line 1397 "parser.tab.c"
    break;

  case 29: /* parameter_list: data_type identifier  */
#line 146 "parser.y"
                         {
        add_symbol((yyvsp[0].string), (yyvsp[-1].string), 1);  // Add parameter to symbol table
    }
#line 1405 "parser.tab.c"
    break;

  case 30: /* parameter_list: parameter_list COMMA data_type identifier  */
#line 149 "parser.y"
                                                {
        add_symbol((yyvsp[0].string), (yyvsp[-1].string), 1);  // Add parameter to symbol table
    }
#line 1413 "parser.tab.c"
    break;

  case 42: /* assignment_statement: identifier ASSIGN expression SEMICOLON  */
#line 175 "parser.y"
                                           {
        if (!lookup_symbol((yyvsp[-3].string), 1) && !lookup_symbol((yyvsp[-3].string), 0)) {
            printf("Error: Variable '%s' not declared at line %d.\n", (yyvsp[-3].string), yylineno);
        } else {
            printf("Assignment to variable '%s' successful at line %d.\n", (yyvsp[-3].string), yylineno);
        }
    }
#line 1425 "parser.tab.c"
    break;


#line 1429 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 314 "parser.y"


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

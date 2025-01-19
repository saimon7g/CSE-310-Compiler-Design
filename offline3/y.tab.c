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
#line 1 "1905056.y"

	#include <bits/stdc++.h>
    #include<vector>
	#include "SymbolTable.h"
    #include "SymbolInfo.h"
	#include "Parameter.h"


    using namespace std;

    // external function and variable declarations
	int yylex();
	int yyparse(void);
	void yyerror(char *s);
	void defineFunction(SymbolInfo*,SymbolInfo*,SymbolInfo*);
	string callFunction(SymbolInfo*,SymbolInfo*);
	void declare_fun_variables();
	void print_parse_tree(SymbolInfo*,int);
	bool voidCheck(SymbolInfo*);
	bool errortype_Check(SymbolInfo*);

    

    extern FILE *yyin;
	ofstream errorOutput;
    ofstream logOutput;
    ofstream lexOut;
    ofstream yOut;
	ofstream parse_tree_output;
	extern int errorCount = 0;
	extern int lineCount=1;
	vector<SymbolInfo*> fun_parameter_list;


	SymbolTable *symbolTable=new SymbolTable(11);




#line 111 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    BREAK = 263,                   /* BREAK  */
    VOID = 264,                    /* VOID  */
    RETURN = 265,                  /* RETURN  */
    SWITCH = 266,                  /* SWITCH  */
    CASE = 267,                    /* CASE  */
    DEFAULT = 268,                 /* DEFAULT  */
    CONTINUE = 269,                /* CONTINUE  */
    INCOP = 270,                   /* INCOP  */
    DECOP = 271,                   /* DECOP  */
    ASSIGNOP = 272,                /* ASSIGNOP  */
    NOT = 273,                     /* NOT  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    LCURL = 276,                   /* LCURL  */
    RCURL = 277,                   /* RCURL  */
    LTHIRD = 278,                  /* LTHIRD  */
    RTHIRD = 279,                  /* RTHIRD  */
    COMMA = 280,                   /* COMMA  */
    SEMICOLON = 281,               /* SEMICOLON  */
    CONST_INT = 282,               /* CONST_INT  */
    CONST_FLOAT = 283,             /* CONST_FLOAT  */
    CONST_CHAR = 284,              /* CONST_CHAR  */
    ID = 285,                      /* ID  */
    INT = 286,                     /* INT  */
    CHAR = 287,                    /* CHAR  */
    FLOAT = 288,                   /* FLOAT  */
    DOUBLE = 289,                  /* DOUBLE  */
    ADDOP = 290,                   /* ADDOP  */
    MULOP = 291,                   /* MULOP  */
    BITOP = 292,                   /* BITOP  */
    RELOP = 293,                   /* RELOP  */
    LOGICOP = 294,                 /* LOGICOP  */
    PRINTLN = 295,                 /* PRINTLN  */
    LOWER_THAN_ELSE = 296          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define VOID 264
#define RETURN 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define CONTINUE 269
#define INCOP 270
#define DECOP 271
#define ASSIGNOP 272
#define NOT 273
#define LPAREN 274
#define RPAREN 275
#define LCURL 276
#define RCURL 277
#define LTHIRD 278
#define RTHIRD 279
#define COMMA 280
#define SEMICOLON 281
#define CONST_INT 282
#define CONST_FLOAT 283
#define CONST_CHAR 284
#define ID 285
#define INT 286
#define CHAR 287
#define FLOAT 288
#define DOUBLE 289
#define ADDOP 290
#define MULOP 291
#define BITOP 292
#define RELOP 293
#define LOGICOP 294
#define PRINTLN 295
#define LOWER_THAN_ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "1905056.y"

    class SymbolInfo* symbol_info;

#line 250 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_SWITCH = 11,                    /* SWITCH  */
  YYSYMBOL_CASE = 12,                      /* CASE  */
  YYSYMBOL_DEFAULT = 13,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_INCOP = 15,                     /* INCOP  */
  YYSYMBOL_DECOP = 16,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 17,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_LCURL = 21,                     /* LCURL  */
  YYSYMBOL_RCURL = 22,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 23,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 24,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_CONST_INT = 27,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 28,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 29,                /* CONST_CHAR  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_CHAR = 32,                      /* CHAR  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 34,                    /* DOUBLE  */
  YYSYMBOL_ADDOP = 35,                     /* ADDOP  */
  YYSYMBOL_MULOP = 36,                     /* MULOP  */
  YYSYMBOL_BITOP = 37,                     /* BITOP  */
  YYSYMBOL_RELOP = 38,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 39,                   /* LOGICOP  */
  YYSYMBOL_PRINTLN = 40,                   /* PRINTLN  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_start = 43,                     /* start  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_unit = 45,                      /* unit  */
  YYSYMBOL_func_declaration = 46,          /* func_declaration  */
  YYSYMBOL_func_definition = 47,           /* func_definition  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_compound_statement = 51,        /* compound_statement  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_var_declaration = 54,           /* var_declaration  */
  YYSYMBOL_type_specifier = 55,            /* type_specifier  */
  YYSYMBOL_declaration_list = 56,          /* declaration_list  */
  YYSYMBOL_statements = 57,                /* statements  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_expression_statement = 59,      /* expression_statement  */
  YYSYMBOL_variable = 60,                  /* variable  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_logic_expression = 62,          /* logic_expression  */
  YYSYMBOL_rel_expression = 63,            /* rel_expression  */
  YYSYMBOL_simple_expression = 64,         /* simple_expression  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_unary_expression = 66,          /* unary_expression  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_argument_list = 68,             /* argument_list  */
  YYSYMBOL_arguments = 69                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    79,    92,   105,   116,   127,   140,   163,
     190,   190,   212,   212,   235,   254,   272,   288,   306,   306,
     330,   330,   351,   378,   389,   401,   414,   430,   453,   469,
     491,   502,   516,   527,   538,   549,   566,   581,   598,   614,
     632,   647,   659,   681,   698,   725,   746,   782,   802,   826,
     846,   869,   887,   908,   928,   954,   976,   997,  1011,  1028,
    1053,  1067,  1078,  1089,  1109,  1132,  1146,  1154,  1169
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "BREAK", "VOID", "RETURN", "SWITCH", "CASE", "DEFAULT",
  "CONTINUE", "INCOP", "DECOP", "ASSIGNOP", "NOT", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "CONST_INT",
  "CONST_FLOAT", "CONST_CHAR", "ID", "INT", "CHAR", "FLOAT", "DOUBLE",
  "ADDOP", "MULOP", "BITOP", "RELOP", "LOGICOP", "PRINTLN",
  "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "$@2", "parameter_list",
  "compound_statement", "$@3", "$@4", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -65,   -65,   -65,     8,     1,   -65,   -65,   -65,   -65,
      -4,   -65,   -65,    -1,    33,     4,     9,    -2,   -65,    12,
      -5,    18,    26,    29,   -65,    41,    45,     1,   -65,   -65,
      53,    61,   -65,   -65,    41,    55,    64,    84,    70,   -65,
     -65,   -65,    76,    77,    78,   108,   108,   108,   -65,   -65,
     -65,    28,   108,    79,   -65,   -65,    69,    51,   -65,   -65,
      59,    74,   -65,    62,   -19,    68,   -65,   -65,   -65,   108,
     102,   108,    80,    52,   -65,    87,   108,   108,   -65,    83,
      85,   -65,   -65,   -65,   -65,   108,   -65,   108,   108,   108,
     108,    89,   102,    96,   -65,   -65,   -65,    98,    97,    99,
     105,   -65,   -65,    68,   104,   -65,    84,   108,    84,   -65,
     108,   -65,   107,   127,   114,   -65,   -65,   -65,    84,    84,
     -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    12,
       0,    17,     0,    26,     9,     0,    10,     0,    16,    29,
       0,    18,    13,     8,     0,    15,     0,     0,     0,    11,
      14,    27,     0,     0,     0,     0,     0,     0,    41,    61,
      62,    43,     0,     0,    34,    32,     0,     0,    30,    33,
      58,     0,    45,    47,    49,    51,    53,    57,    21,     0,
       0,     0,     0,    58,    56,     0,    66,     0,    55,     0,
      28,    19,    31,    63,    64,     0,    42,     0,     0,     0,
       0,     0,     0,     0,    40,    60,    68,     0,    65,     0,
       0,    46,    48,    52,    50,    54,     0,     0,     0,    59,
       0,    44,     0,    36,     0,    38,    67,    39,     0,     0,
      37,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   135,   -65,   -65,   -65,   -65,   -65,   -11,
     -65,   -65,    40,     2,   -65,   -65,   -53,   -61,   -46,   -44,
     -64,    54,    56,    58,   -41,   -65,   -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    25,    20,    54,
      37,    38,    55,    56,    14,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      73,    72,    10,    75,    82,    74,    73,    10,    11,    92,
       1,    78,    96,     1,    32,    26,    88,    21,    15,    89,
      27,   101,    16,    39,    19,    91,    13,    93,    23,    35,
      73,   107,     2,    99,     3,     2,    22,     3,    24,    73,
       9,    73,    73,    73,    73,     9,   116,    76,    28,   105,
      29,    77,    30,   113,    42,   115,    43,    44,    17,    18,
       1,    45,    31,   114,    73,   120,   121,    83,    84,    46,
      47,    33,    31,    81,    83,    84,    85,    48,    49,    50,
      36,    51,     2,   -20,     3,    40,    52,    42,    41,    43,
      44,    53,    68,     1,    45,    69,    70,    71,    79,    80,
      86,    87,    46,    47,    90,    31,    94,    95,    16,   106,
      48,    49,    50,   100,    51,     2,   108,     3,   109,    52,
      46,    47,   110,   111,    53,   112,    46,    47,    48,    49,
      50,   118,    51,   117,   119,    49,    50,    52,    51,    88,
      12,   102,     0,    52,     0,   104,   103
};

static const yytype_int8 yycheck[] =
{
      46,    45,     0,    47,    57,    46,    52,     5,     0,    70,
       9,    52,    76,     9,    25,    20,    35,    15,    19,    38,
      25,    85,    23,    34,    20,    69,    30,    71,    30,    27,
      76,    92,    31,    77,    33,    31,    27,    33,    26,    85,
       0,    87,    88,    89,    90,     5,   110,    19,    30,    90,
      24,    23,    23,   106,     3,   108,     5,     6,    25,    26,
       9,    10,    21,   107,   110,   118,   119,    15,    16,    18,
      19,    26,    21,    22,    15,    16,    17,    26,    27,    28,
      27,    30,    31,    22,    33,    30,    35,     3,    24,     5,
       6,    40,    22,     9,    10,    19,    19,    19,    19,    30,
      26,    39,    18,    19,    36,    21,    26,    20,    23,    20,
      26,    27,    28,    30,    30,    31,    20,    33,    20,    35,
      18,    19,    25,    24,    40,    20,    18,    19,    26,    27,
      28,     4,    30,    26,    20,    27,    28,    35,    30,    35,
       5,    87,    -1,    35,    -1,    89,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    31,    33,    43,    44,    45,    46,    47,    54,
      55,     0,    45,    30,    56,    19,    23,    25,    26,    20,
      50,    55,    27,    30,    26,    49,    20,    25,    30,    24,
      23,    21,    51,    26,    48,    55,    27,    52,    53,    51,
      30,    24,     3,     5,     6,    10,    18,    19,    26,    27,
      28,    30,    35,    40,    51,    54,    55,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    22,    19,
      19,    19,    61,    60,    66,    61,    19,    23,    66,    19,
      30,    22,    58,    15,    16,    17,    26,    39,    35,    38,
      36,    61,    59,    61,    26,    20,    62,    68,    69,    61,
      30,    62,    63,    65,    64,    66,    20,    59,    20,    20,
      25,    24,    20,    58,    61,    58,    62,    26,     4,    20,
      58,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      48,    47,    49,    47,    50,    50,    50,    50,    52,    51,
      53,    51,    54,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
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
  case 2: /* start: program  */
#line 59 "1905056.y"
                {
	(yyval.symbol_info) = new SymbolInfo("program unit","");
	(yyval.symbol_info)->setTypeSpecifier("start : program");

	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));
	
	yOut<<"		inside				start:program		\n"<<endl;

	
	symbolTable->PrinrtAllScope(logOutput); 
	symbolTable->ExitScope();
	cout << "Total Lines: " << lineCount << endl;
	cout << "Total Errors: " << errorCount << endl;
	print_parse_tree((yyval.symbol_info),0);
	}
#line 1402 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 79 "1905056.y"
                       {
	(yyval.symbol_info) = new SymbolInfo("program unit","");
	(yyval.symbol_info)->setTypeSpecifier("program : program unit");

	(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));


	yOut<<"		inside      			program :   program unit		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1420 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 92 "1905056.y"
               {
		(yyval.symbol_info) = new SymbolInfo("unit","");
		(yyval.symbol_info)->setTypeSpecifier("program :  unit");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      			program : unit		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1436 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 105 "1905056.y"
                       {
		(yyval.symbol_info) = new SymbolInfo("var_declaration","");
		(yyval.symbol_info)->setTypeSpecifier("unit : var_declaration");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      		unit : var_declaration		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1452 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 116 "1905056.y"
                       {
		(yyval.symbol_info) = new SymbolInfo("func_declaration","");
		(yyval.symbol_info)->setTypeSpecifier("unit : func_declaration");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      		unit : 		func_declaration   "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1468 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 127 "1905056.y"
                      {
		(yyval.symbol_info) = new SymbolInfo("func_definition","");
		(yyval.symbol_info)->setTypeSpecifier("unit : func_definition");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      		unit : 		func_declaration   "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1484 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 140 "1905056.y"
                                                                            {

		(yyval.symbol_info) = new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",(yyvsp[-5].symbol_info)->getType());
		(yyval.symbol_info)->set_isfunction_declaration(true);
		(yyval.symbol_info)->setTypeSpecifier("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		(yyval.symbol_info)->set_parameter_list((yyvsp[-2].symbol_info)->get_parameter_list());
		bool in_inserted=symbolTable->InsertSymbol((yyvsp[-4].symbol_info)->getName(),(yyvsp[-5].symbol_info)->getType());
        	if(!in_inserted){
                yOut<<" Not Inserted in sumbolTable   due to multiple dec  "<<endl;
            }

		(yyval.symbol_info)->set_startLine((yyvsp[-5].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-5].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1512 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 163 "1905056.y"
                                                    {
		// type id ()
		(yyval.symbol_info) = new SymbolInfo("type_specifier ID LPAREN RPAREN SEMICOLON",(yyvsp[-4].symbol_info)->getType());
		(yyval.symbol_info)->set_isfunction_declaration(true);
		(yyval.symbol_info)->setTypeSpecifier("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		bool in_inserted=symbolTable->InsertSymbol((yyvsp[-3].symbol_info)->getName(),(yyvsp[-4].symbol_info)->getType());
        	if(!in_inserted){
                yOut<<" Not Inserted in sumbolTable   due to multiple dec  "<<endl;
            }
(yyval.symbol_info)->set_startLine((yyvsp[-4].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[-4].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));

		(yyval.symbol_info)->set_startLine((yyvsp[-4].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1542 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 190 "1905056.y"
                                                                 {
    defineFunction((yyvsp[-4].symbol_info),(yyvsp[-3].symbol_info),(yyvsp[-1].symbol_info) );
	fun_parameter_list=(yyvsp[-1].symbol_info)->get_parameter_list();
	}
#line 1551 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 195 "1905056.y"
        {
			cout<<"--================================================--------"<<endl;
		(yyval.symbol_info) = new SymbolInfo((yyvsp[-5].symbol_info)->getName(),(yyvsp[-6].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("func_definition : type_specifier ID LPAREN parameter_list RPAREN");

		(yyval.symbol_info)->set_startLine((yyvsp[-6].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-6].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-5].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN { } compound_statement		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1573 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 212 "1905056.y"
                                          {
		SymbolInfo *temp= new SymbolInfo("","");
		defineFunction((yyvsp[-3].symbol_info),(yyvsp[-2].symbol_info),temp);
		}
#line 1582 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 217 "1905056.y"
                {
		(yyval.symbol_info) = new SymbolInfo((yyvsp[-4].symbol_info)->getName(),(yyvsp[-5].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("func_definition : type_specifier ID LPAREN RPAREN");


		(yyval.symbol_info)->set_startLine((yyvsp[-5].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-5].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"insidw		func_definition : type_specifier ID LPAREN RPAREN { } compound_statement	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1603 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 235 "1905056.y"
                                                        { // void fun(int a, in b);
		(yyval.symbol_info) = new SymbolInfo("parameter_list COMMA type_specifier ID",(yyvsp[-3].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("parameter_list : parameter_list COMMA type_specifier ID");
		(yyval.symbol_info)->set_parameter_list((yyvsp[-3].symbol_info)->get_parameter_list());

		SymbolInfo *temp = new SymbolInfo((yyvsp[0].symbol_info)->getName(),(yyvsp[-1].symbol_info)->getType());
		temp->setTypeSpecifier("Parameter");
		(yyval.symbol_info)->push_into_parameter_list(temp);
		
		(yyval.symbol_info)->set_startLine((yyvsp[-3].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			parameter_list :parameter_list COMMA type_specifier  ID   "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1627 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 254 "1905056.y"
                                              { // void fun(int, float)
		(yyval.symbol_info) = new SymbolInfo("type_specifier ID",(yyvsp[-2].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("parameter_list : parameter_list COMMA type_specifier");
		(yyval.symbol_info)->set_parameter_list((yyvsp[-2].symbol_info)->get_parameter_list());
		SymbolInfo *temp = new SymbolInfo("",(yyvsp[0].symbol_info)->getType());
		temp->setTypeSpecifier("Parameter");
		(yyval.symbol_info)->push_into_parameter_list(temp);

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			parameter_list : parameter_list COMMA type_specifier     "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 1650 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 272 "1905056.y"
                            { // void fun(int a)

		(yyval.symbol_info) = new SymbolInfo("type_specifier ID",(yyvsp[-1].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("parameter_list");
		SymbolInfo *temp = new SymbolInfo((yyvsp[0].symbol_info)->getName(),(yyvsp[-1].symbol_info)->getType());
		temp->setTypeSpecifier("Parameter");
		(yyval.symbol_info)->push_into_parameter_list(temp);
		
		(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			parameter_list : type_specifier  ID   "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1671 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 288 "1905056.y"
                         {
		// void fun(int);
		(yyval.symbol_info) = new SymbolInfo((yyvsp[0].symbol_info)->getType(),"");
		(yyval.symbol_info)->setTypeSpecifier("parameter_list");
		SymbolInfo *temp = new SymbolInfo("",(yyvsp[0].symbol_info)->getType());
		temp->setTypeSpecifier("Parameter");
		(yyval.symbol_info)->push_into_parameter_list(temp);


		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			parameter_list : type_specifier     "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1692 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 306 "1905056.y"
                           {
	symbolTable->EnterScope();
	declare_fun_variables();
	yOut<<"					into compound statemnent		"<<endl;
	}
#line 1702 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@3 statements RCURL  */
#line 312 "1905056.y"
        {

		symbolTable->PrinrtCurrentScope(logOutput);
		symbolTable->ExitScope();

		(yyval.symbol_info) = new SymbolInfo("LCURL","");
		(yyval.symbol_info)->setTypeSpecifier("compound_statement : LCURL statements RCURL");

		(yyval.symbol_info)->set_startLine((yyvsp[-3].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			compound_statement : LCURL statements RCURL "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 1725 "y.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 330 "1905056.y"
                {
		symbolTable->EnterScope(); 
		}
#line 1733 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL $@4 RCURL  */
#line 334 "1905056.y"
                {
		symbolTable->PrinrtCurrentScope(logOutput);
		symbolTable->ExitScope();

		(yyval.symbol_info) = new SymbolInfo("LCURL","");
		(yyval.symbol_info)->setTypeSpecifier("compound_statement : LCURL RCURL");

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));
		yOut<<"inside			compound_statement : LCURL RCURL "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 1753 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 351 "1905056.y"
                                                            {

            (yyval.symbol_info) = new SymbolInfo((yyvsp[-1].symbol_info)->getName(),(yyvsp[-2].symbol_info)->getType());
			(yyval.symbol_info)->setTypeSpecifier("var_declaration : type_specifier declaration_list SEMICOLON");
            if((yyvsp[-2].symbol_info)->getType() == "void"){
				logOutput<<"Variable type cannot be void";
			}
			vector<SymbolInfo*> temp_parameter_list=(yyvsp[-1].symbol_info)->get_declaration_list();
            for(int i=0;i<temp_parameter_list.size();i++){
                bool in_inserted=symbolTable->InsertSymbol(temp_parameter_list[i]->getName(),(yyvsp[-2].symbol_info)->getType());
                if(!in_inserted){
                    yOut<<" Not Inserted in sumbolTable due to multiple declaration    "<<endl;
                }
            }


		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		 inside      var_declaration : type_specifier declaration_list SEMICOLON      "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1783 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 378 "1905056.y"
                      {
		(yyval.symbol_info) = new SymbolInfo("INT", "int");
		(yyval.symbol_info)->setTypeSpecifier("type_specifier	: INT");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside type_spec: INT       got<<<<<<INT "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
		}
#line 1799 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 389 "1905056.y"
                {

        (yyval.symbol_info) = new SymbolInfo("FLOAT", "float");
		(yyval.symbol_info)->setTypeSpecifier("type_specifier");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside type_spec: fkoat          got<<<<<<<<<<<<float "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1816 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 401 "1905056.y"
               {
        (yyval.symbol_info) = new SymbolInfo("VOID", "void");
		(yyval.symbol_info)->setTypeSpecifier("type_specifier");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside type_spec: void          got<<<<<<<<<void    "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1832 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 414 "1905056.y"
                                             {
		(yyval.symbol_info) = new SymbolInfo("declaration_list COMMA ID","");
		(yyval.symbol_info)->setTypeSpecifier("declaration_list : declaration_list COMMA ID");

		(yyval.symbol_info)->set_declaration_list((yyvsp[-2].symbol_info)->get_declaration_list());
		(yyval.symbol_info)->push_into_decList((yyvsp[0].symbol_info));

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

        yOut<<"		inside      declaarationlist: decl comma id    "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1853 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 430 "1905056.y"
                                                            {
		(yyval.symbol_info) = new SymbolInfo("declaration_list COMMA ID LTHIRD CONST_INT RTHIRD","");
		(yyval.symbol_info)->setTypeSpecifier("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		(yyval.symbol_info)->set_declaration_list((yyvsp[-5].symbol_info)->get_declaration_list());

		(yyvsp[-3].symbol_info)->set_isarray(true);
		string str=(yyvsp[-1].symbol_info)->getName();
		int x = stoi(str);
		(yyvsp[-3].symbol_info)->set_size(x);
		(yyval.symbol_info)->push_into_decList((yyvsp[-3].symbol_info));

		(yyval.symbol_info)->set_startLine((yyvsp[-5].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-5].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      declist: ID LTHIRD CONST_INT RTHIRD    "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1881 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 453 "1905056.y"
             {
		// create list for the first symbol
			(yyval.symbol_info) = new SymbolInfo("ID","");
			(yyval.symbol_info)->setTypeSpecifier("declaration_list: ID");
			(yyval.symbol_info)->push_into_decList((yyvsp[0].symbol_info));


			(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
			(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
			(yyval.symbol_info)->set_isLeaf(false);
			(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

			yOut<<"		inside      declist: ID    "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1900 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 469 "1905056.y"
                                     {
		(yyval.symbol_info) = new SymbolInfo("ID LTHIRD CONST_INT RTHIRD","");
		(yyval.symbol_info)->setTypeSpecifier("declaration_list: ID LTHIRD CONST_INT RTHIRD");

		(yyvsp[-3].symbol_info)->set_isarray(true);
		string str=(yyvsp[-1].symbol_info)->getName();
		int x = stoi(str);
		(yyvsp[-3].symbol_info)->set_size(x);
		(yyval.symbol_info)->push_into_decList((yyvsp[-3].symbol_info));

		(yyval.symbol_info)->set_startLine((yyvsp[-3].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      declist: ID LTHIRD CONST_INT RTHIRD    "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1925 "y.tab.c"
    break;

  case 30: /* statements: statement  */
#line 491 "1905056.y"
                       {
		(yyval.symbol_info) = new SymbolInfo("statement",(yyvsp[0].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("statements : statement");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      statements : statement    "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1941 "y.tab.c"
    break;

  case 31: /* statements: statements statement  */
#line 502 "1905056.y"
                               {
		(yyval.symbol_info) = new SymbolInfo("statement",(yyvsp[-1].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("statements : statements statement");

		(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"		inside      statements : statements statement     "<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1958 "y.tab.c"
    break;

  case 32: /* statement: var_declaration  */
#line 516 "1905056.y"
                            {
		(yyval.symbol_info) = new SymbolInfo("var_declaration",(yyvsp[0].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("statement : var_declaration");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: var_declaration  		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1974 "y.tab.c"
    break;

  case 33: /* statement: expression_statement  */
#line 527 "1905056.y"
                               {
		(yyval.symbol_info) = new SymbolInfo("expression_statement",(yyvsp[0].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("statement : expression_statement");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: expression_statement  		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 1990 "y.tab.c"
    break;

  case 34: /* statement: compound_statement  */
#line 538 "1905056.y"
                             {
		(yyval.symbol_info) = new SymbolInfo("compound_statement",(yyvsp[0].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("statement : compound_statement");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: compound_statement   		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2006 "y.tab.c"
    break;

  case 35: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 549 "1905056.y"
                                                                                           {
		(yyval.symbol_info) = new SymbolInfo("FOR LPAREN expression_statement expression_statement expression RPAREN statement",(yyvsp[-6].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");

		(yyval.symbol_info)->set_startLine((yyvsp[-6].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-6].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-5].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement    		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2028 "y.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement  */
#line 566 "1905056.y"
                                                                      {
		(yyval.symbol_info) = new SymbolInfo("IF LPAREN expression RPAREN statement","int");
		(yyval.symbol_info)->setTypeSpecifier("statement: IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE");

		(yyval.symbol_info)->set_startLine((yyvsp[-4].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: IF LPAREN expression RPAREN statement    		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2048 "y.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 581 "1905056.y"
                                                               {
		(yyval.symbol_info) = new SymbolInfo("IF LPAREN expression RPAREN statement ELSE statement","int");
		(yyval.symbol_info)->setTypeSpecifier("statement : IF LPAREN expression RPAREN statement ELSE statement");

		(yyval.symbol_info)->set_startLine((yyvsp[-6].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-6].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-5].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: IF LPAREN expression RPAREN statement ELSE statement    		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2070 "y.tab.c"
    break;

  case 38: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 598 "1905056.y"
                                                   {
		(yyval.symbol_info) = new SymbolInfo("WHILE LPAREN expression RPAREN statement","int");
		(yyval.symbol_info)->setTypeSpecifier("statement : WHILE LPAREN expression RPAREN statement");

		(yyval.symbol_info)->set_startLine((yyvsp[-4].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));


		yOut<<"inside			statement: WHILE LPAREN expression RPAREN statement		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2091 "y.tab.c"
    break;

  case 39: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 614 "1905056.y"
                                             {
		if(symbolTable->LookUpSymbol((yyvsp[-2].symbol_info)->getName())==NULL){
			errorOutput<<" Undeclared value print attempt"<<endl;
		}
		(yyval.symbol_info) = new SymbolInfo("PRINTLN LPAREN ID RPAREN SEMICOLON","int");
		(yyval.symbol_info)->setTypeSpecifier("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

		(yyval.symbol_info)->set_startLine((yyvsp[-4].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-4].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: PRINTLN LPAREN ID RPAREN SEMICOLON    		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2114 "y.tab.c"
    break;

  case 40: /* statement: RETURN expression SEMICOLON  */
#line 632 "1905056.y"
                                      {
		(yyval.symbol_info) = new SymbolInfo("RETURN expression SEMICOLON",(yyvsp[-1].symbol_info)->getTypeSpecifier());
		(yyval.symbol_info)->setTypeSpecifier("statement : RETURN expression SEMICOLON");

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			statement: RETURN expression SEMICOLON    		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2132 "y.tab.c"
    break;

  case 41: /* expression_statement: SEMICOLON  */
#line 647 "1905056.y"
                                 {
		(yyval.symbol_info) = new SymbolInfo("SEMICOLON","void");
		(yyval.symbol_info)->setTypeSpecifier("expression_statement : SEMICOLON");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			expression_statement : SEMICOLON    		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 2149 "y.tab.c"
    break;

  case 42: /* expression_statement: expression SEMICOLON  */
#line 659 "1905056.y"
                               {
		(yyval.symbol_info) = new SymbolInfo("expression SEMICOLON",(yyvsp[-1].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("expression_statement : expression SEMICOLON");

		if(voidCheck((yyvsp[-1].symbol_info)) ){
		errorOutput<<"Void function used in expression_statement"<<endl;
		}
		else if(errortype_Check((yyvsp[-1].symbol_info)) ){
		errorOutput<<"error  function used in expression_statement"<<endl;
		}

		(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			expression_statement : expression SEMICOLON   		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2173 "y.tab.c"
    break;

  case 43: /* variable: ID  */
#line 681 "1905056.y"
              { 
	(yyval.symbol_info) = new SymbolInfo((yyvsp[0].symbol_info)->getName(),"");
	(yyval.symbol_info)->setTypeSpecifier("variable");
	SymbolInfo *temp = symbolTable->LookUpSymbol((yyvsp[0].symbol_info)->getName());
	if(temp==NULL){
		yOut<<" variable not NOT Declared"<<endl;
	}
	else{
		if(temp->is_array()){
				errorOutput<<"Type mismatch, "<<temp->getName()<<" is an array"<<endl;
			}
		else{
			(yyval.symbol_info)->set_isarray(false);
		}
	}
    yOut<<"inside			variable: ID   		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2195 "y.tab.c"
    break;

  case 44: /* variable: ID LTHIRD expression RTHIRD  */
#line 698 "1905056.y"
                                      {
		(yyval.symbol_info) = new SymbolInfo((yyvsp[-3].symbol_info)->getName(),"");
		(yyval.symbol_info)->setTypeSpecifier("variable");
		SymbolInfo *temp = symbolTable->LookUpSymbol((yyvsp[-3].symbol_info)->getName());
		if(temp==NULL){
			yOut<<" variable not NOT Declared"<<endl;
		}
		else{
			if(temp->is_array()){
				if((yyvsp[-1].symbol_info)->getType()=="int"){
				(yyval.symbol_info)->set_isarray(true);
				}
			else{
				errorOutput<<"Type mismatch, "<<temp->getName()<<" is not an array"<<endl;
			}
			}
		}

		(yyval.symbol_info)->set_startLine((yyvsp[-3].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[-3].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));

	yOut<<"inside			variable: ID LTHIRD expression RTHIRD  		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2225 "y.tab.c"
    break;

  case 45: /* expression: logic_expression  */
#line 725 "1905056.y"
                              {
	(yyval.symbol_info) = new SymbolInfo("logic_expression", "int");
	(yyval.symbol_info)->setTypeSpecifier("expression : logic_expression");

	if(voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}



	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

	yOut<<"inside			expression : logic_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2250 "y.tab.c"
    break;

  case 46: /* expression: variable ASSIGNOP logic_expression  */
#line 746 "1905056.y"
                                             {
		SymbolInfo *temp=symbolTable->LookUpSymbol((yyvsp[-2].symbol_info)->getName());
		(yyval.symbol_info) = new SymbolInfo("variable ASSIGNOP logic_expression", "");
		(yyval.symbol_info)->setTypeSpecifier("expression : variable ASSIGNOP logic_expression");
		if(temp==NULL){
			errorOutput<<" variable not declared"<<endl;
			(yyval.symbol_info)->setType("error");
		}
		else{
			(yyval.symbol_info)->setType(temp->getType());
			if(temp->getType()!=(yyvsp[0].symbol_info)->getType()){
				errorOutput<<"assignment operation type mis match"<<endl;//---------------------------------
				(yyval.symbol_info)->setType("error");

			}
		}


		if(voidCheck((yyvsp[-2].symbol_info)) || voidCheck(yyvsp[0].symbol_info) ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[-2].symbol_info)) || voidCheck(yyvsp[0].symbol_info) ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			expression : variable ASSIGNOP logic_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2289 "y.tab.c"
    break;

  case 47: /* logic_expression: rel_expression  */
#line 782 "1905056.y"
                                  { 
	(yyval.symbol_info) = new SymbolInfo("rel_expression", "int");
	(yyval.symbol_info)->setTypeSpecifier("logic_expression : rel_expression");

	if(voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}

	

	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

	yOut<<"inside			logic_expression : rel_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2314 "y.tab.c"
    break;

  case 48: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 802 "1905056.y"
                                                {
		(yyval.symbol_info) = new SymbolInfo("rel_expression LOGICOP rel_expression", "int");
		(yyval.symbol_info)->setTypeSpecifier("logic_expression : rel_expression LOGICOP rel_expression");

		if(voidCheck((yyvsp[-2].symbol_info)) || voidCheck(yyvsp[0].symbol_info) ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[-2].symbol_info)) || voidCheck(yyvsp[0].symbol_info) ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}



		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			logic_expression : rel_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2341 "y.tab.c"
    break;

  case 49: /* rel_expression: simple_expression  */
#line 826 "1905056.y"
                                   {
	(yyval.symbol_info) = new SymbolInfo("simple_expression", "int");
	(yyval.symbol_info)->setTypeSpecifier("rel_expression : simple_expression");

	if(voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in rel_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in rel_expression"<<endl;
		}

	

	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

	yOut<<"inside			rel_expression : simple_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2366 "y.tab.c"
    break;

  case 50: /* rel_expression: simple_expression RELOP simple_expression  */
#line 846 "1905056.y"
                                                        {
		(yyval.symbol_info) = new SymbolInfo("simple_expression RELOP simple_expression", "int");
		(yyval.symbol_info)->setTypeSpecifier("rel_expression : simple_expression RELOP simple_expression");

		if(voidCheck((yyvsp[-2].symbol_info)) || voidCheck(yyvsp[0].symbol_info) ){
		errorOutput<<"Void function used in rel_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[-2].symbol_info)) || voidCheck(yyvsp[0].symbol_info) ){
		errorOutput<<"error  function used in rel_expression"<<endl;
		}


		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"indside			rel_expression : simple_expression RELOP simple_expressio		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2392 "y.tab.c"
    break;

  case 51: /* simple_expression: term  */
#line 869 "1905056.y"
                         {
	(yyval.symbol_info) = new SymbolInfo("term", (yyvsp[0].symbol_info)->getType());
	(yyval.symbol_info)->setTypeSpecifier("simple_expression : term");

	if(voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in simple_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in simple_expression"<<endl;
		}

	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));
	
	yOut<<"inside			simple_expression : term		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2415 "y.tab.c"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 887 "1905056.y"
                                       {
	(yyval.symbol_info) = new SymbolInfo("simple_expression ADDOP term", (yyvsp[-2].symbol_info)->getType());
	(yyval.symbol_info)->setTypeSpecifier("simple_expression : simple_expression ADDOP term");
	if(voidCheck((yyvsp[-2].symbol_info)) ||  voidCheck((yyvsp[0].symbol_info))){
		errorOutput<<"Void function used in simple_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[-2].symbol_info)) || voidCheck((yyvsp[0].symbol_info))){
		errorOutput<<"error  function used in simple_expression"<<endl;
		}

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

	yOut<<"inside			simple_expression : simple_expression ADDOP term		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2439 "y.tab.c"
    break;

  case 53: /* term: unary_expression  */
#line 908 "1905056.y"
                         {
	(yyval.symbol_info) = new SymbolInfo("unary_expression", (yyvsp[0].symbol_info)->getType());

	if(voidCheck((yyvsp[0].symbol_info))){
		errorOutput<<"Void function used in term"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in term"<<endl;
		}(yyval.symbol_info)->setTypeSpecifier("term : unary_expression");



	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

	yOut<<"inside			term :	unary_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 2464 "y.tab.c"
    break;

  case 54: /* term: term MULOP unary_expression  */
#line 928 "1905056.y"
                                   {
		(yyval.symbol_info) = new SymbolInfo("term MULOP unary_expression", (yyvsp[-2].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("term : term MULOP unary_expression");


		if(( ((yyvsp[-2].symbol_info)->getType() != "int") || ((yyvsp[0].symbol_info)->getType() != "int") ) && ((yyvsp[-1].symbol_info)->getType()=="%")){
		errorOutput<<"Non-Integer operand on modulus operator"<<endl;
		}
		else if(voidCheck((yyvsp[-2].symbol_info)) || voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in term"<<endl;
		}
		else if(errortype_Check((yyvsp[-2].symbol_info)) || errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in term"<<endl;
		}

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			term :	term MULOP unary_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2493 "y.tab.c"
    break;

  case 55: /* unary_expression: ADDOP unary_expression  */
#line 954 "1905056.y"
                                          {

	(yyval.symbol_info) = new SymbolInfo("ADDOP unary_expression", (yyvsp[0].symbol_info)->getType());
	(yyval.symbol_info)->setTypeSpecifier("unary_expression : ADDOP unary_expression");

	if(voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in unary_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in unary_expression"<<endl;
		}

	(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

	

	yOut<<"inside			unary_expression : ADDOP unary_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2520 "y.tab.c"
    break;

  case 56: /* unary_expression: NOT unary_expression  */
#line 976 "1905056.y"
                               {
	(yyval.symbol_info) = new SymbolInfo("NOT unary_expression",(yyvsp[0].symbol_info)->getType());

	if(voidCheck((yyvsp[0].symbol_info)) ){
		errorOutput<<"Void function used in unary_expression"<<endl;
		}
		else if(errortype_Check((yyvsp[0].symbol_info)) ){
		errorOutput<<"error  function used in unary_expression"<<endl;
		}(yyval.symbol_info)->setTypeSpecifier("unary_expression : NOT unary_expression");



	(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));


	yOut<<"inside			unary_expression : NOT unary_expression		"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2546 "y.tab.c"
    break;

  case 57: /* unary_expression: factor  */
#line 997 "1905056.y"
                 {
	(yyval.symbol_info) = new SymbolInfo("factor", (yyvsp[0].symbol_info)->getType());
	(yyval.symbol_info)->setTypeSpecifier("unary_expression : factor");
	(yyval.symbol_info)->setType((yyvsp[0].symbol_info)->getType());

	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));
	yOut<<"inside			unary_expression : factor	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2562 "y.tab.c"
    break;

  case 58: /* factor: variable  */
#line 1011 "1905056.y"
                   {
	SymbolInfo *temp=symbolTable->LookUpSymbol((yyvsp[0].symbol_info)->getName());
	(yyval.symbol_info) = new SymbolInfo("variable","");
	if(temp==NULL){
		(yyval.symbol_info)->setType("error");
	}
	else{
		(yyval.symbol_info)->setType(temp->getType());
	}
	(yyval.symbol_info)->setTypeSpecifier("factor	: variable");

	(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));
	yOut<<"inside			factor variable	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2584 "y.tab.c"
    break;

  case 59: /* factor: ID LPAREN argument_list RPAREN  */
#line 1028 "1905056.y"
                                         {
		SymbolInfo *temp=symbolTable->LookUpSymbol((yyvsp[-3].symbol_info)->getName());
		(yyval.symbol_info) = new SymbolInfo("variable","");
		if(temp==NULL){
			errorOutput<<" function not specified"<<endl;
			(yyval.symbol_info)->setType("error");
		}
		else{
			(yyval.symbol_info)->setType(temp->getType());
		}
		string s=callFunction((yyvsp[-3].symbol_info),(yyvsp[-1].symbol_info));
		(yyval.symbol_info)->setTypeSpecifier("factor : ID LPAREN argument_list RPAREN");

		callFunction((yyvsp[-3].symbol_info),(yyvsp[-1].symbol_info));

		(yyval.symbol_info)->set_startLine((yyvsp[-3].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-3].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			factor: ID LPAREN argument_list RPAREN	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2614 "y.tab.c"
    break;

  case 60: /* factor: LPAREN expression RPAREN  */
#line 1053 "1905056.y"
                                   {
		(yyval.symbol_info) = new SymbolInfo(" LPAREN expression RPAREN",(yyvsp[-1].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("factor : LPAREN expression RPAREN ");

		(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			factor: LPAREN expression RPAREN	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 2633 "y.tab.c"
    break;

  case 61: /* factor: CONST_INT  */
#line 1067 "1905056.y"
                    { 
		(yyval.symbol_info) = new SymbolInfo("CONST_INT","int");
		(yyval.symbol_info)->setTypeSpecifier("factor : CONST_INT");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			factor: CONST_INT	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2649 "y.tab.c"
    break;

  case 62: /* factor: CONST_FLOAT  */
#line 1078 "1905056.y"
                      { 
		(yyval.symbol_info) = new SymbolInfo("CONST_FLOAT","float");
		(yyval.symbol_info)->setTypeSpecifier("factor : CONST_FLOAT");

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			factor: CONST_FLOAT	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2665 "y.tab.c"
    break;

  case 63: /* factor: variable INCOP  */
#line 1089 "1905056.y"
                         {
		SymbolInfo *temp=symbolTable->LookUpSymbol((yyvsp[-1].symbol_info)->getName());
		(yyval.symbol_info) = new SymbolInfo("variable INCOP","");
		(yyval.symbol_info)->setTypeSpecifier("factor : variable INCOP");
		if(temp==NULL){
			(yyval.symbol_info)->setType("error");
			errorOutput<<" error @ variable incop in factor"<<endl;
		}
		else{
			(yyval.symbol_info)->setType(temp->getType());
		}

		(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			factor: variable INCOP	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2690 "y.tab.c"
    break;

  case 64: /* factor: variable DECOP  */
#line 1109 "1905056.y"
                         {
		SymbolInfo *temp=symbolTable->LookUpSymbol((yyvsp[-1].symbol_info)->getName());
		(yyval.symbol_info) = new SymbolInfo("variable DECOP","");
		if(temp==NULL){
			(yyval.symbol_info)->setType("error");
			errorOutput<<" error @ variable deccop in factor"<<endl;
		}
		else{
			(yyval.symbol_info)->setType(temp->getType());
		}
		(yyval.symbol_info)->setTypeSpecifier("factor : variable DECOP");

		(yyval.symbol_info)->set_startLine((yyvsp[-1].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			factor: variable DECOP	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2715 "y.tab.c"
    break;

  case 65: /* argument_list: arguments  */
#line 1132 "1905056.y"
                          {
		(yyval.symbol_info) = new SymbolInfo("arguments","");
		(yyval.symbol_info)->setTypeSpecifier("argument_list");
		(yyval.symbol_info)->set_parameter_list((yyvsp[0].symbol_info)->get_parameter_list());

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			argument_list : arguments	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;

	}
#line 2733 "y.tab.c"
    break;

  case 66: /* argument_list: %empty  */
#line 1146 "1905056.y"
        {
		(yyval.symbol_info) = new SymbolInfo("","");
		(yyval.symbol_info)->setTypeSpecifier("argument_list");
		yOut<<"inside			argument_list : empty	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2743 "y.tab.c"
    break;

  case 67: /* arguments: arguments COMMA logic_expression  */
#line 1154 "1905056.y"
                                             {

	(yyval.symbol_info) = new SymbolInfo("arguments","");
	(yyval.symbol_info)->set_parameter_list((yyvsp[-2].symbol_info)->get_parameter_list());
	(yyval.symbol_info)->push_into_parameter_list((yyvsp[0].symbol_info));

	(yyval.symbol_info)->set_startLine((yyvsp[-2].symbol_info)->get_startLine());
	(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
	(yyval.symbol_info)->set_isLeaf(false);
	(yyval.symbol_info)->push_into_childList((yyvsp[-2].symbol_info));
	(yyval.symbol_info)->push_into_childList((yyvsp[-1].symbol_info));
	(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));
		
	yOut<<"inside			arguments : arguments COMMA logic_expression	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2763 "y.tab.c"
    break;

  case 68: /* arguments: logic_expression  */
#line 1169 "1905056.y"
                           {
		(yyval.symbol_info) = new SymbolInfo("logic_expression",(yyvsp[0].symbol_info)->getType());
		(yyval.symbol_info)->setTypeSpecifier("arguments");
		(yyval.symbol_info)->push_into_parameter_list((yyvsp[0].symbol_info));

		(yyval.symbol_info)->set_startLine((yyvsp[0].symbol_info)->get_startLine());
		(yyval.symbol_info)->set_endLine((yyvsp[0].symbol_info)->get_endLine());
		(yyval.symbol_info)->set_isLeaf(false);
		(yyval.symbol_info)->push_into_childList((yyvsp[0].symbol_info));

		yOut<<"inside			arguments : logic_expression	"<<lineCount<<"		"<<(yyval.symbol_info)->getName()<<"		"<<(yyval.symbol_info)->getTypeSpecifier()<<endl;
	}
#line 2780 "y.tab.c"
    break;


#line 2784 "y.tab.c"

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

#line 1182 "1905056.y"

void yyerror(char *s){

	cout<<"Error at line "<<lineCount<<": "<<s<<"\n"<<endl;
	errorCount++;

}
void defineFunction(SymbolInfo *returnType,SymbolInfo *name,SymbolInfo *parameter ){

		cout<<"just came into define function------------------------2222222222222222222222222222222222222222"<<endl;		
		name->setType(returnType->getType());
		name->set_parameter_list(parameter->get_parameter_list());
		SymbolInfo *temp=symbolTable->LookUpSymbol(name->getName());
		vector<SymbolInfo*> vec2=name->get_parameter_list();

		cout<<"--------------------------------before  if    in define fun"<<endl;
		if(temp==NULL){
			symbolTable->InsertSymbol(name);
			for(int i=0;i<vec2.size();i++){
				cout<<vec2[i]->getName()<<"		"<<vec2[i]->getType()<<"		"<<vec2[i]->getTypeSpecifier()<<endl;;
			}
			return;
		}
		cout<<"--------------------111111111111111111111111111111111111111"<<endl;
		vector<SymbolInfo*> vec1=temp->get_parameter_list();
		cout<<"000000000000000000000000000000000000000000000000000"<<endl;
		if(temp->is_function_defination()){
			errorOutput<<"Multiple declaration of same function"<<endl;
			return;
		}
		else if(temp->getType()!=returnType->getType()){
			errorOutput<<"return type mis match with pre defination"<<endl;
			return;

		}
		else if(vec1.size()!=vec2.size()){
			errorOutput<<"parameter num mis match"<<endl;
			return;

		}else{
			
			for(int i=0;i<vec2.size();i++){
				if(vec1[i]->getType()!=vec2[i]->getType()){
					errorOutput<<"individual parameter type mis match"<<endl;
				}
			}
		}
		cout<<"11111111111111111111111111111111111111111111111"<<endl;
	yOut<<" function defined "<<endl;


}

string callFunction(SymbolInfo* id,SymbolInfo* parameter){


	cout<<"okkkkkkkkkkkkkkkkkkkkk"<<endl;
	
	

}
void declare_fun_variables(){
	vector<SymbolInfo*> vec=fun_parameter_list;
	for(int i=0;i<vec.size();i++){
		symbolTable->InsertSymbol(vec[i]->getName(),vec[i]->getType());
	}
	fun_parameter_list.clear();
}
void print_parse_tree(SymbolInfo *root,int height){
	for(int i=0;i<height;i++){
		parse_tree_output<<" ";
	}
	if(root->get_isLeaf()){
	parse_tree_output<<root->getTypeSpecifier()<<root->getName()<<"		<Line: "<<root->get_startLine()<<">"<<endl;//"					"<<root->getName()<<"		"<<root->getType()<<endl;
	return;
	}
	vector<SymbolInfo*> vec=root->get_child_list();
	parse_tree_output<<root->getTypeSpecifier()<<"		<Line: "<<root->get_startLine()<<"-"<<root->get_endLine()<<">"<<endl;//					"<<root->getName()<<"		"<<root->getType()<<endl;
	for(int i=0;i<vec.size();i++){
		print_parse_tree(vec[i],height+1);
	}
}
bool voidCheck( SymbolInfo *s){
	if(s->getType()=="void"){
	return true;
	}
	return false;
}
bool errortype_Check( SymbolInfo *s){
	if(s->getType()=="error"){
	return true;
	}
	return false;
}
int main(int argc,char *argv[])
{
	if(argc != 2){
        cout<<"not enough file inputed"<<endl;
        return 0;
    }
    FILE *fin = freopen(argv[1], "r", stdin);
    if(fin == nullptr){
        cout<<"Cannt open file"<<endl;
        return 0;
    }	
    errorOutput.open("error.txt");
    logOutput.open("log.txt");
    lexOut.open("lex.txt");
    yOut.open("y.txt");
	parse_tree_output.open("parse_tree.txt");
	yyin = fin;

    // start scanning the file here
	yyparse();



    // symbolTable->printAllScope(logOutput);

	logOutput<<"Total lines: "<<lineCount<<endl;
    logOutput<<"Total errors: "<<errorCount<<endl;

    fclose(yyin);
    errorOutput.close();
    logOutput.close();
	printf(" parse kora shesh");
	return 0;
}

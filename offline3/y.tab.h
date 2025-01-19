/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

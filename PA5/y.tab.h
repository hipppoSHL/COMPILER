/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    CHAR = 259,
    REAL = 260,
    ID = 261,
    STRING = 262,
    OPERATOR = 263,
    BREAK = 264,
    CASE = 265,
    CHAR_K = 266,
    DEFAULT = 267,
    ELSE = 268,
    FLOAT = 269,
    FOR = 270,
    IF = 271,
    RETURN = 272,
    SWITCH = 273,
    VOID = 274,
    WHILE = 275,
    INT = 276,
    DOUBLE = 277,
    ASGN = 278,
    ADD_ASGN = 279,
    SUB_ASGN = 280,
    MUL_ASGN = 281,
    DIV_ASGN = 282,
    MOD_ASGN = 283,
    EQ_CMP = 284,
    EQ_NOT = 285,
    EQ_LES = 286,
    EQ_BIG = 287,
    LSHIFT = 288,
    RSHIFT = 289,
    AND = 290,
    OR = 291,
    INCREMENT = 292,
    DECREMENT = 293,
    ADD = 294,
    SUB = 295,
    MUL = 296,
    DIV = 297,
    MOD = 298,
    LESS = 299,
    BIGG = 300
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define CHAR 259
#define REAL 260
#define ID 261
#define STRING 262
#define OPERATOR 263
#define BREAK 264
#define CASE 265
#define CHAR_K 266
#define DEFAULT 267
#define ELSE 268
#define FLOAT 269
#define FOR 270
#define IF 271
#define RETURN 272
#define SWITCH 273
#define VOID 274
#define WHILE 275
#define INT 276
#define DOUBLE 277
#define ASGN 278
#define ADD_ASGN 279
#define SUB_ASGN 280
#define MUL_ASGN 281
#define DIV_ASGN 282
#define MOD_ASGN 283
#define EQ_CMP 284
#define EQ_NOT 285
#define EQ_LES 286
#define EQ_BIG 287
#define LSHIFT 288
#define RSHIFT 289
#define AND 290
#define OR 291
#define INCREMENT 292
#define DECREMENT 293
#define ADD 294
#define SUB 295
#define MUL 296
#define DIV 297
#define MOD 298
#define LESS 299
#define BIGG 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "bar.y" /* yacc.c:1909  */

	int iVal;
	float rVal;
	char* sVal;

#line 150 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

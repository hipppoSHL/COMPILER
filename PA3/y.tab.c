/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
STACK *stack;
int yylex(void);
int yyerror(char*);
void dfs(ASTNode *node);
int check;
int isSyntaxError;

#line 78 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 13 "bar.y" /* yacc.c:355  */

	int iVal;
	float rVal;
	char* sVal;

#line 214 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    25,    25,    31,    36,    38,    39,    42,    50,    59,
      64,    68,    73,    75,    80,    82,    89,    96,   106,   108,
     115,   116,   117,   118,   120,   125,   127,   133,   137,   147,
     149,   150,   152,   153,   154,   155,   156,   157,   158,   159,
     167,   173,   181,   189,   195,   202,   207,   209,   213,   217,
     221,   222,   224,   225,   227,   233,   239,   245,   251,   257,
     264,   270,   272,   277,   279,   284,   286,   291,   296,   301,
     306,   311,   316,   318,   323,   328,   330,   335,   340,   345,
     347,   348,   349,   354,   355,   360,   365,   367,   368,   370,
     371,   373,   379,   385,   394,   402,   409,   413,   415,   420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "CHAR", "REAL", "ID",
  "STRING", "OPERATOR", "BREAK", "CASE", "CHAR_K", "DEFAULT", "ELSE",
  "FLOAT", "FOR", "IF", "RETURN", "SWITCH", "VOID", "WHILE", "INT",
  "DOUBLE", "ASGN", "ADD_ASGN", "SUB_ASGN", "MUL_ASGN", "DIV_ASGN",
  "MOD_ASGN", "EQ_CMP", "EQ_NOT", "EQ_LES", "EQ_BIG", "LSHIFT", "RSHIFT",
  "AND", "OR", "INCREMENT", "DECREMENT", "ADD", "SUB", "MUL", "DIV", "MOD",
  "LESS", "BIGG", "'('", "')'", "';'", "','", "'{'", "'}'", "'['", "']'",
  "':'", "$accept", "Program", "DeclarationList", "Declaration",
  "FuncDeclaration", "FuncID", "Params", "ParamList", "Param",
  "CompoundStmt", "LocalDeclarationList", "VarDeclaration",
  "TypeSpecifier", "IDs", "Value", "StmtList", "Stmt", "MatchedStmt",
  "OpenStmt", "SwitchStmt", "CaseList", "DefaultCase", "ReturnStmt",
  "BreakStmt", "ExprStmt", "Expr", "AssignExpr", "Variable", "SimpleExpr",
  "AndExpr", "RelExpr", "AddExpr", "Term", "Factor", "NumberLiteral",
  "IncDec", "WhileStmt", "ForStmt", "FunctionCall", "Arguments",
  "ArgumentList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    40,    41,    59,    44,
     123,   125,    91,    93,    58
};
# endif

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,  -143,  -143,  -143,  -143,     6,     7,  -143,  -143,  -143,
      28,  -143,  -143,   -33,   -29,   -19,  -143,    35,    58,  -143,
      36,    14,    67,    41,    42,  -143,    36,    43,  -143,  -143,
      48,     7,  -143,  -143,  -143,  -143,  -143,     7,  -143,    36,
      65,  -143,  -143,   -32,    60,    80,    82,    38,   101,   103,
    -143,  -143,    87,    87,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,   100,  -143,   118,   117,   115,   -20,
      61,    97,  -143,  -143,   151,  -143,  -143,  -143,    87,    87,
    -143,    87,    87,  -143,   110,    87,    87,    84,  -143,   112,
    -143,    87,    87,    87,    87,    87,    87,  -143,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,   109,  -143,  -143,   116,   123,   120,   126,   128,  -143,
     129,   130,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   115,
     -20,    61,    61,    61,    61,    61,    61,    97,    97,  -143,
    -143,  -143,  -143,    87,  -143,    87,   114,   131,    56,  -143,
     132,  -143,   152,   168,  -143,  -143,    87,   114,   176,   102,
     135,  -143,  -143,   133,   180,   134,   138,    59,  -143,   136,
    -143,  -143,  -143,  -143,   114,  -143,   114,   114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    21,    20,     0,     2,     4,     6,     5,
       0,     1,     3,    27,     0,     0,    25,     0,    12,    19,
       0,     0,    11,     0,    10,    14,     0,    27,    24,    26,
       0,     0,    15,     8,    18,     7,    13,    29,    17,     0,
       0,    87,    88,    61,     0,     0,     0,     0,     0,     0,
      89,    90,     0,     0,    51,    16,    36,    28,    30,    31,
      38,    35,    37,    32,     0,    52,    83,    53,    63,    65,
      72,    75,    79,    86,     0,    34,    33,    81,    97,     0,
      49,     0,     0,    48,     0,     0,     0,    83,    82,     0,
      50,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    85,    99,     0,    96,     0,     0,     0,    47,
       0,     0,    80,    54,    55,    56,    57,    58,    59,    62,
      64,    70,    71,    67,    69,    66,    68,    73,    74,    76,
      77,    78,    95,     0,    60,     0,     0,     0,     0,    98,
       0,    40,    30,     0,    92,    91,     0,     0,     0,    46,
       0,    39,    41,     0,     0,     0,     0,     0,    29,     0,
      29,    42,    94,    93,    44,    29,    45,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,   178,  -143,  -143,  -143,  -143,   154,   -30,
    -143,   149,   -15,  -143,    11,   -81,    45,  -142,    37,  -143,
    -143,  -143,  -143,  -143,  -143,   -46,  -143,   -47,  -143,    94,
      96,    66,    29,   -44,  -143,   -64,  -143,  -143,  -143,  -143,
    -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    14,    23,    24,    25,    56,
      37,     9,    10,    15,    16,    40,    57,    58,    59,    60,
     159,   166,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   114,
     115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    84,    97,    26,   152,    87,    11,    89,    88,   100,
     101,   102,   103,    -9,    78,   161,    26,    18,     1,    17,
      79,     2,    39,    97,   104,   105,     3,   112,     4,    19,
      20,    28,   113,   116,    13,   117,   118,    32,    21,   120,
     121,    41,    27,    42,    43,   123,   124,   125,   126,   127,
     128,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,   139,   140,   141,    29,    41,     1,
      42,    43,     2,   -21,    44,    50,    51,    22,    52,     4,
      45,    46,    47,    48,    53,    49,    83,   174,    30,   176,
      41,    31,    42,    43,   177,    17,    33,   149,    34,   150,
     106,   107,    50,    51,   154,    52,    34,   172,    80,    34,
     160,    53,   164,    54,   165,    34,    55,    41,   155,    42,
      43,    50,    51,    44,    50,    51,    81,    52,    82,    45,
      46,    47,    48,    53,    49,   137,   138,   173,   108,   109,
     110,    91,    92,    93,    94,    95,    96,    85,    90,    86,
      99,    50,    51,    98,    52,    50,    51,   111,   119,   122,
      53,    79,    54,   142,    34,   157,   131,   132,   133,   134,
     135,   136,   143,   144,   145,   146,   147,   148,   158,   163,
     156,   153,   167,   169,    12,    36,    38,   168,   170,   171,
     175,   151,   129,     0,   162,   130
};

static const yytype_int16 yycheck[] =
{
      30,    47,    66,    18,   146,    52,     0,    53,    52,    29,
      30,    31,    32,    46,    46,   157,    31,    46,    11,    52,
      52,    14,    37,    87,    44,    45,    19,    74,    21,    48,
      49,    20,    78,    79,     6,    81,    82,    26,     3,    85,
      86,     3,     6,     5,     6,    91,    92,    93,    94,    95,
      96,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   108,   109,   110,    53,     3,    11,
       5,     6,    14,     6,     9,    37,    38,    19,    40,    21,
      15,    16,    17,    18,    46,    20,    48,   168,    47,   170,
       3,    49,     5,     6,   175,    52,    48,   143,    50,   145,
      39,    40,    37,    38,    48,    40,    50,    48,    48,    50,
     156,    46,    10,    48,    12,    50,    51,     3,   148,     5,
       6,    37,    38,     9,    37,    38,    46,    40,    46,    15,
      16,    17,    18,    46,    20,   106,   107,   167,    41,    42,
      43,    23,    24,    25,    26,    27,    28,    46,    48,    46,
      35,    37,    38,    36,    40,    37,    38,     6,    48,    47,
      46,    52,    48,    47,    50,    13,   100,   101,   102,   103,
     104,   105,    49,    53,    48,    47,    47,    47,    10,     3,
      48,    50,    47,     3,     6,    31,    37,    54,    54,    51,
      54,   146,    98,    -1,   157,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    19,    21,    56,    57,    58,    59,    66,
      67,     0,    58,     6,    60,    68,    69,    52,    46,    48,
      49,     3,    19,    61,    62,    63,    67,     6,    69,    53,
      47,    49,    69,    48,    50,    64,    63,    65,    66,    67,
      70,     3,     5,     6,     9,    15,    16,    17,    18,    20,
      37,    38,    40,    46,    48,    51,    64,    71,    72,    73,
      74,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    46,    52,
      48,    46,    46,    48,    80,    46,    46,    82,    88,    80,
      48,    23,    24,    25,    26,    27,    28,    90,    36,    35,
      29,    30,    31,    32,    44,    45,    39,    40,    41,    42,
      43,     6,    82,    80,    94,    95,    80,    80,    80,    48,
      80,    80,    47,    80,    80,    80,    80,    80,    80,    84,
      85,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    47,    49,    53,    48,    47,    47,    47,    80,
      80,    71,    72,    50,    48,    64,    48,    13,    10,    75,
      80,    72,    73,     3,    10,    12,    76,    47,    54,     3,
      54,    51,    48,    64,    70,    54,    70,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    61,    62,    62,    63,    64,    65,    65,    66,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    94,    94,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     6,     6,     1,
       1,     1,     0,     3,     1,     2,     4,     2,     0,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       5,     7,     8,     5,     4,     3,     0,     3,     2,     2,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       4,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     5,     5,     9,     9,     4,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 25 "bar.y" /* yacc.c:1646  */
    { 
	ASTNode *prog = makeASTNode(_PROG, NO_TYPE);
	ASTNode *declist = pop(stack);
	push(stack, setChild(prog, declist));
}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 31 "bar.y" /* yacc.c:1646  */
    {
	ASTNode *dec = pop(stack);
	ASTNode *declist = pop(stack);
	push(stack, setLastSibling(declist, dec));
}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "bar.y" /* yacc.c:1646  */
    {}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 38 "bar.y" /* yacc.c:1646  */
    {}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 39 "bar.y" /* yacc.c:1646  */
    {}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 42 "bar.y" /* yacc.c:1646  */
    {
	ASTNode *cpdstmt = pop(stack);
	ASTNode *params = pop(stack);
	ASTNode *funcid = pop(stack);
	ASTNode *funcdec = makeASTNode(_FUNCDEC, NO_TYPE);
	funcdec = setChild(funcdec, setSibling(pop(stack), setSibling(funcid, setSibling(params, cpdstmt))));
	push(stack, funcdec);
}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "bar.y" /* yacc.c:1646  */
    {
	ASTNode *funcdec = makeASTNode(_FUNCDEC, NO_TYPE);
	ASTNode *params = pop(stack);
	ASTNode *funcid = pop(stack);
	funcdec = setChild(funcdec, setSibling(setSibling(pop(stack), funcid), params));
	push(stack, funcdec);
}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 59 "bar.y" /* yacc.c:1646  */
    {
		push(stack, makeASTNodeID((yyvsp[0].sVal), NO_TYPE)); 
	}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 64 "bar.y" /* yacc.c:1646  */
    { 
		ASTNode *params = makeASTNode(_PARAMS, NO_TYPE);
		push(stack, setChild(params, pop(stack)));
	  }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "bar.y" /* yacc.c:1646  */
    { 
		ASTNode *params = makeASTNode(_PARAMS, NO_TYPE);
		ASTNode *voidtype = makeASTNode(_TYPE, TYPE_VOID);
		push(stack, setChild(params, voidtype));
	  }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_PARAMS, NO_TYPE)); }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 75 "bar.y" /* yacc.c:1646  */
    { 
		   ASTNode *param = pop(stack);
		   ASTNode *paramlist = pop(stack);
		   push(stack, setLastSibling(paramlist, param));
 		 }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 80 "bar.y" /* yacc.c:1646  */
    {}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 82 "bar.y" /* yacc.c:1646  */
    {
	   ASTNode *param = makeASTNode(_PARAM, NO_TYPE);
	   ASTNode *value = pop(stack);
	   ASTNode *type = pop(stack);
	   push(stack, setChild(param, setSibling(type, value)));
     }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "bar.y" /* yacc.c:1646  */
    { 
				ASTNode *cpdstmt = makeASTNode(_CPDSTMT, NO_TYPE);
				ASTNode *stmtlist = pop(stack);
				ASTNode *ldeclist = pop(stack);
				push(stack, setChild(cpdstmt, setSibling(ldeclist, stmtlist)));
 			}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "bar.y" /* yacc.c:1646  */
    {
						ASTNode *vardec = pop(stack);
						ASTNode *ldeclist = pop(stack);
						if (getChild(ldeclist)) {
							ldeclist = setChild(ldeclist,setLastSibling(getChild(ldeclist), vardec));
							push(stack, ldeclist);
						} else {
							push(stack, setChild(ldeclist, vardec));
						}
					}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 106 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_LDECLIST, NO_TYPE)); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "bar.y" /* yacc.c:1646  */
    {
				ASTNode *vardec = makeASTNode(_VARDEC, NO_TYPE);
			  	ASTNode *ids = pop(stack);
				ASTNode *type = pop(stack);
				push(stack, setChild(vardec, setSibling(type, ids)));
			  }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_TYPE, TYPE_INT)); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_TYPE, TYPE_VOID)); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 117 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_TYPE, TYPE_INT)); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 118 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_TYPE, TYPE_FLOAT)); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "bar.y" /* yacc.c:1646  */
    { 
     ASTNode *value = pop(stack);
	 ASTNode *ids = pop(stack);
	 push(stack, setLastSibling(ids, value));
   }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "bar.y" /* yacc.c:1646  */
    {}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "bar.y" /* yacc.c:1646  */
    {
	   ASTNode *value = makeASTNode(_VALUE, NO_TYPE);
	   ASTNode *integer = makeASTNodeINT((yyvsp[-1].iVal));
	   ASTNode *id = makeASTNodeID((yyvsp[-3].sVal), NO_TYPE);
	   push(stack, setChild(value, setSibling(id, integer)));
	 }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 133 "bar.y" /* yacc.c:1646  */
    {
		push(stack, makeASTNodeID((yyvsp[0].sVal), NO_TYPE));
	 }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 137 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *stmt = pop(stack);
			ASTNode *stmtlist = pop(stack);
			if (getChild(stmtlist)) {
				stmtlist = setChild(stmtlist, setLastSibling(getChild(stmtlist),stmt));
				push(stack, stmtlist);
			} else {
				push(stack, setChild(stmtlist, stmt));
			}
		}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 147 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_STMTLIST, NO_TYPE)); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 149 "bar.y" /* yacc.c:1646  */
    {}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "bar.y" /* yacc.c:1646  */
    {}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 152 "bar.y" /* yacc.c:1646  */
    {}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 153 "bar.y" /* yacc.c:1646  */
    {}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "bar.y" /* yacc.c:1646  */
    {}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 155 "bar.y" /* yacc.c:1646  */
    {}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 156 "bar.y" /* yacc.c:1646  */
    {}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 157 "bar.y" /* yacc.c:1646  */
    {}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 158 "bar.y" /* yacc.c:1646  */
    {}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 159 "bar.y" /* yacc.c:1646  */
    {
			   ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			   ASTNode *false_stmt = pop(stack);
			   ASTNode *true_stmt = pop(stack);
			   ASTNode *expr = pop(stack);
			   push(stack, setChild(ifstmt, setSibling(expr, (setSibling(true_stmt, false_stmt)))));
		   }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			ASTNode *stmt = pop(stack);
			ASTNode *expr = pop(stack);
			push(stack, setChild(ifstmt, setSibling(expr, stmt)));
		}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 173 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			ASTNode *openstmt = pop(stack);
			ASTNode *matchedstmt = pop(stack);
			ASTNode *expr = pop(stack);
			push(stack, setChild(ifstmt, setSibling(expr, setSibling(matchedstmt, openstmt))));
		}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 181 "bar.y" /* yacc.c:1646  */
    {
		    ASTNode *swstmt = makeASTNode(_SWSTMT, NO_TYPE);
			ASTNode *defaultcase = pop(stack);
			ASTNode *caselist = pop(stack);
			ASTNode *expr = setSibling(pop(stack), setSibling(caselist, defaultcase));
			push(stack, setChild(swstmt, expr));
		  }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 189 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *stmtlist = pop(stack);
			ASTNode *integer = makeASTNodeINT((yyvsp[-2].iVal));
			ASTNode *caselist = pop(stack);
			push(stack, setChild(caselist, setSibling(integer, stmtlist)));
		}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 195 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *caselist = makeASTNode(_CASE, NO_TYPE);
			ASTNode *stmtlist = pop(stack);
			ASTNode *integer = makeASTNodeINT((yyvsp[-2].iVal));
			push(stack, setChild(caselist, setSibling(integer, stmtlist)));
		}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "bar.y" /* yacc.c:1646  */
    {
		       ASTNode *defaultstmt = makeASTNode(_DEFAULT, NO_TYPE);
			   ASTNode *stmtlist = pop(stack);
			   push(stack, setChild(defaultstmt, stmtlist));
		   }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 207 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_DEFAULT, NO_TYPE)); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 209 "bar.y" /* yacc.c:1646  */
    {
		    ASTNode *rtstmt = makeASTNode(_RTSTMT, NO_TYPE);
			push(stack, setChild(rtstmt, pop(stack)));
		  }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 213 "bar.y" /* yacc.c:1646  */
    {
			push(stack, makeASTNode(_RTSTMT, NO_TYPE));
		  }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 217 "bar.y" /* yacc.c:1646  */
    {
			push(stack, makeASTNode(_BRKSTMT, NO_TYPE));
		 }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 221 "bar.y" /* yacc.c:1646  */
    {}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 222 "bar.y" /* yacc.c:1646  */
    {}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 224 "bar.y" /* yacc.c:1646  */
    {}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 225 "bar.y" /* yacc.c:1646  */
    {}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 227 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 233 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("+=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 239 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("-=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 245 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("*=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 251 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("/=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 257 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("%=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 264 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *idarr = makeASTNode(_ID_ARR, NO_TYPE);
			ASTNode *expr = pop(stack);
			ASTNode *id = makeASTNodeID((yyvsp[-3].sVal), NO_TYPE);
			push(stack, setChild(idarr, setSibling(id, expr)));
		}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 270 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNodeID((yyvsp[0].sVal), NO_TYPE)); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 272 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *andexpr = pop(stack);
			ASTNode *orop = makeASTNodeOP("||", NO_TYPE);
			push(stack, setChild(orop, setSibling(pop(stack), andexpr)));
		  }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "bar.y" /* yacc.c:1646  */
    {}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 279 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relexpr = pop(stack);
			ASTNode *andop = makeASTNodeOP("&&", NO_TYPE);
			push(stack, setChild(andop, setSibling(pop(stack), relexpr)));
	   }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 284 "bar.y" /* yacc.c:1646  */
    {}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 286 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relop = makeASTNodeOP("<", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 291 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relop = makeASTNodeOP("<=", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 296 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relop = makeASTNodeOP(">", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 301 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relop = makeASTNodeOP(">=", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 306 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relop = makeASTNodeOP("==", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 311 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *relop = makeASTNodeOP("!=", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 316 "bar.y" /* yacc.c:1646  */
    {}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 318 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *term = pop(stack);
			ASTNode *oper = makeASTNodeOP("+", NO_TYPE);
			push(stack, setChild(oper, setSibling(pop(stack), term)));
	   }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 323 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *term = pop(stack);
			ASTNode *oper = makeASTNodeOP("-", NO_TYPE);
			push(stack, setChild(oper, setSibling(pop(stack), term)));
	   }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 328 "bar.y" /* yacc.c:1646  */
    {}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 330 "bar.y" /* yacc.c:1646  */
    { 
		ASTNode *factor = pop(stack);
		ASTNode *oper = makeASTNodeOP("*", NO_TYPE);
		push(stack, setChild(oper, setSibling(pop(stack), factor)));
 	}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 335 "bar.y" /* yacc.c:1646  */
    { 
		ASTNode *factor = pop(stack);
		ASTNode *oper = makeASTNodeOP("/", NO_TYPE);
		push(stack, setChild(oper, setSibling(pop(stack), factor)));
 	}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 340 "bar.y" /* yacc.c:1646  */
    { 
		ASTNode *factor = pop(stack);
		ASTNode *oper = makeASTNodeOP("%", NO_TYPE);
		push(stack, setChild(oper, setSibling(pop(stack), factor)));
 	}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 345 "bar.y" /* yacc.c:1646  */
    {}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 347 "bar.y" /* yacc.c:1646  */
    {}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 348 "bar.y" /* yacc.c:1646  */
    {}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 349 "bar.y" /* yacc.c:1646  */
    {
		  ASTNode *factor = pop(stack);
		  ASTNode *neg = makeASTNodeOP("-", NO_TYPE);
		  push(stack, setChild(neg, factor));
	  }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 354 "bar.y" /* yacc.c:1646  */
    {}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 355 "bar.y" /* yacc.c:1646  */
    {
		  ASTNode *incdecexp = makeASTNode(_INCDEC_EXP, NO_TYPE);
		  ASTNode *incdec = pop(stack);
		  push(stack, setChild(incdecexp, setSibling(pop(stack), incdec)));
	  }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 360 "bar.y" /* yacc.c:1646  */
    {
		  ASTNode *incdecexp = makeASTNode(_INCDEC_EXP, NO_TYPE);
		  ASTNode *variable = pop(stack);
		  push(stack, setChild(incdecexp, setSibling(pop(stack), variable)));
	  }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 365 "bar.y" /* yacc.c:1646  */
    {}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 367 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNodeINT((yyvsp[0].iVal))); }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 368 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNodeREAL((yyvsp[0].rVal))); }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 370 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNodeOP("++", NO_TYPE)); }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 371 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNodeOP("--", NO_TYPE)); }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 373 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *whlstmt = makeASTNode(_WHLSTMT, NO_TYPE);
			ASTNode *cpdstmt = pop(stack);
			ASTNode *expr = pop(stack);
			push(stack, setChild(whlstmt, setSibling(expr, cpdstmt)));
		 }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 379 "bar.y" /* yacc.c:1646  */
    {
			 ASTNode *whlstmt = makeASTNode(_WHLSTMT, NO_TYPE);
			 ASTNode *expr = pop(stack);
			 push(stack, setChild(whlstmt, expr));
		 }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 385 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *forstmt = makeASTNode(_FORSTMT, NO_TYPE);
			ASTNode *cpdstmt = pop(stack);
			ASTNode *expr3 = pop(stack);
			ASTNode *expr2 = pop(stack);
			ASTNode *expr1 = pop(stack);
			expr1 = setSibling(expr1, setSibling(expr2, setSibling(expr3, cpdstmt)));
			push(stack, setChild(forstmt, expr1));
	   }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 394 "bar.y" /* yacc.c:1646  */
    {
		    ASTNode *forstmt = makeASTNode(_FORSTMT, NO_TYPE);
		    ASTNode *expr3 = pop(stack);
			ASTNode *expr2 = pop(stack);
			ASTNode *expr1 = pop(stack);
			push(stack, setChild(forstmt, setSibling(expr1, setSibling(expr2, expr3))));
	   }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 402 "bar.y" /* yacc.c:1646  */
    {
				ASTNode *funccall = makeASTNode(_FUNCCALL, NO_TYPE);
				ASTNode *id = makeASTNodeID((yyvsp[-3].sVal), NO_TYPE);
				ASTNode *arguments = pop(stack);
				push(stack, setChild(funccall, setSibling(id, arguments)));
			}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 409 "bar.y" /* yacc.c:1646  */
    {
			ASTNode *args = makeASTNode(_ARGS, NO_TYPE);
			push(stack, setChild(args, pop(stack)));
		 }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 413 "bar.y" /* yacc.c:1646  */
    { push(stack, makeASTNode(_ARGS, NO_TYPE)); }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 415 "bar.y" /* yacc.c:1646  */
    {
				ASTNode *expr = pop(stack);
				ASTNode *arglist = pop(stack);
				push(stack, setLastSibling(arglist, expr));
			}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 420 "bar.y" /* yacc.c:1646  */
    {}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2286 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 423 "bar.y" /* yacc.c:1906  */

void dfs(ASTNode *node) {
	int node_type = getTkNum(node);
	int check2 = 0;
	if (node_type == _FORSTMT || node_type == _WHLSTMT || node_type == _SWSTMT) {
		check++;
		check2 = 1;
	} 
	
	if (node_type == _BRKSTMT) {
		if (check != 1) {
			isSyntaxError = 1;
			return;
		}
	}
	
	ASTNode *child = getChild(node);
	while (child != 0) {
		dfs(child);
		child = getSibling(child);
	}
	if (check2 == 1) check--;
	ASTNode *sibling = getSibling(node);
	while (sibling != 0) {
		dfs(sibling);
		sibling = getSibling(sibling);
	}
	return;
}

int main(int argc, char *argv[]){
	extern FILE *yyin;
	stack = initStack();
	check = 0;
	isSyntaxError = 0;
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	ASTNode *tmp = pop(stack);
	printAST(tmp);
	dfs(tmp);
	if (isSyntaxError == 1) {
		printf("Syntax Error\n");
	}
	return 0;
}


/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 23 "oberon.y"


#include<stdio.h>
#include "symbol_table.h"
#include "ast.h"
#include "ast.c"
void yyerror(const char *);
int yylex(void);

extern char * yytext; 



/* Line 268 of yacc.c  */
#line 85 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEMIC = 258,
     COMMA = 259,
     COLON = 260,
     RIGHTBRAC = 261,
     LEFTBRAC = 262,
     DOTSYM = 263,
     LSQBR = 264,
     RSQBR = 265,
     LCBR = 266,
     RCBR = 267,
     CARR = 268,
     EQ_COMP = 269,
     UNEQ = 270,
     TILDA = 271,
     ASSIGN = 272,
     DOTDOT = 273,
     REPEAT = 274,
     UNTIL = 275,
     FOR = 276,
     TO = 277,
     BY = 278,
     DOCASE = 279,
     END = 280,
     WHILE = 281,
     IF_COND = 282,
     THEN = 283,
     ELSEIF = 284,
     ELSE = 285,
     CASE_COND = 286,
     OF = 287,
     STRLEN = 288,
     STRCAT = 289,
     STRCMP = 290,
     STRREV = 291,
     STRCPY = 292,
     NEW = 293,
     ARRAY = 294,
     RECORD = 295,
     SET = 296,
     BEG = 297,
     CONST = 298,
     EXIT = 299,
     IMPORT = 300,
     LOOP = 301,
     MODULE = 302,
     NIL = 303,
     POINTER = 304,
     PROCEDURE = 305,
     RETURN = 306,
     TYPE = 307,
     VAR = 308,
     WITH = 309,
     ABS = 310,
     ODD = 311,
     LEN = 312,
     LSL = 313,
     ASR = 314,
     ROR = 315,
     FLOOR = 316,
     FLT = 317,
     ORD = 318,
     CHR = 319,
     LONG = 320,
     SHORT = 321,
     INC = 322,
     DEC = 323,
     INCL = 324,
     EXCL = 325,
     COPY = 326,
     ASSERT = 327,
     PACK = 328,
     UNPK = 329,
     BOOLEAN = 330,
     CHAR = 331,
     INTEGER = 332,
     LONGREAL = 333,
     REAL = 334,
     BOOLEAN_VAL = 335,
     CHAR_VAL = 336,
     INTEGER_VAL = 337,
     REAL_VAL = 338,
     STRING_VAL = 339,
     IDENT = 340,
     IS = 341,
     IN = 342,
     GE = 343,
     GT = 344,
     LE = 345,
     LT = 346,
     OR = 347,
     MINUS_SYM = 348,
     PLUS_SYM = 349,
     OR_SYM = 350,
     AND_SYM = 351,
     MOD = 352,
     DIV = 353,
     DIVIDE_SYM = 354,
     MULTIPLY_SYM = 355
   };
#endif
/* Tokens.  */
#define SEMIC 258
#define COMMA 259
#define COLON 260
#define RIGHTBRAC 261
#define LEFTBRAC 262
#define DOTSYM 263
#define LSQBR 264
#define RSQBR 265
#define LCBR 266
#define RCBR 267
#define CARR 268
#define EQ_COMP 269
#define UNEQ 270
#define TILDA 271
#define ASSIGN 272
#define DOTDOT 273
#define REPEAT 274
#define UNTIL 275
#define FOR 276
#define TO 277
#define BY 278
#define DOCASE 279
#define END 280
#define WHILE 281
#define IF_COND 282
#define THEN 283
#define ELSEIF 284
#define ELSE 285
#define CASE_COND 286
#define OF 287
#define STRLEN 288
#define STRCAT 289
#define STRCMP 290
#define STRREV 291
#define STRCPY 292
#define NEW 293
#define ARRAY 294
#define RECORD 295
#define SET 296
#define BEG 297
#define CONST 298
#define EXIT 299
#define IMPORT 300
#define LOOP 301
#define MODULE 302
#define NIL 303
#define POINTER 304
#define PROCEDURE 305
#define RETURN 306
#define TYPE 307
#define VAR 308
#define WITH 309
#define ABS 310
#define ODD 311
#define LEN 312
#define LSL 313
#define ASR 314
#define ROR 315
#define FLOOR 316
#define FLT 317
#define ORD 318
#define CHR 319
#define LONG 320
#define SHORT 321
#define INC 322
#define DEC 323
#define INCL 324
#define EXCL 325
#define COPY 326
#define ASSERT 327
#define PACK 328
#define UNPK 329
#define BOOLEAN 330
#define CHAR 331
#define INTEGER 332
#define LONGREAL 333
#define REAL 334
#define BOOLEAN_VAL 335
#define CHAR_VAL 336
#define INTEGER_VAL 337
#define REAL_VAL 338
#define STRING_VAL 339
#define IDENT 340
#define IS 341
#define IN 342
#define GE 343
#define GT 344
#define LE 345
#define LT 346
#define OR 347
#define MINUS_SYM 348
#define PLUS_SYM 349
#define OR_SYM 350
#define AND_SYM 351
#define MOD 352
#define DIV 353
#define DIVIDE_SYM 354
#define MULTIPLY_SYM 355




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 327 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   692

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    17,    21,    22,    26,    28,
      31,    34,    35,    38,    39,    43,    46,    50,    52,    60,
      67,    73,    78,    82,    86,    88,    91,    93,    94,   104,
     112,   116,   120,   124,   128,   132,   136,   140,   144,   148,
     152,   156,   160,   164,   168,   172,   176,   178,   180,   182,
     184,   186,   188,   192,   195,   198,   202,   207,   210,   215,
     218,   219,   221,   225,   229,   233,   235,   237,   241,   247,
     248,   251,   252,   254,   258,   262,   263,   265,   269,   271,
     275,   278,   282,   286,   290,   291,   297,   298,   304,   305,
     311,   312,   314,   316,   318,   320,   322,   324,   329,   333,
     340,   344,   348,   351,   353,   356,   359,   360,   362,   366,
     368,   374,   378,   379,   383,   384,   393,   399,   403,   406,
     407,   411,   413,   417,   422,   425,   428,   429
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     102,     0,    -1,   103,   104,    25,   145,     8,    -1,    47,
     145,     3,    -1,   105,   127,   109,    -1,    45,   106,     3,
      -1,    -1,   106,     4,   107,    -1,   107,    -1,   145,   108,
      -1,    17,   145,    -1,    -1,    42,   110,    -1,    -1,   111,
       3,   110,    -1,   111,     3,    -1,   115,    17,   113,    -1,
     115,    -1,    27,   113,    28,   110,   121,   122,    25,    -1,
      31,   113,    32,   123,   122,    25,    -1,    26,   113,    24,
     110,    25,    -1,    19,   110,    20,   113,    -1,    21,   145,
     112,    -1,    46,   110,    25,    -1,    44,    -1,    51,   113,
      -1,    51,    -1,    -1,    17,   113,    22,   113,    23,   135,
      24,   110,    25,    -1,    17,   113,    22,   113,    24,   110,
      25,    -1,   113,    14,   113,    -1,   113,    15,   113,    -1,
     113,    91,   113,    -1,   113,    90,   113,    -1,   113,    89,
     113,    -1,   113,    88,   113,    -1,   113,    87,   113,    -1,
     113,    86,   113,    -1,   113,    94,   113,    -1,   113,    93,
     113,    -1,   113,    92,   113,    -1,   113,   100,   113,    -1,
     113,    99,   113,    -1,   113,    98,   113,    -1,   113,    97,
     113,    -1,   113,    96,   113,    -1,   114,    -1,   115,    -1,
      82,    -1,    81,    -1,    48,    -1,   118,    -1,     7,   113,
       6,    -1,    16,   114,    -1,   145,   116,    -1,     8,   145,
     116,    -1,     9,   117,    10,   116,    -1,    13,   116,    -1,
       7,   117,     6,   116,    -1,     7,     6,    -1,    -1,   113,
      -1,   113,     4,   117,    -1,    11,   119,    12,    -1,   120,
       4,   119,    -1,   120,    -1,   113,    -1,   113,    18,   113,
      -1,    29,   113,    28,   110,   121,    -1,    -1,    30,   110,
      -1,    -1,   124,    -1,   124,    95,   123,    -1,   125,     5,
     110,    -1,    -1,   126,    -1,   126,     4,   125,    -1,   113,
      -1,   113,    18,   113,    -1,   128,   138,    -1,    43,   129,
     128,    -1,    52,   130,   128,    -1,    53,   131,   128,    -1,
      -1,   143,    14,   135,     3,   129,    -1,    -1,   143,    14,
     132,     3,   130,    -1,    -1,   143,     5,   132,     3,   131,
      -1,    -1,   133,    -1,    77,    -1,    76,    -1,    75,    -1,
      79,    -1,    78,    -1,    39,   136,    32,   132,    -1,    39,
      32,   132,    -1,    40,     7,   133,     6,   137,    25,    -1,
      40,   137,    25,    -1,    49,    22,   132,    -1,    50,   140,
      -1,    41,    -1,   145,   134,    -1,     8,   145,    -1,    -1,
     113,    -1,   135,     4,   136,    -1,   135,    -1,   143,     5,
     132,     3,   137,    -1,   143,     5,   132,    -1,    -1,   139,
       3,   138,    -1,    -1,    50,   145,   140,     3,   127,   109,
      25,   145,    -1,     7,   141,     6,     5,   132,    -1,     7,
     141,     6,    -1,     7,     6,    -1,    -1,   142,     3,   141,
      -1,   142,    -1,   143,     5,   132,    -1,    53,   143,     5,
     132,    -1,   145,   144,    -1,     4,   143,    -1,    -1,    85,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    45,    49,    53,    54,    58,    59,    63,
      67,    68,    72,    73,    77,    78,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    97,    98,
     103,   104,   105,   106,   107,   108,   109,   110,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   125,   126,   127,
     128,   129,   130,   131,   135,   139,   140,   141,   142,   143,
     144,   148,   149,   153,   157,   158,   162,   163,   167,   168,
     172,   173,   177,   178,   182,   183,   187,   188,   192,   193,
     201,   205,   206,   207,   208,   215,   216,   220,   221,   225,
     226,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   249,   253,   254,   259,   263,   264,
     269,   270,   271,   277,   278,   282,   288,   289,   290,   291,
     295,   296,   300,   301,   305,   309,   310,   314
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMIC", "COMMA", "COLON", "RIGHTBRAC",
  "LEFTBRAC", "DOTSYM", "LSQBR", "RSQBR", "LCBR", "RCBR", "CARR",
  "EQ_COMP", "UNEQ", "TILDA", "ASSIGN", "DOTDOT", "REPEAT", "UNTIL", "FOR",
  "TO", "BY", "DOCASE", "END", "WHILE", "IF_COND", "THEN", "ELSEIF",
  "ELSE", "CASE_COND", "OF", "STRLEN", "STRCAT", "STRCMP", "STRREV",
  "STRCPY", "NEW", "ARRAY", "RECORD", "SET", "BEG", "CONST", "EXIT",
  "IMPORT", "LOOP", "MODULE", "NIL", "POINTER", "PROCEDURE", "RETURN",
  "TYPE", "VAR", "WITH", "ABS", "ODD", "LEN", "LSL", "ASR", "ROR", "FLOOR",
  "FLT", "ORD", "CHR", "LONG", "SHORT", "INC", "DEC", "INCL", "EXCL",
  "COPY", "ASSERT", "PACK", "UNPK", "BOOLEAN", "CHAR", "INTEGER",
  "LONGREAL", "REAL", "BOOLEAN_VAL", "CHAR_VAL", "INTEGER_VAL", "REAL_VAL",
  "STRING_VAL", "IDENT", "IS", "IN", "GE", "GT", "LE", "LT", "OR",
  "MINUS_SYM", "PLUS_SYM", "OR_SYM", "AND_SYM", "MOD", "DIV", "DIVIDE_SYM",
  "MULTIPLY_SYM", "$accept", "Module", "cast_away", "Main_Block",
  "Import_Modules", "Import_Modules_List", "Import", "Import_Aux",
  "Stat_Block", "Statement_Sequence", "Statement", "Statement_Aux", "Expr",
  "Factor", "Designator", "optSuffix", "Expr_List", "Set", "Element_List",
  "Element", "Else_If_Block", "Else", "Case_Parameters", "Case_Single",
  "Case_Expression_List", "Case_Expression", "Decl_Seq", "Data_List",
  "Const_List", "Type_List", "Var_List", "Type", "Qualident",
  "Qualident_Aux", "Const_Expr", "Const_Expr_List", "Field_List",
  "Proc_List", "Proc_Decl", "Formal_Pars", "FP_section_List", "FP_section",
  "Identifier_List", "Identifier_List_Aux", "ident", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   104,   105,   105,   106,   106,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   115,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   134,   134,   135,   136,   136,
     137,   137,   137,   138,   138,   139,   140,   140,   140,   140,
     141,   141,   142,   142,   143,   144,   144,   145
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     3,     3,     0,     3,     1,     2,
       2,     0,     2,     0,     3,     2,     3,     1,     7,     6,
       5,     4,     3,     3,     1,     2,     1,     0,     9,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     3,     4,     2,     4,     2,
       0,     1,     3,     3,     3,     1,     1,     3,     5,     0,
       2,     0,     1,     3,     3,     0,     1,     3,     1,     3,
       2,     3,     3,     3,     0,     5,     0,     5,     0,     5,
       0,     1,     1,     1,     1,     1,     1,     4,     3,     6,
       3,     3,     2,     1,     2,     2,     0,     1,     3,     1,
       5,     3,     0,     3,     0,     8,     5,     3,     2,     0,
       3,     1,     3,     4,     2,     2,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,   127,     0,     1,     0,     0,    84,
       3,     0,     8,    11,     0,    86,    88,    90,    13,   114,
       5,     0,     0,     9,     0,    84,     0,   126,    84,     0,
      84,     0,    27,     4,     0,    80,     0,     7,    10,     2,
      81,     0,     0,   124,    82,     0,    83,     0,    27,     0,
       0,     0,     0,    24,    27,    26,    12,     0,    17,    60,
     119,   114,     0,     0,     0,    50,    49,    48,   107,    46,
      47,    51,     0,   125,     0,   112,   103,     0,   119,    94,
      93,    92,    96,    95,     0,    91,   106,     0,     0,     0,
       0,     0,     0,     0,    25,    15,     0,     0,     0,     0,
      60,    54,     0,     0,   113,     0,    66,     0,    65,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,   109,     0,
       0,     0,     0,     0,   102,    88,     0,   104,    90,     0,
       0,    22,    27,    27,    75,    23,    14,    16,    59,    61,
       0,    60,     0,    57,   118,     0,     0,   121,     0,    84,
      52,     0,    63,     0,    30,    31,    37,    36,    35,    34,
      33,    32,    40,    39,    38,    45,    44,    43,    42,    41,
      85,    98,     0,     0,     0,   100,     0,   101,    87,   105,
      89,    21,     0,     0,    69,    78,    71,    72,     0,    76,
       0,    60,    55,    60,     0,   117,     0,     0,    13,    67,
      64,   108,    97,   112,   111,     0,    20,     0,    71,     0,
      27,     0,    75,    27,     0,    62,    58,    56,     0,     0,
     120,   122,     0,     0,   112,     0,     0,     0,    79,    70,
      19,    73,    74,    77,   123,   116,     0,    99,   110,     0,
      27,    27,    18,   115,     0,     0,    69,    27,    29,    68,
       0,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    11,    12,    23,    33,    56,
      57,   141,    68,    69,    70,   101,   150,    71,   107,   108,
     218,   221,   196,   197,   198,   199,    18,    19,    25,    28,
      30,    84,    85,   137,   128,   129,   131,    35,    36,   103,
     156,   157,   132,    43,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -195
static const yytype_int16 yypact[] =
{
     -18,   -59,    35,    -6,  -195,    44,  -195,   -59,    28,   -21,
    -195,    77,  -195,    32,   -59,   -59,   -59,   -59,    21,    15,
    -195,   -59,   -59,  -195,    61,   -21,    58,    78,   -21,    71,
     -21,    81,   286,  -195,   -59,  -195,    87,  -195,  -195,  -195,
    -195,   607,   -59,  -195,  -195,    38,  -195,    38,   286,   -59,
     607,   607,   607,  -195,   286,   607,  -195,    88,    76,    29,
      95,    15,   607,   607,   607,  -195,  -195,  -195,   498,  -195,
    -195,  -195,    92,  -195,   184,    11,  -195,    85,    95,  -195,
    -195,  -195,  -195,  -195,   100,  -195,   102,   116,   101,   103,
     344,   324,   359,    97,   498,    24,   607,    60,   -59,   607,
      29,  -195,     4,   121,  -195,   164,   374,   119,   124,  -195,
     607,   607,   607,   607,   607,   607,   607,   607,   607,   607,
     607,   607,   607,   607,   607,   607,   -59,    38,   129,   104,
     -59,   113,   134,    38,  -195,   -59,   -59,  -195,   -59,   607,
     607,  -195,   286,   286,   607,  -195,  -195,   498,  -195,    69,
     137,    29,   130,  -195,  -195,   -59,   138,   143,   144,   -21,
    -195,   607,  -195,   607,   513,   513,   513,   513,   513,   513,
     513,   513,   -38,   -38,   -38,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,   607,    38,   146,  -195,    38,  -195,  -195,  -195,
    -195,   498,   461,   125,   135,   411,   123,    79,   166,   169,
     607,    29,  -195,    29,   170,   171,   -29,    38,    21,   498,
    -195,  -195,  -195,   -59,   178,   607,  -195,   607,   123,   607,
     286,   158,   607,   286,   607,  -195,  -195,  -195,    38,    38,
    -195,  -195,   159,   161,   -59,   257,   478,   162,   498,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,   -59,  -195,  -195,   607,
     286,   286,  -195,  -195,   172,   163,   135,   286,  -195,  -195,
     165,  -195
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,  -195,  -195,  -195,  -195,   176,  -195,    -9,   -43,
    -195,  -195,   179,   139,   -31,   -97,   -95,  -195,    39,  -195,
     -55,   -14,   -13,  -195,   -11,  -195,    52,     0,    89,    82,
      80,   -35,    91,  -195,   -39,    40,  -194,   174,  -195,   145,
      18,  -195,    -8,  -195,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
       5,    58,    72,   153,   152,    88,    13,    26,    29,    31,
     154,    93,    87,    24,    27,    27,    27,    58,   130,   233,
      13,    38,    15,    58,   155,    40,     4,   -27,    44,     1,
      46,    16,    17,    60,    73,     6,    97,    98,    99,     7,
     248,    27,   100,    48,    86,    49,    86,    10,    89,    22,
      50,    51,   146,    14,   202,    52,     4,   155,   121,   122,
     123,   124,   125,    32,    58,    34,   148,    62,    53,    39,
      54,    63,    41,   200,    27,    55,    64,    74,    75,    76,
      20,    21,    42,   110,   111,    45,    47,    77,    78,     4,
      61,    95,   181,    96,   158,   126,     4,   151,   187,   193,
     194,    27,   102,   135,   226,   225,   227,   133,    65,     4,
     136,    58,    58,    79,    80,    81,    82,    83,    26,   138,
     140,   139,   145,     4,   159,    27,    86,    29,   163,    86,
      31,   162,    86,   182,    27,   189,   183,    27,   185,   186,
     203,    66,    67,   201,   205,     4,   206,   204,   212,   207,
     216,   214,   213,   220,    27,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   217,   121,   122,   123,   124,   125,
     160,   223,   231,   224,   222,   228,   229,   239,   110,   111,
     242,   234,    86,   240,   246,    86,   247,   252,   258,    58,
     261,    62,    58,   244,   245,    63,   257,    37,   158,   232,
      64,   259,   210,   109,   237,    27,    86,   255,   256,   241,
     254,   208,    27,   243,   260,   180,   127,   188,   190,    58,
      58,   184,   211,   134,   230,     0,    58,    86,    86,    90,
      91,    92,    65,    27,    94,   104,     0,     0,     0,     0,
       0,   105,   106,     0,     0,   253,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,   123,   124,   125,    66,    67,     0,     0,     4,
       0,   110,   111,     0,     0,   147,   149,     0,   149,     0,
     249,   250,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,    48,     0,    49,     0,     0,
       0,     0,    50,    51,     0,     0,     0,    52,   191,   192,
       0,     0,     0,   195,     0,     0,     0,     0,     0,     0,
      53,     0,    54,     0,     0,     0,     0,    55,   110,   111,
     209,     0,   106,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   143,   121,   122,   123,   124,   125,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     4,     0,   110,   111,     0,     0,     0,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
       0,   144,   161,     0,   235,     0,   236,     0,   238,     0,
       0,   195,     0,   195,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,   123,   124,   125,   110,   111,     0,     0,   219,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,   123,   124,   125,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,   122,   123,   124,   125,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,   123,   124,   125,   110,   111,     0,     0,     0,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   251,   121,   122,   123,
     124,   125,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -28,   -28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,   122,   123,
     124,   125,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,   122,   123,   124,   125,     0,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,   122,   123,   124,   125,   -28,
     -28,   -28,   -28,   -28,   -28,   118,   119,   120,     0,   121,
     122,   123,   124,   125,    62,     0,     0,     0,    63,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
       0,     0,     4
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-195))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-28))

static const yytype_int16 yycheck[] =
{
       1,    32,    41,   100,    99,    48,     7,    15,    16,    17,
       6,    54,    47,    14,    15,    16,    17,    48,     7,   213,
      21,    22,    43,    54,    53,    25,    85,     3,    28,    47,
      30,    52,    53,    34,    42,     0,     7,     8,     9,    45,
     234,    42,    13,    19,    45,    21,    47,     3,    49,    17,
      26,    27,    95,    25,   151,    31,    85,    53,    96,    97,
      98,    99,   100,    42,    95,    50,     6,     7,    44,     8,
      46,    11,    14,     4,    75,    51,    16,    39,    40,    41,
       3,     4,     4,    14,    15,    14,     5,    49,    50,    85,
       3,     3,   127,    17,   102,     3,    85,    98,   133,   142,
     143,   102,     7,     3,   201,   200,   203,    22,    48,    85,
       8,   142,   143,    75,    76,    77,    78,    79,   126,     3,
      17,    20,    25,    85,     3,   126,   127,   135,     4,   130,
     138,    12,   133,     4,   135,   136,    32,   138,    25,     5,
      10,    81,    82,     6,     6,    85,     3,   155,   183,     5,
      25,   186,     6,    30,   155,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    29,    96,    97,    98,    99,   100,
       6,     5,   207,     4,    95,     5,     5,   220,    14,    15,
     223,     3,   183,    25,    25,   186,    25,    25,    25,   220,
      25,     7,   223,   228,   229,    11,    24,    21,   206,   208,
      16,   256,   163,    64,   218,   206,   207,   250,   251,   222,
     249,   159,   213,   224,   257,   126,    32,   135,   138,   250,
     251,   130,   182,    78,   206,    -1,   257,   228,   229,    50,
      51,    52,    48,   234,    55,    61,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    81,    82,    -1,    -1,    85,
      -1,    14,    15,    -1,    -1,    96,    97,    -1,    99,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    19,    -1,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    31,   139,   140,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    46,    -1,    -1,    -1,    -1,    51,    14,    15,
     161,    -1,   163,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    28,    96,    97,    98,    99,   100,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    85,    -1,    14,    15,    -1,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    32,    18,    -1,   215,    -1,   217,    -1,   219,    -1,
      -1,   222,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    14,    15,    -1,    -1,    18,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,   100,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    28,    96,    97,    98,
      99,   100,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,     7,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,   102,   103,    85,   145,     0,    45,   104,   105,
       3,   106,   107,   145,    25,    43,    52,    53,   127,   128,
       3,     4,    17,   108,   145,   129,   143,   145,   130,   143,
     131,   143,    42,   109,    50,   138,   139,   107,   145,     8,
     128,    14,     4,   144,   128,    14,   128,     5,    19,    21,
      26,    27,    31,    44,    46,    51,   110,   111,   115,   145,
     145,     3,     7,    11,    16,    48,    81,    82,   113,   114,
     115,   118,   135,   143,    39,    40,    41,    49,    50,    75,
      76,    77,    78,    79,   132,   133,   145,   132,   110,   145,
     113,   113,   113,   110,   113,     3,    17,     7,     8,     9,
      13,   116,     7,   140,   138,   113,   113,   119,   120,   114,
      14,    15,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    96,    97,    98,    99,   100,     3,    32,   135,   136,
       7,   137,   143,    22,   140,     3,     8,   134,     3,    20,
      17,   112,    24,    28,    32,    25,   110,   113,     6,   113,
     117,   145,   117,   116,     6,    53,   141,   142,   143,     3,
       6,    18,    12,     4,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     129,   132,     4,    32,   133,    25,     5,   132,   130,   145,
     131,   113,   113,   110,   110,   113,   123,   124,   125,   126,
       4,     6,   116,    10,   143,     6,     3,     5,   127,   113,
     119,   136,   132,     6,   132,    22,    25,    29,   121,    18,
      30,   122,    95,     5,     4,   117,   116,   116,     5,     5,
     141,   132,   109,   137,     3,   113,   113,   122,   113,   110,
      25,   123,   110,   125,   132,   132,    25,    25,   137,    23,
      24,    28,    25,   145,   135,   110,   110,    24,    25,   121,
     110,    25
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 41 "oberon.y"
    {printf("start \n");}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 45 "oberon.y"
    {printf("Module\n");}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 49 "oberon.y"
    {printf("Import_Modules Decl_Seq Stat_Block\n");}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 53 "oberon.y"
    {printf("IMPORT Import_Modules_List SEMIC\n");}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 54 "oberon.y"
    {printf("IMPORT Import_Modules_List SEMIC_nothing\n");}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 58 "oberon.y"
    {printf("Import_Modules_List COMMA Import\n");}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 59 "oberon.y"
    {printf("Import\n");}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 67 "oberon.y"
    {printf("IDENT ASSIGN IDENT\n");}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 72 "oberon.y"
    {printf("BEG Statement_Sequence\n");}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 73 "oberon.y"
    {printf("BEG Statement_Sequence_Nothing\n");}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 77 "oberon.y"
    {printf("Statement SEMIC Statement_Sequence\n");}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 78 "oberon.y"
    {printf("Statement SEMIC\n");}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 82 "oberon.y"
    {printf(" Designator ASSIGN Expr \n");}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 83 "oberon.y"
    {printf(" Designator\n");}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 84 "oberon.y"
    {printf(" IF_COND Expr THEN Statement_Sequence Else_If_Block Else END\n");}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 85 "oberon.y"
    {printf(" CASE_COND Expr OF Case_Parameters Else END \n");}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 86 "oberon.y"
    {printf("WHILE Expr DOCASE Statement_Sequence END\n");}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 87 "oberon.y"
    {printf("REPEAT Statement_Sequence UNTIL Expr\n");}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 89 "oberon.y"
    {printf("LOOP Statement_Sequence END\n");}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 90 "oberon.y"
    {printf(" EXIT\n");}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 91 "oberon.y"
    {printf(" RETURN Expr\n");}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 92 "oberon.y"
    {printf(" RETURN\n");}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 93 "oberon.y"
    {printf(" stat_nothing\n");}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 97 "oberon.y"
    {printf(" FOR IDENT ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END\n");}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 98 "oberon.y"
    {printf("FOR IDENT ASSIGN Expr TO Expr DOCASE Statement_Sequence END\n");}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 103 "oberon.y"
    {printf("Expr EQ_COMP Expr\n");}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 104 "oberon.y"
    {printf(" Expr UNEQ Expr\n");}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 105 "oberon.y"
    {printf(" Expr LT Expr\n");}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 106 "oberon.y"
    {printf(" Expr LE Expr\n");}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 107 "oberon.y"
    {printf(" Expr GT Expr\n");}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 108 "oberon.y"
    {printf(" Expr GE Expr\n");}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 109 "oberon.y"
    {printf(" Expr IN Expr\n");}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 110 "oberon.y"
    {printf(" Expr IS Expr\n");}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 113 "oberon.y"
    {printf("Expr PLUS_SYM Expr\n");}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 114 "oberon.y"
    {printf("Expr MINUS_SYM Expr\n");}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 115 "oberon.y"
    {printf("Expr OR Expr\n");}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 116 "oberon.y"
    {printf("Expr MULTIPLY_SYM Expr\n");}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 117 "oberon.y"
    {printf("Expr DIVIDE_SYM Expr\n");}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 118 "oberon.y"
    {printf("Expr DIV Expr\n");}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 119 "oberon.y"
    {printf("Expr MOD Expr\n");}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 120 "oberon.y"
    {printf("Expr AND_SYM Expr\n");}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 121 "oberon.y"
    {printf("Factor\n");}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 125 "oberon.y"
    {printf("Designator\n");}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 126 "oberon.y"
    {printf("integer val is %d",(yyvsp[(1) - (1)]));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 127 "oberon.y"
    {printf("CHAR_VAL\n");}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 128 "oberon.y"
    {printf("NIL\n");}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 129 "oberon.y"
    {printf("Set\n");}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 130 "oberon.y"
    {printf("LEFTBRAC Expr RIGHTBRAC\n");}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 131 "oberon.y"
    {printf("TILDA Factor\n");}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 135 "oberon.y"
    {printf("IDENT optSuffix\n");}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 139 "oberon.y"
    {printf("DOTSYM IDENT  optSuffix\n");}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 140 "oberon.y"
    {printf("LSQBR Expr_List RSQBR  optSuffix\n");}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 141 "oberon.y"
    {printf("CARR  optSuffix\n");}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 142 "oberon.y"
    {printf("LEFTBRAC Expr_List RIGHTBRAC optSuffix\n");}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 143 "oberon.y"
    {printf("LEFTBRAC RIGHTBRAC\n");}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 144 "oberon.y"
    {printf("optSuffix_Nothing\n");}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 148 "oberon.y"
    {printf("Expr\n");}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 149 "oberon.y"
    {printf("Expr COMMA Expr_List\n");}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 153 "oberon.y"
    {printf("LCBR Element_List RCBR\n");}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 157 "oberon.y"
    {printf("Element COMMA Element_List\n");}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 158 "oberon.y"
    {printf("Element\n");}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 162 "oberon.y"
    {printf("Expr\n");}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 163 "oberon.y"
    {printf("Expr DOTDOT Expr\n");}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 167 "oberon.y"
    {printf("ELSEIF Expr THEN Statement_Sequence Else_If_Block\n");}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 168 "oberon.y"
    {printf("Else_If_Block_Nothing\n");}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 172 "oberon.y"
    {printf("ELSE Statement_Sequence\n");}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 173 "oberon.y"
    {printf("Else_Nothing\n");}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 177 "oberon.y"
    {printf("Case_Single\n");}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 178 "oberon.y"
    {printf("Case_Single OR_SYM Case_Parameters\n");}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 182 "oberon.y"
    {printf("Case_Expression_List COLON Statement_Sequence\n");}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 183 "oberon.y"
    {printf("Case_Single_Nothing\n");}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 187 "oberon.y"
    {printf("Case_Expression\n");}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 188 "oberon.y"
    {printf("Case_Expression COMMA Case_Expression_List\n");}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 192 "oberon.y"
    {printf("Expr\n");}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 193 "oberon.y"
    {printf("Expr DOTDOT Expr\n");}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 201 "oberon.y"
    {printf("Data_List Proc_List\n");}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 205 "oberon.y"
    {printf("CONST Const_List Data_List\n");}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 206 "oberon.y"
    {printf("TYPE  Type_List  Data_List\n");}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 207 "oberon.y"
    {printf("VAR   Var_List Data_List\n");}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 208 "oberon.y"
    {printf("Data_List_Nothing\n");}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 215 "oberon.y"
    {printf("Identifier_List EQ_COMP Const_Expr SEMIC Const_List\n");}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 216 "oberon.y"
    {printf("Const_List_Nothing\n");}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 220 "oberon.y"
    {printf("Identifier_List EQ_COMP Type SEMIC Type_List\n");}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 221 "oberon.y"
    {printf("Type_List_Nothing\n");}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 225 "oberon.y"
    {printf("Identifier_List COLON Type SEMIC Var_List\n");}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 226 "oberon.y"
    {printf("Var_List_Nothing\n");}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 233 "oberon.y"
    {printf("Qualident\n");}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 234 "oberon.y"
    {printf("INTEGER\n");}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 235 "oberon.y"
    {printf("CHAR\n");}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 236 "oberon.y"
    {printf("BOOLEAN\n");}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 237 "oberon.y"
    {printf("REAL\n");}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 238 "oberon.y"
    {printf("LONGREAL\n");}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 239 "oberon.y"
    {printf("ARRAY Const_Expr_List OF Type\n");}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 240 "oberon.y"
    {printf("ARRAY OF Type\n");}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 241 "oberon.y"
    {printf("RECORD LEFTBRAC Qualident RIGHTBRAC Field_List END\n");}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 242 "oberon.y"
    {printf("RECORD Field_List END\n");}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 243 "oberon.y"
    {printf("POINTER TO Type\n");}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 244 "oberon.y"
    {printf("PROCEDURE Formal_Pars\n");}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 245 "oberon.y"
    {printf("SET\n");}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 253 "oberon.y"
    {printf("IDENT DOTSYM IDENT\n");}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 259 "oberon.y"
    {printf("Expr\n");}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 263 "oberon.y"
    {printf("Const_Expr COMMA Const_Expr_List\n");}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 264 "oberon.y"
    {printf("Const_Expr\n");}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 269 "oberon.y"
    {printf("Identifier_List COLON Type SEMIC Field_List\n");}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 270 "oberon.y"
    {printf("Identifier_List COLON Type\n");}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 271 "oberon.y"
    {printf("Field_List_Nothing\n");}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 277 "oberon.y"
    {printf("Proc_Decl SEMIC Proc_List\n");}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 278 "oberon.y"
    {printf("Proc_Decl_Nothing\n");}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 282 "oberon.y"
    {printf("PROCEDURE IDENT Formal_Pars SEMIC Decl_Seq Stat_Block END IDENT\n");}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 288 "oberon.y"
    {printf("LEFTBRAC FP_section_List RIGHTBRAC COLON Type\n");}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 289 "oberon.y"
    {printf("LEFTBRAC FP_section_List RIGHTBRAC\n");}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 290 "oberon.y"
    {printf("LEFTBRAC RIGHTBRAC\n");}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 291 "oberon.y"
    {printf("Formal_Pars_nothing\n");}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 295 "oberon.y"
    {printf("FP_section SEMIC FP_section_List");}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 296 "oberon.y"
    {printf("FP_section");}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 300 "oberon.y"
    {printf("Identifier_List COLON Type\n");}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 301 "oberon.y"
    {printf("VAR Identifier_List COLON Type\n");}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 309 "oberon.y"
    {printf("IDENT COMMA Identifier_List\n");}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 314 "oberon.y"
    {(yyval) = makeNode(IDENT, yytext, NOTSET, REF, NULL, NULL); }
    break;



/* Line 1806 of yacc.c  */
#line 2725 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 317 "oberon.y"


void yyerror(const char *s){
    fprintf(stderr, "************************** %s **************************\n", s);
}

int main()
{
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
}



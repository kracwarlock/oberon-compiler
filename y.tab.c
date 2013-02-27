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
#line 39 "oberon.y"


#include<stdio.h>
void yyerror(const char *);
int yylex(void);



/* Line 268 of yacc.c  */
#line 80 "y.tab.c"

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
#line 322 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   638

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  257

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
      32,    34,    37,    38,    42,    45,    49,    51,    59,    66,
      72,    77,    89,    99,   103,   105,   108,   110,   111,   115,
     119,   123,   127,   131,   135,   139,   143,   147,   151,   155,
     159,   163,   167,   171,   175,   177,   179,   181,   183,   185,
     187,   191,   194,   197,   201,   206,   209,   214,   217,   218,
     220,   224,   228,   232,   234,   236,   240,   246,   247,   250,
     251,   253,   257,   261,   262,   264,   268,   270,   274,   277,
     281,   285,   289,   290,   296,   297,   303,   304,   310,   311,
     313,   315,   317,   319,   321,   323,   328,   332,   339,   343,
     347,   350,   352,   354,   358,   360,   364,   366,   372,   376,
     377,   381,   382,   391,   397,   401,   404,   405,   409,   411,
     415,   420,   422
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     102,     0,    -1,   103,   104,    25,    85,     8,    -1,    47,
      85,     3,    -1,   105,   125,   108,    -1,    45,   106,     3,
      -1,    -1,   106,     4,   107,    -1,   107,    -1,    85,    17,
      85,    -1,    85,    -1,    42,   109,    -1,    -1,   110,     3,
     109,    -1,   110,     3,    -1,   113,    17,   111,    -1,   113,
      -1,    27,   111,    28,   109,   119,   120,    25,    -1,    31,
     111,    32,   121,   120,    25,    -1,    26,   111,    24,   109,
      25,    -1,    19,   109,    20,   111,    -1,    21,    85,    17,
     111,    22,   111,    23,   132,    24,   109,    25,    -1,    21,
      85,    17,   111,    22,   111,    24,   109,    25,    -1,    46,
     109,    25,    -1,    44,    -1,    51,   111,    -1,    51,    -1,
      -1,   111,    14,   111,    -1,   111,    15,   111,    -1,   111,
      91,   111,    -1,   111,    90,   111,    -1,   111,    89,   111,
      -1,   111,    88,   111,    -1,   111,    87,   111,    -1,   111,
      86,   111,    -1,   111,    94,   111,    -1,   111,    93,   111,
      -1,   111,    92,   111,    -1,   111,   100,   111,    -1,   111,
      99,   111,    -1,   111,    98,   111,    -1,   111,    97,   111,
      -1,   111,    96,   111,    -1,   112,    -1,   113,    -1,    82,
      -1,    81,    -1,    48,    -1,   116,    -1,     7,   111,     6,
      -1,    16,   112,    -1,    85,   114,    -1,     8,    85,   114,
      -1,     9,   115,    10,   114,    -1,    13,   114,    -1,     7,
     115,     6,   114,    -1,     7,     6,    -1,    -1,   111,    -1,
     111,     4,   115,    -1,    11,   117,    12,    -1,   118,     4,
     117,    -1,   118,    -1,   111,    -1,   111,    18,   111,    -1,
      29,   111,    28,   109,   119,    -1,    -1,    30,   109,    -1,
      -1,   122,    -1,   122,    95,   121,    -1,   123,     5,   109,
      -1,    -1,   124,    -1,   124,     4,   123,    -1,   111,    -1,
     111,    18,   111,    -1,   126,   135,    -1,    43,   127,   126,
      -1,    52,   128,   126,    -1,    53,   129,   126,    -1,    -1,
     140,    14,   132,     3,   127,    -1,    -1,   140,    14,   130,
       3,   128,    -1,    -1,   140,     5,   130,     3,   129,    -1,
      -1,   131,    -1,    77,    -1,    76,    -1,    75,    -1,    79,
      -1,    78,    -1,    39,   133,    32,   130,    -1,    39,    32,
     130,    -1,    40,     7,   131,     6,   134,    25,    -1,    40,
     134,    25,    -1,    49,    22,   130,    -1,    50,   137,    -1,
      41,    -1,    85,    -1,    85,     8,    85,    -1,   111,    -1,
     132,     4,   133,    -1,   132,    -1,   140,     5,   130,     3,
     134,    -1,   140,     5,   130,    -1,    -1,   136,     3,   135,
      -1,    -1,    50,    85,   137,     3,   125,   108,    25,    85,
      -1,     7,   138,     6,     5,   130,    -1,     7,   138,     6,
      -1,     7,     6,    -1,    -1,   139,     3,   138,    -1,   139,
      -1,   140,     5,   130,    -1,    53,   140,     5,   130,    -1,
      85,    -1,    85,     4,   140,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    56,    60,    64,    65,    69,    70,    74,
      75,    79,    80,    84,    85,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   106,   107,
     108,   109,   110,   111,   112,   113,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   128,   129,   130,   131,   132,
     133,   134,   138,   142,   143,   144,   145,   146,   147,   151,
     152,   156,   160,   161,   165,   166,   170,   171,   175,   176,
     180,   181,   185,   186,   190,   191,   195,   196,   204,   208,
     209,   210,   211,   218,   219,   223,   224,   228,   229,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   252,   253,   257,   261,   262,   267,   268,   269,
     275,   276,   280,   286,   287,   288,   289,   293,   294,   298,
     299,   303,   304
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
  "Import_Modules", "Import_Modules_List", "Import", "Stat_Block",
  "Statement_Sequence", "Statement", "Expr", "Factor", "Designator",
  "optSuffix", "Expr_List", "Set", "Element_List", "Element",
  "Else_If_Block", "Else", "Case_Parameters", "Case_Single",
  "Case_Expression_List", "Case_Expression", "Decl_Seq", "Data_List",
  "Const_List", "Type_List", "Var_List", "Type", "Qualident", "Const_Expr",
  "Const_Expr_List", "Field_List", "Proc_List", "Proc_Decl", "Formal_Pars",
  "FP_section_List", "FP_section", "Identifier_List", 0
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
     107,   108,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   113,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   133,   133,   134,   134,   134,
     135,   135,   136,   137,   137,   137,   137,   138,   138,   139,
     139,   140,   140
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     3,     3,     0,     3,     1,     3,
       1,     2,     0,     3,     2,     3,     1,     7,     6,     5,
       4,    11,     9,     3,     1,     2,     1,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     3,     4,     2,     4,     2,     0,     1,
       3,     3,     3,     1,     1,     3,     5,     0,     2,     0,
       1,     3,     3,     0,     1,     3,     1,     3,     2,     3,
       3,     3,     0,     5,     0,     5,     0,     5,     0,     1,
       1,     1,     1,     1,     1,     4,     3,     6,     3,     3,
       2,     1,     1,     3,     1,     3,     1,     5,     3,     0,
       3,     0,     8,     5,     3,     2,     0,     3,     1,     3,
       4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     0,     1,     0,     0,    82,     3,
      10,     0,     8,     0,    84,    86,    88,    12,   111,     0,
       5,     0,     0,   121,    82,     0,    82,     0,    82,     0,
      27,     4,     0,    78,     0,     9,     7,     2,     0,    79,
       0,    80,     0,    81,     0,    27,     0,     0,     0,     0,
      24,    27,    26,    58,    11,     0,    16,   116,   111,   122,
       0,     0,     0,    48,    47,    46,   104,    44,    45,    49,
       0,     0,   109,   101,     0,   116,    92,    91,    90,    94,
      93,   102,     0,    89,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    58,    52,    14,     0,     0,
       0,   110,     0,    64,     0,    63,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,   106,     0,     0,     0,     0,
       0,   100,     0,    86,    88,     0,     0,    27,    27,    73,
      23,    57,    59,     0,    58,     0,    55,    13,    15,   115,
       0,     0,   118,     0,    82,    50,     0,    61,     0,    28,
      29,    35,    34,    33,    32,    31,    30,    38,    37,    36,
      43,    42,    41,    40,    39,    83,    96,     0,     0,     0,
      98,     0,    99,   103,    85,    87,    20,     0,     0,    67,
      76,    69,    70,     0,    74,     0,    58,    53,    58,     0,
     114,     0,     0,    12,    65,    62,   105,    95,   109,   108,
       0,    19,     0,    69,     0,    27,     0,    73,    27,     0,
      60,    56,    54,     0,     0,   117,   119,     0,     0,   109,
       0,     0,     0,    77,    68,    18,    71,    72,    75,   120,
     113,     0,    97,   107,     0,    27,    27,    17,   112,     0,
       0,    67,    27,    22,    66,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    11,    12,    31,    54,    55,
      66,    67,    68,    96,   143,    69,   104,   105,   213,   216,
     191,   192,   193,   194,    17,    18,    24,    26,    28,    82,
      83,   125,   126,   128,    33,    34,   100,   151,   152,   129
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -198
static const yytype_int16 yypact[] =
{
     -28,   -63,    28,   -15,    30,  -198,   -51,    13,   -29,  -198,
      18,    22,  -198,   -42,   -40,   -40,   -40,     5,     1,   -33,
    -198,   -51,    52,    58,   -29,    49,   -29,    51,   -29,    61,
     544,  -198,   -17,  -198,    66,  -198,  -198,  -198,   -40,  -198,
     553,  -198,   224,  -198,   224,   544,   -13,   553,   553,   553,
    -198,   544,   553,    67,  -198,    70,    60,    75,     1,  -198,
     553,   553,   553,  -198,  -198,  -198,   444,  -198,  -198,  -198,
      80,    39,    -1,  -198,    63,    75,  -198,  -198,  -198,  -198,
    -198,    78,    86,  -198,    87,    71,    88,   255,   283,   299,
      72,   444,    33,    19,   553,    67,  -198,    10,   553,    11,
     103,  -198,    64,   342,   101,   112,  -198,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   -40,   224,   113,    93,    34,   102,   121,
     224,  -198,    43,   -40,   -40,   553,   553,   544,   544,   553,
    -198,  -198,    44,   123,    67,   135,  -198,  -198,   444,  -198,
     -40,   141,   145,   154,   -29,  -198,   553,  -198,   553,   459,
     459,   459,   459,   459,   459,   459,   459,     3,     3,     3,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,   553,   224,   159,
    -198,   224,  -198,  -198,  -198,  -198,   444,   314,   148,   137,
     401,   146,    82,   170,   174,   553,    67,  -198,    67,   177,
     178,   -43,   224,     5,   444,  -198,  -198,  -198,   -40,   176,
     553,  -198,   553,   146,   553,   544,   161,   553,   544,   553,
    -198,  -198,  -198,   224,   224,  -198,  -198,   162,   164,   -40,
     196,   429,   168,   444,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,    99,  -198,  -198,   553,   544,   544,  -198,  -198,   171,
     169,   137,   544,  -198,  -198,   172,  -198
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,  -198,  -198,  -198,  -198,   175,    -5,   -44,  -198,
     120,   138,   -30,   -87,   -85,  -198,    41,  -198,   -48,    -9,
     -12,  -198,   -10,  -198,    53,    -8,    90,    84,    89,   -32,
      94,   -38,    47,  -197,   167,  -198,   151,    42,  -198,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      56,    85,    70,    25,    27,    29,   127,    90,   146,   145,
     150,   228,    84,   -27,    14,    56,    39,   149,    41,     1,
      43,    56,     4,    15,    16,    20,    21,    59,     5,    45,
       6,    46,   243,     9,    10,    19,    47,    48,    13,   141,
      60,    49,    23,    22,    61,    23,    60,    30,   195,    62,
      61,    32,    35,   147,    50,    62,    51,   197,   107,   108,
      37,    52,    38,    40,   150,    42,    44,    56,    57,    58,
     155,   124,    86,    97,    92,    93,    94,    98,   107,   108,
      95,    63,    99,   123,    23,   130,   132,    63,   153,   133,
     134,   135,   176,   188,   189,    53,    23,   140,   182,   118,
     119,   120,   121,   122,   144,   136,   154,    56,    56,   221,
     220,   222,    25,   157,    64,    65,   158,   177,    53,    81,
      64,    65,    27,    29,    53,   178,   181,   180,   183,   196,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   199,
     118,   119,   120,   121,   122,   198,   207,   200,   201,   209,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   202,
     118,   119,   120,   121,   122,   208,   212,    87,    88,    89,
     226,   234,    91,   211,   237,   218,   215,   217,   219,   229,
     102,   103,   223,   224,   248,    56,   235,   241,    56,   242,
     153,   239,   240,   247,   253,   252,    36,   256,   227,   205,
     106,   250,   251,   254,   232,   236,   249,   203,   255,   238,
     107,   108,   142,   175,   142,    56,    56,   184,   148,   244,
     245,   179,    56,   185,   206,   101,   131,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   187,     0,     0,   190,
       0,     0,     0,    71,    72,    73,     0,     0,     0,   107,
     108,     0,     0,    74,    75,     0,   204,     0,   103,   137,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,   120,   121,   122,   107,   108,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,    81,
       0,   138,     0,   107,   108,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     230,   139,   231,     0,   233,     0,   210,   190,     0,   190,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,   120,   121,   122,   107,   108,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   118,
     119,   120,   121,   122,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,   120,   121,   122,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,   120,   121,   122,   107,   108,     0,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
     120,   121,   122,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -28,   -28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,   120,   121,   122,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,   120,   121,   122,   -28,   -28,   -28,   -28,   -28,
     -28,   115,   116,   117,     0,   118,   119,   120,   121,   122,
      60,     0,     0,    45,    61,    46,     0,     0,     0,    62,
      47,    48,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,    64,    65,     0,     0,    53
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-198))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-28))

static const yytype_int16 yycheck[] =
{
      30,    45,    40,    14,    15,    16,     7,    51,    95,    94,
      53,   208,    44,     3,    43,    45,    24,     6,    26,    47,
      28,    51,    85,    52,    53,     3,     4,    38,     0,    19,
      45,    21,   229,     3,    85,    17,    26,    27,    25,     6,
       7,    31,    85,    85,    11,    85,     7,    42,     4,    16,
      11,    50,    85,    97,    44,    16,    46,   144,    14,    15,
       8,    51,     4,    14,    53,    14,     5,    97,    85,     3,
       6,    32,    85,     3,     7,     8,     9,    17,    14,    15,
      13,    48,     7,     3,    85,    22,     8,    48,    99,     3,
       3,    20,   124,   137,   138,    85,    85,    25,   130,    96,
      97,    98,    99,   100,    85,    17,     3,   137,   138,   196,
     195,   198,   123,    12,    81,    82,     4,     4,    85,    85,
      81,    82,   133,   134,    85,    32,     5,    25,    85,     6,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   150,
      96,    97,    98,    99,   100,    10,   178,     6,     3,   181,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     5,
      96,    97,    98,    99,   100,     6,    29,    47,    48,    49,
     202,   215,    52,    25,   218,     5,    30,    95,     4,     3,
      60,    61,     5,     5,    85,   215,    25,    25,   218,    25,
     201,   223,   224,    25,    25,    24,    21,    25,   203,   158,
      62,   245,   246,   251,   213,   217,   244,   154,   252,   219,
      14,    15,    92,   123,    94,   245,   246,   133,    98,    23,
      24,   127,   252,   134,   177,    58,    75,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,    14,
      15,    -1,    -1,    49,    50,    -1,   156,    -1,   158,    24,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,   100,    14,    15,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    28,    -1,    14,    15,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
     210,    32,   212,    -1,   214,    -1,    22,   217,    -1,   219,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,   100,    14,    15,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,   100,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    14,    15,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,   100,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,   100,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,   100,
       7,    -1,    -1,    19,    11,    21,    -1,    -1,    -1,    16,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      46,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,   102,   103,    85,     0,    45,   104,   105,     3,
      85,   106,   107,    25,    43,    52,    53,   125,   126,    17,
       3,     4,    85,    85,   127,   140,   128,   140,   129,   140,
      42,   108,    50,   135,   136,    85,   107,     8,     4,   126,
      14,   126,    14,   126,     5,    19,    21,    26,    27,    31,
      44,    46,    51,    85,   109,   110,   113,    85,     3,   140,
       7,    11,    16,    48,    81,    82,   111,   112,   113,   116,
     132,    39,    40,    41,    49,    50,    75,    76,    77,    78,
      79,    85,   130,   131,   130,   109,    85,   111,   111,   111,
     109,   111,     7,     8,     9,    13,   114,     3,    17,     7,
     137,   135,   111,   111,   117,   118,   112,    14,    15,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   100,     3,    32,   132,   133,     7,   134,   140,
      22,   137,     8,     3,     3,    20,    17,    24,    28,    32,
      25,     6,   111,   115,    85,   115,   114,   109,   111,     6,
      53,   138,   139,   140,     3,     6,    18,    12,     4,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   127,   130,     4,    32,   131,
      25,     5,   130,    85,   128,   129,   111,   111,   109,   109,
     111,   121,   122,   123,   124,     4,     6,   114,    10,   140,
       6,     3,     5,   125,   111,   117,   133,   130,     6,   130,
      22,    25,    29,   119,    18,    30,   120,    95,     5,     4,
     115,   114,   114,     5,     5,   138,   130,   108,   134,     3,
     111,   111,   120,   111,   109,    25,   121,   109,   123,   130,
     130,    25,    25,   134,    23,    24,    28,    25,    85,   132,
     109,   109,    24,    25,   119,   109,    25
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
#line 52 "oberon.y"
    {printf("start \n");}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 56 "oberon.y"
    {printf("Module\n");}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 60 "oberon.y"
    {printf("Import_Modules Decl_Seq Stat_Block\n");}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 64 "oberon.y"
    {printf("IMPORT Import_Modules_List SEMIC\n");}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 65 "oberon.y"
    {printf("IMPORT Import_Modules_List SEMIC_nothing\n");}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 69 "oberon.y"
    {printf("Import_Modules_List COMMA Import\n");}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 70 "oberon.y"
    {printf("Import\n");}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 74 "oberon.y"
    {printf("IDENT ASSIGN IDENT\n");}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 75 "oberon.y"
    {printf("IDENT\n");}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 79 "oberon.y"
    {printf("BEG Statement_Sequence\n");}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 80 "oberon.y"
    {printf("BEG Statement_Sequence_Nothing\n");}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 84 "oberon.y"
    {printf("Statement SEMIC Statement_Sequence\n");}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 85 "oberon.y"
    {printf("Statement SEMIC\n");}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 89 "oberon.y"
    {printf(" Designator ASSIGN Expr \n");}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 90 "oberon.y"
    {printf(" Designator\n");}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 91 "oberon.y"
    {printf(" IF_COND Expr THEN Statement_Sequence Else_If_Block Else END\n");}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 92 "oberon.y"
    {printf(" CASE_COND Expr OF Case_Parameters Else END \n");}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 93 "oberon.y"
    {printf("WHILE Expr DOCASE Statement_Sequence END\n");}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 94 "oberon.y"
    {printf("REPEAT Statement_Sequence UNTIL Expr\n");}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 95 "oberon.y"
    {printf(" FOR IDENT ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END\n");}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 96 "oberon.y"
    {printf("FOR IDENT ASSIGN Expr TO Expr DOCASE Statement_Sequence END\n");}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 97 "oberon.y"
    {printf("LOOP Statement_Sequence END\n");}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 98 "oberon.y"
    {printf(" EXIT\n");}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 99 "oberon.y"
    {printf(" RETURN Expr\n");}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 100 "oberon.y"
    {printf(" RETURN\n");}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 101 "oberon.y"
    {printf(" stat_nothing\n");}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 106 "oberon.y"
    {printf("Expr EQ_COMP Expr\n");}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 107 "oberon.y"
    {printf(" Expr UNEQ Expr\n");}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 108 "oberon.y"
    {printf(" Expr LT Expr\n");}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 109 "oberon.y"
    {printf(" Expr LE Expr\n");}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 110 "oberon.y"
    {printf(" Expr GT Expr\n");}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 111 "oberon.y"
    {printf(" Expr GE Expr\n");}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 112 "oberon.y"
    {printf(" Expr IN Expr\n");}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 113 "oberon.y"
    {printf(" Expr IS Expr\n");}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 116 "oberon.y"
    {printf("Expr PLUS_SYM Expr\n");}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 117 "oberon.y"
    {printf("Expr MINUS_SYM Expr\n");}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 118 "oberon.y"
    {printf("Expr OR Expr\n");}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 119 "oberon.y"
    {printf("Expr MULTIPLY_SYM Expr\n");}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 120 "oberon.y"
    {printf("Expr DIVIDE_SYM Expr\n");}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 121 "oberon.y"
    {printf("Expr DIV Expr\n");}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 122 "oberon.y"
    {printf("Expr MOD Expr\n");}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 123 "oberon.y"
    {printf("Expr AND_SYM Expr\n");}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 124 "oberon.y"
    {printf("Factor\n");}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 128 "oberon.y"
    {printf("Designator\n");}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 129 "oberon.y"
    {printf("integer val is %d",(yyvsp[(1) - (1)]));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 130 "oberon.y"
    {printf("CHAR_VAL\n");}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 131 "oberon.y"
    {printf("NIL\n");}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 132 "oberon.y"
    {printf("Set\n");}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 133 "oberon.y"
    {printf("LEFTBRAC Expr RIGHTBRAC\n");}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 134 "oberon.y"
    {printf("TILDA Factor\n");}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 138 "oberon.y"
    {printf("IDENT optSuffix\n");}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 142 "oberon.y"
    {printf("DOTSYM IDENT  optSuffix\n");}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 143 "oberon.y"
    {printf("LSQBR Expr_List RSQBR  optSuffix\n");}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 144 "oberon.y"
    {printf("CARR  optSuffix\n");}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 145 "oberon.y"
    {printf("LEFTBRAC Expr_List RIGHTBRAC optSuffix\n");}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 146 "oberon.y"
    {printf("LEFTBRAC RIGHTBRAC\n");}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 147 "oberon.y"
    {printf("optSuffix_Nothing\n");}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 151 "oberon.y"
    {printf("Expr\n");}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 152 "oberon.y"
    {printf("Expr COMMA Expr_List\n");}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 156 "oberon.y"
    {printf("LCBR Element_List RCBR\n");}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 160 "oberon.y"
    {printf("Element COMMA Element_List\n");}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 161 "oberon.y"
    {printf("Element\n");}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 165 "oberon.y"
    {printf("Expr\n");}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 166 "oberon.y"
    {printf("Expr DOTDOT Expr\n");}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 170 "oberon.y"
    {printf("ELSEIF Expr THEN Statement_Sequence Else_If_Block\n");}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 171 "oberon.y"
    {printf("Else_If_Block_Nothing\n");}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 175 "oberon.y"
    {printf("ELSE Statement_Sequence\n");}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 176 "oberon.y"
    {printf("Else_Nothing\n");}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 180 "oberon.y"
    {printf("Case_Single\n");}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 181 "oberon.y"
    {printf("Case_Single OR_SYM Case_Parameters\n");}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 185 "oberon.y"
    {printf("Case_Expression_List COLON Statement_Sequence\n");}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 186 "oberon.y"
    {printf("Case_Single_Nothing\n");}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 190 "oberon.y"
    {printf("Case_Expression\n");}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 191 "oberon.y"
    {printf("Case_Expression COMMA Case_Expression_List\n");}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 195 "oberon.y"
    {printf("Expr\n");}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 196 "oberon.y"
    {printf("Expr DOTDOT Expr\n");}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 204 "oberon.y"
    {printf("Data_List Proc_List\n");}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 208 "oberon.y"
    {printf("CONST Const_List Data_List\n");}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 209 "oberon.y"
    {printf("TYPE  Type_List  Data_List\n");}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 210 "oberon.y"
    {printf("VAR   Var_List Data_List\n");}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 211 "oberon.y"
    {printf("Data_List_Nothing\n");}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 218 "oberon.y"
    {printf("Identifier_List EQ_COMP Const_Expr SEMIC Const_List\n");}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 219 "oberon.y"
    {printf("Const_List_Nothing\n");}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 223 "oberon.y"
    {printf("Identifier_List EQ_COMP Type SEMIC Type_List\n");}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 224 "oberon.y"
    {printf("Type_List_Nothing\n");}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 228 "oberon.y"
    {printf("Identifier_List COLON Type SEMIC Var_List\n");}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 229 "oberon.y"
    {printf("Var_List_Nothing\n");}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 236 "oberon.y"
    {printf("Qualident\n");}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 237 "oberon.y"
    {printf("INTEGER\n");}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 238 "oberon.y"
    {printf("CHAR\n");}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 239 "oberon.y"
    {printf("BOOLEAN\n");}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 240 "oberon.y"
    {printf("REAL\n");}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 241 "oberon.y"
    {printf("LONGREAL\n");}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 242 "oberon.y"
    {printf("ARRAY Const_Expr_List OF Type\n");}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 243 "oberon.y"
    {printf("ARRAY OF Type\n");}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 244 "oberon.y"
    {printf("RECORD LEFTBRAC Qualident RIGHTBRAC Field_List END\n");}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 245 "oberon.y"
    {printf("RECORD Field_List END\n");}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 246 "oberon.y"
    {printf("POINTER TO Type\n");}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 247 "oberon.y"
    {printf("PROCEDURE Formal_Pars\n");}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 248 "oberon.y"
    {printf("SET\n");}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 252 "oberon.y"
    {printf("IDENT\n");}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 253 "oberon.y"
    {printf("IDENT DOTSYM IDENT\n");}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 257 "oberon.y"
    {printf("Expr\n");}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 261 "oberon.y"
    {printf("Const_Expr COMMA Const_Expr_List\n");}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 262 "oberon.y"
    {printf("Const_Expr\n");}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 267 "oberon.y"
    {printf("Identifier_List COLON Type SEMIC Field_List\n");}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 268 "oberon.y"
    {printf("Identifier_List COLON Type\n");}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 269 "oberon.y"
    {printf("Field_List_Nothing\n");}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 275 "oberon.y"
    {printf("Proc_Decl SEMIC Proc_List\n");}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 276 "oberon.y"
    {printf("Proc_Decl_Nothing\n");}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 280 "oberon.y"
    {printf("PROCEDURE IDENT Formal_Pars SEMIC Decl_Seq Stat_Block END IDENT\n");}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 286 "oberon.y"
    {printf("LEFTBRAC FP_section_List RIGHTBRAC COLON Type\n");}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 287 "oberon.y"
    {printf("LEFTBRAC FP_section_List RIGHTBRAC\n");}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 288 "oberon.y"
    {printf("LEFTBRAC RIGHTBRAC\n");}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 289 "oberon.y"
    {printf("Formal_Pars_nothing\n");}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 293 "oberon.y"
    {printf("FP_section SEMIC FP_section_List");}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 294 "oberon.y"
    {printf("FP_section");}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 298 "oberon.y"
    {printf("Identifier_List COLON Type\n");}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 299 "oberon.y"
    {printf("VAR Identifier_List COLON Type\n");}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 303 "oberon.y"
    {printf("IDENT\n");}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 304 "oberon.y"
    {printf("IDENT COMMA Identifier_List\n");}
    break;



/* Line 1806 of yacc.c  */
#line 2715 "y.tab.c"
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
#line 308 "oberon.y"


void yyerror(const char *s){
    fprintf(stderr, "************************** %s **************************\n", s);
}

int main()
{
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
}



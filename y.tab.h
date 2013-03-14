/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;



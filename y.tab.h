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
     ARRAY = 293,
     RECORD = 294,
     SET = 295,
     BEG = 296,
     CONST = 297,
     EXIT = 298,
     IMPORT = 299,
     LOOP = 300,
     MODULE = 301,
     NIL = 302,
     POINTER = 303,
     PROCEDURE = 304,
     RETURN = 305,
     TYPE = 306,
     VAR = 307,
     WITH = 308,
     ABS = 309,
     ODD = 310,
     LEN = 311,
     LSL = 312,
     ASR = 313,
     ROR = 314,
     FLOOR = 315,
     FLT = 316,
     ORD = 317,
     CHR = 318,
     LONG = 319,
     SHORT = 320,
     INC = 321,
     DEC = 322,
     INCL = 323,
     EXCL = 324,
     COPY = 325,
     NEW = 326,
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
#define ARRAY 293
#define RECORD 294
#define SET 295
#define BEG 296
#define CONST 297
#define EXIT 298
#define IMPORT 299
#define LOOP 300
#define MODULE 301
#define NIL 302
#define POINTER 303
#define PROCEDURE 304
#define RETURN 305
#define TYPE 306
#define VAR 307
#define WITH 308
#define ABS 309
#define ODD 310
#define LEN 311
#define LSL 312
#define ASR 313
#define ROR 314
#define FLOOR 315
#define FLT 316
#define ORD 317
#define CHR 318
#define LONG 319
#define SHORT 320
#define INC 321
#define DEC 322
#define INCL 323
#define EXCL 324
#define COPY 325
#define NEW 326
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



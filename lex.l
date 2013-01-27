%{
	# include "y.tab.h"
	# include <stdio.h>
	# include <stdlib.h>
	# include <string.h>
	/* definitions of manifest constants	
	*/
%}

/* regular definitions */
digit		[0-9]
letter		[A-Za-z]
hexdigit	[0-9A-F]

BOOLEAN		"TRUE"|"FALSE"
CHAR		[.\n]|digit{hexdigit}"X"
INTEGER		{digit}+
REAL		{INTEGER}"."{digit}*
LONGREAL	{INTEGER}"."{digit}*
STRING		"""{char}*"""
SET
IDENT		letter{letter|digit}

%%

"="		{return EQ_COMP;}
"#"		{return UNEQ;}
"<"		{return LT;}
"<="		{return LE;}
">"		{return GT;}
">="		{return GE;}
"IN"		{return IN;}
"IS"		{return IS;}

"+"		{return PLUS_SYM;}
"-"		{return MINUS_SYM;}
"*"		{return MULTIPLY_SYM;}
"/"		{return DIVIDE_SYM;}
"DIV"		{return DIV;}
"MOD"		{return MOD;}

"OR"		{return OR_SYM;}
"&"		{return AND_SYM;}
"∼"		{return TILDA;}

":="		{return ASSIGN;}

"REPEAT"	{return REPEAT;}
"UNTIL"		{return UNTIL;}
"FOR"		{return FOR;}
"TO"		{return TO;}
"BY"		{return BY;}
"DO"		{return DOCASE;}
"END"		{return END;}
"WHILE"		{return WHILE;}
"IF"		{return IF_COND;}
"THEN"		{return THEN;}
"ELSIF"		{return ELSEIF;}
"ELSE"		{return ELSE;}
"CASE"		{return CASE_COND;}
"OF"		{return OF;}

"STRLEN"	{return STRLEN;}
"STRCAT"	{return STRCAT;}
"STRCPY"	{return STRCPY;}
"STRREV"	{return STRREV;}
"STRCMP"	{return STRCMP;}

"TRUE"		{return TRUE;}
"FALSE"		{return FALSE;}

{BOOLEAN}
{CHAR}		{return CHAR;}
{INTEGER}	{return INT;}
{REAL}		{return REAL;}
{LONGREAL}	{return LONGREAL;}
{STRING}	{return STRING;}
{IDENT}		{return IDENT;}

"(*"		{}
[\t]		{}
[\r\n]		{}

ARRAY
begin***
CONST
EXIT
IMPORT
LOOP                                                                                                                                              
MODULE
NIL
OR
POINTER
PROCEDURE
RETURN
TYPE
VAR
WITH

%%

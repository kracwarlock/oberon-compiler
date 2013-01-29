%{
	# include "y.tab.h"
	# include <stdio.h>
	# include <stdlib.h>
	# include <string.h>
	/* definitions of manifest constants	
	*/
	extern int yylineno = 0;
	void yyerror(const char *s);
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

[ \t]		{;}
[\r\n]		{yylineno++;}

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

{BOOLEAN}	{return BOOLEAN;}
{CHAR}		{return CHAR;}
{INTEGER}	{return INT;}
{REAL}		{return REAL;}
{LONGREAL}	{return LONGREAL;}
{STRING}	{return STRING;}
{IDENT}		{return IDENT;}

"(*"		{doComments();}

ARRAY		{return ARRAY;}
BEGIN		{return BEG;}
CONST		{return CONST;}
EXIT		{return EXIT;}
IMPORT		{return IMPORT;}
LOOP		{return LOOP;}
MODULE		{return MODULE;}
NIL		{return NIL;}
OR		{return OR;}
POINTER		{return POINTER;}
PROCEDURE	{return PROCEDURE;}
RETURN		{return RETURN;}
TYPE		{return TYPE;}
VAR		{return VAR;}
WITH		{return WITH;}

%%

void yyerror(const char *s)
{
	
}

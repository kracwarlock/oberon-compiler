%{
	# include "y.tab.h"
	# include <stdio.h>
	# include <stdlib.h>
	# include <string.h>
	/* definitions of manifest constants
		TRUE, FALSE
	*/
%}

/* regular definitions */
digit		[0-9]
letter		[A-Za-z]
boolean
hexdigit	[0-9A-F]
char		[.\n]|digit{hexdigit}"X"
integer		{digit}+
real		{integer}"."{digit}*
longreal	{integer}"."{digit}*
string		"""{char}*"""
set
ident		letter{letter|digit}

%%

"="			{return EQ_COMP;}
"#"			{return UNEQ;}
"<"			{return LT;}
"<="		{return LE;}
">"			{return GT;}
">="		{return GE;}
"IN"		{return IN;}
"IS"		{return IS;}
relation	{}

"+"			{return PLUS_SYM;}
"-"			{return MINUS_SYM;}
"*"			{return MULTIPLY_SYM;}
"/"			{return DIVIDE_SYM;}
"DIV"		{return DIV;}
"MOD"		{return MOD;}

"OR"		{return OR_SYM;}
"&"			{return AND_SYM;}
"∼"			{return TILDA;}

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
"CASE"		{return CASE_COND;}
"OF"		{return OF;}

"STRLEN"	{return STRLEN;}
"STRCAT"	{return STRCAT;}
"STRCPY"	{return STRCPY;}
"STRREV"	{return STRREV;}
"STRCMP"	{return STRCMP;}

{char}		{return CHAR;}
{integer}	{return INT;}
{real}		{return REAL;}
{longreal}	{return LONGREAL;}
{string}	{return STRING;}
{ident}		{return IDENT;}

"(*"
[\t]
[\r\n]

array
begin***
const
else
exit
import
loop
module
nil
or
pointer
procedure
return
type
var
with

%%

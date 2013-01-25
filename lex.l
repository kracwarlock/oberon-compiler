%{
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

"="		{return EQ;}
"#"		{return UNEQ;}
"<"		{return LT;}
"<="		{return LE;}
">"		{return GT;}
">="		{return GE;}
"IN"		{return IN;}
"IS"		{return IS;}
relation	{}

"+"		{return PLUS_SYM;}
"-"		{return MINUS_SYM;}
"*"		{return MULTIPLY_SYM;}
"/"		{return DIVIDE_SYM;}
"DIV"		{return DIV;}
"MOD"		{return MOD;}

"OR"		{return OR;}
"&"		{return AND_SYM;}
"∼"		{return TILDA;}

":="		{return ASSIGN;}

"REPEAT"	{}
"UNTIL"		{}
"FOR"		{}
"TO"		{}
"BY"		{}
"DO"		{}
"END"		{}
"WHILE"		{}
"IF"		{}
"THEN"		{}
"ELSIF"		{}
"CASE"		{}
"OF"		{}

"STRLEN"	{}
"STRCAT"	{}
"STRCPY"	{}
"STRREV"	{}
"STRCMP"	{}

"(*"
[\t]
[\r\n]

{char}		{return ;}
{integer}	{return ;}
{real}		{return ;}
{longreal}	{return ;}
{string}	{return ;}
{ident}		{return ;}

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

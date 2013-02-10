%{
	# include <stdio.h>
	# include <stdlib.h>
	# include <string.h>
	# include "y.tab.h"
	/* definitions of manifest constants	
	*/
	void yyerror(const char *s);
	void AvoidComments();

%}

/* regular definitions */
digit		[0-9]
letter		[A-Za-z]
hexdigit	[0-9A-Fa-f]

BOOLEAN		"TRUE"|"FALSE"
CHAR		(([0]{hexdigit}{hexdigit}"X")|([0]{hexdigit}"X"))
INTEGER		{digit}+
REAL		{INTEGER}"."{digit}+
STRING		["][^"]*["]
IDENT		{letter}({letter}|{digit})*

%%

"="		{
			return EQ_COMP;
		}
"#"		{
			printf(" HASH (%s) ",yytext);
			return UNEQ;
		}
"<"		{
			printf(" LESS THAN (%s) ",yytext);
			return LT;
		}
"<="		{
			printf(" LESS THAN EQUAL (%s) ",yytext);
			return LE;
		}

">"		{
			printf(" GREATER (%s) ",yytext);
			return GT;
		}
">="		{
			printf(" GREATER THAN EQUAL (%s) ",yytext);
			return GE;
		}
"IN"		{
			printf(" IN (%s) ",yytext);
			return IN;
		}
"IS"		{
			printf(" IS (%s) ",yytext);
			return IS;
		}

"+"		{
			printf(" PLUS (%s) ",yytext);
			return PLUS_SYM;
		}
"-"		{
			printf(" MINUS (%s) ",yytext);
			return MINUS_SYM;
		}
"*"		{
			printf(" MULTIPLY (%s) ",yytext);
			return MULTIPLY_SYM;
		}
"/"		{
			printf(" DIVIDE (%s) ",yytext);
			return DIVIDE_SYM;
		}
"DIV"		{
			printf(" DIVISION (%s) ",yytext);
			return DIV;
		}
"MOD"		{
			printf(" MODULUS (%s) ",yytext);
			return MOD;
		}

"OR"		{
			printf(" OR|| (%s) ",yytext);
			return OR_SYM;
		}
"&"		{
			printf(" AND (%s) ",yytext);
			return AND_SYM;
		}
"∼"		{
			printf(" TILDA (%s) ",yytext);
			return TILDA;
		}
":="		{
			printf(" ASSIGNMENT (%s) ",yytext);
			return ASSIGN;
		}
".."		{
			printf(" DOTDOT (%s) ",yytext);
			return DOTDOT;
		}

[ \t]		{;}

[\r\n]		{	
			printf("\n");
			printf("Tokenizing Line: %d ---- ",yylineno+1);
			yylineno++;
		}

"REPEAT"	{
			printf(" REPEATT (%s) ",yytext);
			return REPEAT;
		}
"UNTIL"		{	
			printf(" UNTILT (%s) ",yytext);
			return UNTIL;
		}
"FOR"		{
			printf(" FOR Token (%s) ",yytext);
			return FOR;
		}
"TO"		{	
			printf(" TO Token (%s) ",yytext);
			return TO;
		}
"BY"		{
			printf(" BY Token (%s) ",yytext);
			return BY;
		}
"DO"		{
			printf(" DO Token (%s) ",yytext);
			return DOCASE;
		}
"END"		{
			printf(" END Token (%s) ",yytext);
			return END;
		}
"WHILE"		{	
			printf(" WHILE Token (%s) ",yytext);
			return WHILE;
		}
"IF"		{
			printf(" IF Token (%s) ",yytext);
			return IF_COND;
		}
"THEN"		{	
			printf(" THEN Token (%s) ",yytext);
			return THEN;
		}
"ELSIF"		{
			printf(" ELSE IF Token (%s) ",yytext);
			return ELSEIF;
		}
"ELSE"		{
			printf(" ELSE Token (%s) ",yytext);
			return ELSE;
		}
"CASE"		{	
			printf(" CASE Token (%s) ",yytext);
			return CASE_COND;
		}
"OF"		{	
			printf(" OF Token (%s) ",yytext);
			return OF;
		}

"STRLEN"	{
			printf(" STRLEN Token (%s) ",yytext);
			return STRLEN;
		}
"STRCAT"	{
			printf(" STRCAT Token (%s) ",yytext);
			return STRCAT;
		}
"STRCPY"	{
			printf(" STRCPY TOken (%s) ",yytext);
			return STRCPY;
		}
"STRREV"	{
			printf(" STRREV Token (%s) ",yytext);
			return STRREV;
		}
"STRCMP"	{	
			printf(" STRCMP Token (%s) ",yytext);
			return STRCMP;
		}
"(*"		{
			AvoidComments();
			printf(" COMMENT ");
		}

"ARRAY"		{	
			printf(" ARRAY Token (%s) ",yytext);
			return ARRAY;
		}
"RECORD"	{	
			printf(" RECORD Token (%s) ",yytext);
			return RECORD;
		}
"SET"		{	
			printf(" SET Token (%s) ",yytext);
			return SET;
		}
"BEGIN"		{
			printf(" BEGIN Token (%s) ",yytext);
			return BEG;
		}
"CONST"		{	
			printf(" CONST Token (%s) ",yytext);
			return CONST;
		}
"EXIT"		{
			printf(" EXIT Token (%s) ",yytext);
			return EXIT;
		}
"IMPORT"	{	
			printf(" IMPORT Token (%s) ",yytext);
			return IMPORT;
		}
"LOOP"		{	
			printf(" LOOP Token (%s) ",yytext);
			return LOOP;
		}
"MODULE"	{
			printf(" MODULE Token (%s) ",yytext);
			return MODULE;
		}
"NIL"		{
			printf(" NIL Token (%s) ",yytext);
			return NIL;
		}
"POINTER"	{
			printf(" POINTER Token (%s) ",yytext);
			return POINTER;
		}
"PROCEDURE"	{
			printf(" PROCEDURE Token (%s) ",yytext);
			return PROCEDURE;
		}
"RETURN"	{		
			printf(" RETURN Token (%s) ",yytext);
			return RETURN;
		}
"TYPE"		{
			printf(" TYPE Token (%s) ",yytext);
			return TYPE;
		}
"VAR"		{
			printf(" VAR Token (%s) ",yytext);
			return VAR;
		}
"WITH"		{
			printf(" WITH Token (%s) ",yytext);
			return WITH;
		}
"ABS"		{
			printf(" ABS Token (%s) ",yytext);
			return ABS;
		}
"ODD"		{
			printf(" ODD Token (%s) ",yytext);
			return ODD;
		}
"LEN"		{
			printf(" LEN Token (%s) ",yytext);
			return LEN;
		}
"LSL"		{
			printf(" LSL Token (%s) ",yytext);
			return LSL;
		}
"ASR"		{
			printf(" ASR Token (%s) ",yytext);
			return ASR;
		}
"ROR"		{
			printf(" ROR Token (%s) ",yytext);
			return ROR;
		}
"FLOOR"		{
			printf(" FLOOR Token (%s) ",yytext);
			return FLOOR;
		}
"FLT"		{
			printf(" FLT Token (%s) ",yytext);
			return FLT;
		}
"ORD"		{
			printf(" ORD Token (%s) ",yytext);
			return ORD;
		}
"CHR"		{
			printf(" CHR Token (%s) ",yytext);
			return CHR;
		}
"LONG"		{
			printf(" LONG Token (%s) ",yytext);
			return LONG;
		}
"SHORT"		{
			printf(" SHORT Token (%s) ",yytext);
			return SHORT;
		}
"INC"		{
			printf(" INC Token (%s) ",yytext);
			return INC;
		}
"DEC"		{
			printf(" DEC Token (%s) ",yytext);
			return DEC;
		}
"INCL"		{
			printf(" INCL Token (%s) ",yytext);
			return INCL;
		}
"EXCL"		{
			printf(" EXCL Token (%s) ",yytext);
			return EXCL;
		}
"COPY"		{
			printf(" COPY Token (%s) ",yytext);
			return COPY;
		}
"NEW"		{
			printf(" NEW Token (%s) ",yytext);
			return NEW;
		}
"ASSERT"		{
			printf(" ASSERT Token (%s) ",yytext);
			return ASSERT;
		}
"PACK"		{
			printf(" PACK Token (%s) ",yytext);
			return PACK;
		}
"UNPK"		{
			printf(" UNPK Token (%s) ",yytext);
			return UNPK;
		}

"BOOLEAN"	{
			printf(" BOOLEAN_IDENT (%s)",yytext);
			return BOOLEAN;
		}
"CHAR"		{	
			printf(" CHAR_IDENT (%s) ",yytext);
			return CHAR;
		}
"INTEGER"	{
			printf(" INTEGER_IDENT (%s) ",yytext);
			return INTEGER;
		}
"REAL"		{
			printf(" REAL_IDENT (%s) ",yytext);
			return REAL;
		}
"LONGREAL"	{
			printf(" LONGREAL_IDENT (%s) ",yytext);
			return LONGREAL;
		}

{BOOLEAN}	{
			printf(" BOOLEAN (%s)",yytext);
			return BOOLEAN_VAL;
		}
{CHAR}		{	
			printf(" CHAR (%s) ",yytext);
			return CHAR_VAL;
		}
{INTEGER}	{
			printf(" INTEGER (%s) ",yytext);
			return INTEGER_VAL;
		}
{REAL}		{
			printf(" REAL (%s) ",yytext);
			return REAL_VAL;
		}
{STRING}	{
			printf(" STRING (%s) ",yytext);
			return STRING_VAL;
		}
{IDENT}		{
			printf(" IDENTIFIER (%s) ",yytext);
			return IDENT;
		}

%%

void yyerror(const char *s)
{
	return;
}

void AvoidComments(){
	printf(" Cmmmts ");
	int count=1;
	int cp1=0;
	int cp2=0;
	int v1=0;
	int v2=0;
	char c;
	while((c=input())!=EOF){
		if (c=='\n')
			yylineno++;
		if (c=='('){
			cp1=1;
		}
		else{
			if (cp1==1)
				v1=1;
			else
				v1=0;	
			cp1=0;
		}
		if (c=='*'){
			cp2=1;
		}
		else{
			if (cp2==1)
				v2=1;
			else
				v2=0;
			cp2=0;
		}
		if (v1==1){
			if (c=='*')
				count++;
		}
		if (v2==1){
			if (c==')' && count!=0){
				count--;
			}
			if (c==')' && count==0){
				break;
			}
		}
	}
}

int yywrap(void) {
	return 1;
}
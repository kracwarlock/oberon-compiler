%{
    # include <stdio.h>
    # include <stdlib.h>
    # include <string.h>
    /* definitions of manifest constants    
    */
    void yyerror(const char *s);
    void AvoidComments();

%}

/* regular definitions */
digit       [0-9]
letter      [A-Za-z]
hexdigit    [0-9A-Fa-f]

BOOLEAN     "TRUE"|"FALSE"
CHAR        (([0]{hexdigit}{hexdigit}[Xx])|([0]{hexdigit}[Xx]))
INTEGER     {digit}+
REAL        {INTEGER}"."{digit}*
STRING      ["][^"]*["]
IDENT       {letter}({letter}|{digit})*

%%

"="             {return EQ_COMP;}
"#"             {return UNEQ;}
"<"             {return LT;}
"<="            {return LE;}
">"             {return GT;}
">="            {return GE;}
"IN"            {return IN;}
"IS"            {return IS;}

"+"             {return PLUS_SYM;}
"-"             {return MINUS_SYM;}
"*"             {return MULTIPLY_SYM;}
"/"             {return DIVIDE_SYM;}
"DIV"           {return DIV;}
"MOD"           {return MOD;}

"OR"            {return OR_SYM;}
"&"             {return AND_SYM;}
"∼"             {return TILDA;}

":="            {return ASSIGN;}

[ \t]           {;}
[\r\n]          {yylineno++;}

"REPEAT"        {return REPEAT;}
"UNTIL"         {return UNTIL;}
"FOR"           {return FOR;}
"TO"            {return TO;}
"BY"            {return BY;}
"DO"            {return DOCASE;}
"END"           {return END;}
"WHILE"         {return WHILE;}
"IF"            {return IF_COND;}
"THEN"          {return THEN;}
"ELSIF"         {return ELSEIF;}
"ELSE"          {return ELSE;}
"CASE"          {return CASE_COND;}
"OF"            {return OF;}

"STRLEN"        {return STRLEN;}
"STRCAT"        {return STRCAT;}
"STRCPY"        {return STRCPY;}
"STRREV"        {return STRREV;}
"STRCMP"        {return STRCMP;}

{BOOLEAN}       {return BOOLEAN;}
{CHAR}          {return CHAR;}
{INTEGER}       {return INT;}
{REAL}          {return REAL;}
{LONGREAL}      {return LONGREAL;}
{STRING}        {return STRING;}
{IDENT}         {return IDENT;}

"(*"            {AvoidComments();}

"ARRAY"         {return ARRAY;}
"BEGIN"         {return BEG;}
"CONST"         {return CONST;}
"EXIT"          {return EXIT;}
"IMPORT"        {return IMPORT;}
"LOOP"          {return LOOP;}
"MODULE"        {return MODULE;}
"NIL"           {return NIL;}
"POINTER"       {return POINTER;}
"PROCEDURE"     {return PROCEDURE;}
"RETURN"        {return RETURN;}
"TYPE"          {return TYPE;}
"VAR"           {return VAR;}
"WITH"          {return WITH;}

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
        if (c=='(') cp1=1;
        else{
            if (cp1==1) v1=1;
            else v1=0;   
            cp1=0;
        }
        if (c=='*'){
            cp2=1;
        }
        else{
            if (cp2==1) v2=1;
            else v2=0;
            cp2=0;
        }
        if (v1==1){
            if (c=='*') count++;
        }
        if (v2==1){
            if (c==')' && count!=0) count--;
            if (c==')' && count==0) break;
        }
    }
}

int main(){
    yylex();
    return 0;
}

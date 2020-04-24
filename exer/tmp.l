%{
#include <stdlib.h>
#include "y.tab.h"
int get_ascii();
%}

WS		[ \t\n]+
IDENTIFIER	[A-Za-z_][A-Za-z0-9_]*
CHARACTER	\'([a-zA-Z_]|[0-9]|\\[\'\"\?\\abfnrtv0]|[!#%\^&\*\(_\)\-\+=~\[\]\|;:\{\},\.<>\/])\'
STRING		\"([^\\'"]|\\[abfnrtv0\'\"\?\\])*\"
INTEGER10	[1-9][0-9]*|0
INTEGER8	0[0-7]+
INTEGER16	0(x|X)[0-9A-Fa-f]+
REAL		[0-9]+\.([0-9]+|[0-9]+(e|E)(\+|\-)?[0-9]+)
COMMENT		\/\/(.)*|\/\*([^\*]|\*+[^\*\/])*\*+\/
OPERATOR_1B	[\+\-\*\/%!=<>\,]
PUNCTUATION	[\(\)\{\}\[\]\.:;]
ADDASGN		\+=
SUBASGN		\-=
MULASGN		\*=
DIVASGN		\/=
MODASGN		%=
EQ		==
NEQ		!=
LOE		<=
GOE		>=
LSHIFT		<<
RSHIFT		>>
AND		&&
OR		\|\|
INCREMENT	\+\+
DECREMENT	\-\-

%%
{WS}		{}
break		{return BREAK;}
case		{return CASE;}
char		{return CHAR;}
default		{return DEFAULT;}
else		{return ELSE;}
float		{return FLOAT;}
for		{return FOR;}
if		{return IF;}
int		{return INT;}
return		{return RETURN;}
struct		{return STRUCT;}
switch		{return SWITCH;}
void		{return VOID;}
while		{return WHILE;}
{IDENTIFIER}	{return ID;}
{CHARACTER}	{yylval.iVal = get_ascii(); return INTEGER;}
{STRING}	{return STRING;}
{INTEGER10}	{yylval.iVal = atoi(yytext); return INTEGER;}
{INTEGER8}	{yylval.iVal = (int)strtol(yytext, NULL, 8); return INTEGER;}
{INTEGER16}	{yylval.iVal = (int)strtol(yytext, NULL, 16); return INTEGER;}
{REAL}		{yylval.rVal = atof(yytext); return REAL;}
{COMMENT}	{}
{OPERATOR_1B}	{return yytext[0];}
{ADDASGN}	{return ADDASGN;}
{SUBASGN}	{return SUBASGN;}
{MULASGN}	{return MULASGN;}
{DIVASGN}	{return DIVASGN;}
{MODASGN}	{return MODASGN;}
{EQ}		{return EQ;}
{NEQ}		{return NEQ;}
{LOE}		{return LOE;}
{GOE}		{return GOE;}
{LSHIFT}	{return LSHIFT;}
{RSHIFT}	{return RSHIFT;}
{AND}		{return AND;}
{OR}		{return OR;}
{INCREMENT}	{return INCREMENT;}
{DECREMENT}	{return DECREMENT;}
{PUNCTUATION}	{return yytext[0];}
%%

int get_ascii() {
	if (yyleng == 3)
		return yytext[1];
	else {
		switch(yytext[2]) {
			case '\'':	return '\'';
			case '\"':	return '\"';
			case '\?':	return '\?';
			case '\\':	return '\\';
			case 'a':	return '\a';
			case 'b':	return '\b';
			case 'f':	return '\f';
			case 'n':	return '\n';
			case 'r':	return '\r';
			case 't':	return '\t';
			case 'v':	return '\v';
			case '0':	return '\0';
		}
	}
}

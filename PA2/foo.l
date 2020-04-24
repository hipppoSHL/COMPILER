%{

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tokenType[] = {"Keyword", "Identifier", "Character", "String", "Integer", "Real number", "Comment", "Operator", "Punctuation symbol"};

void calcDecimal(char* x);
void calcASCII(char* x);
int calcNL_comment(char* x);

%}

NEWLINE			\n
TAB				\t
BLANK			[ \t]
KEYWORD			break|case|char|default|else|float|for|if|int|return|switch|void|while|int|float|double|char|void
ID				{LETTER_}({LETTER_}|{DIGIT})*
DIGIT			[0-9]
LETTER_			[A-Za-z_]
INTEGER			[1-9][0-9]*|0|0[0-7]+|0[xX][A-Fa-f0-9]+
REAL			[0-9]+\.[0-9]+|[0-9]+\.[0-9]+[eE](\+|\-)?[0-9]+
CHAR			\'\\[abfnrtv0\\\'\"\?]\'|\'[^\\\'\"]\'
STRING			\"([^\\\'\"]|[abfnrtv0\\\'\"\?])*\"
COMMENT			(\/\/(([^\n])*)\n)|\/\*([^\*]|\*+[^\*\/])*\*+\/\n

ASGN			=
ADD_ASGN		\+=
SUB_ASGN		\-=
MUL_ASGN		\*=
DIV_ASGN		\/=
MOD_ASGN		%=
EQ_CMP			==
EQ_NOT			!=
EQ_LES			<=
EQ_BIG			>=
LSHIFT			<<
RSHIFT			>>
AND				&&
OR				\|\|
INCREMENT		\+\+
DECREMENT		\-\-
ADD				\+
SUB				\-
MUL				\*
DIV				\/
MOD				%
LESS			<
BIGG			>

PUNC			\(|\)|\{|\}|\[|\]|;|:|\.
ERROR			.

%%
{COMMENT}	{
				int i;
				char *comment = 0;
				comment = (char*)malloc(yyleng+1);
				for (i=0; i<yyleng; i++)
					comment[i] = yytext[i];
				comment[i] = '\0';
				yylval.sVal = comment;
				return COMMENT;
			}

break		{return break;}
case		{return case;}
char		{return char;}
default		{return default;}
else		{return else;}
float		{return float;}
for			{return for;}
if			{return if;}
int			{return int;}
return		{return return;}
switch		{return switch;}
void		{return void;}
while		{return while;}
int			{return int;}
float		{return float;}
double		{return double;}
char		{return char;}
void		{return void;}

{ID}		{
				int i;
				char *id = 0;
				id = (char*)malloc(yyleng+1);
				for (i=0; i<yyleng; i++)
					id[i] = yytext[i];
				id[i] = '\0';
				yylval.sVal = id;
				return ID;
			}

{INTEGER}	{
				yylval.iVal = calcDecimal(yytext); 
		    	return INTEGER;
			}
{REAL}		{
				yylval.rVal = atof(yytext);
				return REAL;
			}
{CHAR}		{
				yylval.iVal = calcASCII(yytext);
				return CHAR;
			}
{STRING}	{
				int i;
				char *str = 0;
				str = (char*)malloc(yyleng+1);
				for (i=0; i<yyleng; i++)
					str[i] = yytext[i];
				str[i] = '\0';
				yylval.sVal = str;
				return STRING;
			}
{OPERATOR}	{return yytext[0]; // 다시살펴보기 char->*char? }
{ASGN}		{return ASGN;}
{ADD_ASGN}	{return ADD_ASGN;}
{SUB_ASGN}	{return SUB_ASGN;}
{MUL_ASGN}	{return MUL_ASGN;}
{DIV_ASGN}	{return DIV_ASGN;}
{MOD_ASGN}	{return MOD_ASGN;}
{EQ_CMP}	{return EQ_CMP;}
{EQ_NOT}	{return EQ_NOT;}
{EQ_RIG}	{return EQ_RIG;}		
{EQ_LEF}	{return EQ_LEF;}		
{LSHIFT}	{return LSHIFT;}		
{RSHIFT}	{return RSHIFT;}		
{AND}		{return AND;}
{OR}		{return OR;}
{INCREMENT}	{return INCREMENT;}
{DECREMENT}	{return DECREMENT;}

{ADD}		{return ADD;}
{SUB}		{return SUB;}
{MUL}		{return MUL;}
{DIV}		{return DIV;}
{MOD}		{return MOD;}
{LESS}		{return LESS;}
{BIGG}		{return BIGG;}

{PUNC}		{return yytext[0];}
{ERROR}		{return ERROR;}
%%

void calcDecimal(char* x) {
	if (strlen(x) == 1 && x[0] == 0) {
		yylval.iVal = 0;
		return;
	}
	if (x[1] == 'x' || x[1] == 'X') {
		yylval.iVal = strtoul(x, NULL, 16);
		return;
	}
	if (x[0] == '0') {
		yylval.iVal = strtoul(x, NULL, 8);
		return;
	}
	else {
		yylval.iVal = atoi(x);
		return;
	}

}

void calcASCII(char* x) {
	if (strlen(x) == 3) {
		yylval.iVal = x[1];
		return;
	}

	if (x[2] == 'a') {
		yylval.iVal = x[2];
		return;
	}
	if (x[2] == 'b'){
		yylval.iVal = '\b';
		return;}
	if (x[2] == 'f'){
		yylval.iVal = '\f';
		return;}
	if (x[2] == 'n'){
		yylval.iVal = '\n';
		return;}
	if (x[2] == 'r'){
		yylval.iVal = '\r';
		return;}
	if (x[2] == 't'){
		yylval.iVal = '\t';
		return;}
	if (x[2] == 'v'){
		yylval.iVal = '\v';
		return;}
	if (x[2] == '0'){
		yylval.iVal = '\0';
		return;}

	if (x[2] == '?') {
		yylval.iVal = '\?';
		return;
	}
	if (x[2] == '"') {
		yylval.iVal = '\"';
		return;
	}
	if (x[2] == '\\') {
		yylval.iVal = '\\';
		return;
	}
	yylval.iVal = '\'';
	return;
}
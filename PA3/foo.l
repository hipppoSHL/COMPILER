%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int calcDecimal(char* x);
int calcASCII(char* x);
int calcNL_comment(char* x);
%}

WS				[ \t\n]+
DIGIT			[0-9]
LETTER_			[A-Za-z_]
ID				{LETTER_}({LETTER_}|{DIGIT})*
INTEGER			[1-9][0-9]*|0|0[0-7]+|0[xX][A-Fa-f0-9]+
REAL			[0-9]+\.[0-9]+|[0-9]+\.[0-9]+[eE](\+|\-)?[0-9]+
CHAR			\'\\[abfnrtv0\\\'\"\?]\'|\'[^\\\'\"]\'
STRING			\"([^\\\'\"]|[abfnrtv0\\\'\"\?])*\"
COMMENT		(\/\/(([^\n])*)\n)|\/\*([^\*]|\*+[^\*\/])*\*+\/\n

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

PUNC			\(|\)|\{|\}|\[|\]|;|:|\.|,

BREAK			break
CASE			case
CHAR_K			char
DEFAULT			default
ELSE			else
FLOAT			float
FOR				for
IF				if
RETURN			return
SWITCH			switch
VOID			void
WHILE			while
INT				int
DOUBLE			double

%%
{WS}		{}
{BREAK}		{return BREAK;}
{CASE}		{return CASE;}
{CHAR_K}	{return CHAR_K;}
{DEFAULT}	{return DEFAULT;}
{ELSE}		{return ELSE;}
{FLOAT}		{return FLOAT;}
{FOR}		{return FOR;}
{IF}		{return IF;}
{RETURN}	{return RETURN;}
{SWITCH}	{return SWITCH;}
{VOID}		{return VOID;}
{WHILE}		{return WHILE;}
{INT}		{return INT;}
{DOUBLE}	{return DOUBLE;}

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
{INTEGER}	{
				yylval.iVal = calcDecimal(yytext); 
		    	return INTEGER;
			}
{REAL}		{
				yylval.rVal = atof(yytext);
				return REAL;
			}

{COMMENT}	{}

{ASGN}		{return ASGN;}
{ADD}		{return ADD;}
{SUB}		{return SUB;}
{MUL}		{return MUL;}
{DIV}		{return DIV;}
{MOD}		{return MOD;}
{LESS}		{return LESS;}
{BIGG}		{return BIGG;}
			
{ADD_ASGN}	{return ADD_ASGN;}
{SUB_ASGN}	{return SUB_ASGN;}
{MUL_ASGN}	{return MUL_ASGN;}
{DIV_ASGN}	{return DIV_ASGN;}
{MOD_ASGN}	{return MOD_ASGN;}
{EQ_CMP}	{return EQ_CMP;}
{EQ_NOT}	{return EQ_NOT;}
{EQ_LES}	{return EQ_LES;}		
{EQ_BIG}	{return EQ_BIG;}		
{LSHIFT}	{return LSHIFT;}		
{RSHIFT}	{return RSHIFT;}		
{AND}		{return AND;}
{OR}		{return OR;}
{INCREMENT}	{return INCREMENT;}
{DECREMENT}	{return DECREMENT;}

{PUNC}		{return yytext[0];}
%%

int calcDecimal(char* x) {
	if (strlen(x) == 1 && x[0] == 0) {
		return 0;
	}
	if (x[1] == 'x' || x[1] == 'X') {
		return strtoul(x, NULL, 16);
	}
	if (x[0] == '0') {
		return strtoul(x, NULL, 8);
	}
	else {
		return atoi(x);
	}

}

int calcASCII(char* x) {
	if (strlen(x) == 3)
		return x[1];

	if (x[2] == 'a')
		return x[2];

	if (x[2] == 'b')
		return '\b';
	if (x[2] == 'f')
		return '\f';
	if (x[2] == 'n')
		return '\n';
	if (x[2] == 'r')
		return '\r';
	if (x[2] == 't')
		return '\t';
	if (x[2] == 'v')
		return '\v';
	if (x[2] == '0')
		return '\0';

	if (x[2] == '?')
		return '\?';
	if (x[2] == '"')
		return '\"';
	if (x[2] == '\\')
		return '\\';
		
	return '\'';
}
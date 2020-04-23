%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tokenType[] = {"Keyword", "Identifier", "Character", "String", "Integer", "Real number", "Comment", "Operator", "Punctuation symbol"};
enum tnumber {TEOF, TKEYWORD, TIDENTIFIER, TCHARACTER, TSTRING, TINTEGER, TREAL, TCOMMENT, TOPERATOR, TPUNCTUATION, TERROR};

union{
	int iVal;
	float rVal;
} yylval;

int line, pos;

void calcDecimal(char* x);
void calcASCII(char* x);
int calcNL_comment(char* x);

%}

NEWLINE		\n
TAB			\t
BLANK		[ \t]+
KEYWORD		break|case|char|default|else|float|for|if|int|return|switch|void|while|int|float|double|char|void
ID			{LETTER_}({LETTER_}|{DIGIT})*
DIGIT		[0-9]
LETTER_		[A-Za-z_]
INTEGER		[1-9][0-9]*|0|0[0-7]+|0[xX][A-Fa-f0-9]+
REAL		[0-9]+\.[0-9]+|[0-9]+\.[0-9]+[eE](\+|\-)?[0-9]+
CHAR		\'\\[abfnrtv0\\\'\"\?]\'|\'[^\\\'\"]\'
STRING		\"([^\\\'\"]|[abfnrtv0\\\'\"\?])*\"
COMMENT		(\/\/(([^\n])*)\n)|\/\*([^\*]|\*+[^\*\/])*\*+\/\n
OPERATOR	\+(\+|=)?|\-(\-|=)?|\*(=)?|\/(=)?|%(=)?|!(=)?|(<|>|=)?=|<|>|&&|\|\||,
PUNC		\(|\)|\{|\}|\[|\]|;|:|\.
ERROR		.

%%
{COMMENT}	{return TCOMMENT;}
{NEWLINE}	{line++; pos = 1;}
{BLANK}		{pos++;}
{KEYWORD}	{return TKEYWORD;}
{ID}		{return TIDENTIFIER;}
{INTEGER}	{return TINTEGER;}
{REAL}		{return TREAL;}
{CHAR}		{return TCHARACTER;}
{STRING}	{return TSTRING;}
{OPERATOR}	{return TOPERATOR;}
{PUNC}		{return TPUNCTUATION;}
{ERROR}		{return TERROR;}
%%

int main(int argc, char *argv[]){
	enum tnumber tn;
	if(!argc)	exit(0);
	yyin = fopen(argv[1], "r");

	// Insert source code here...
	
	line = 1;
	pos = 1;

	while ((tn = yylex()) != TEOF) {
		switch (tn) {
			case (TINTEGER):
				calcDecimal(yytext);
				printf("%-15s:%19s,%3d,%3d,%5d\n", yytext, tokenType[tn-1], line, pos, yylval.iVal);
				break;
				pos += strlen(yytext);
			case (TCHARACTER):
				calcASCII(yytext);
				printf("%-15s:%19s,%3d,%3d,%5d\n", yytext, tokenType[tn-1], line, pos, yylval.iVal);
				pos += strlen(yytext);
				break;
			case (TREAL):
				yylval.rVal = atof(yytext);
				printf("%-15s:%19s,%3d,%3d,%5.2f\n", yytext, tokenType[5], line, pos, yylval.rVal);
				pos += strlen(yytext);
				break;
			case (TCOMMENT):
				printf("%-15s:%19s,%3d,%3d\n", yytext, tokenType[tn-1], line, pos);
				// line += calcNL_comment(yytext);
				int lines = 0;
				int tmp = 0;
				while (yytext[tmp] != '\0') {
					if (yytext[tmp] == '\n') {
						lines++;
						pos = 1;
					}
					tmp++;
				}
				line += lines;
				break;
			case (TKEYWORD):
			case (TIDENTIFIER):
			case (TSTRING):
			case (TOPERATOR):
			case (TPUNCTUATION):
				printf("%-15s:%19s,%3d,%3d\n", yytext, tokenType[tn-1], line, pos);
				pos += strlen(yytext);
				break;
			case (TERROR):
				printf("Error occurred in Line %d, Position %d\n", line, pos);
				return 0;

		}
	}

	fclose(yyin);
	return 0;
}

void calcDecimal(char* x) {
	if (strlen(x) == 1 && x[0] == 0) {
		yylval.iVal = 0;
		return;
	}
	if (x[0] == '0') {
		yylval.iVal = strtoul(x, NULL, 8);
		return;
	}
	if (x[0] == 'x' || x[0] == 'X') {
		yylval.iVal = strtoul(x, NULL, 16);
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

int calcNL_comment(char* x) {
	// int lines = 0;
	// int tmp = 0;
	// if (x[1] != '*') {
	// 	while (x[tmp] != '\0') {
	// 		if (x[tmp] == '\n') {
	// 			lines++;
	// 		}
	// 		tmp++;
	// 	}
	// 	return lines;
	// }
	// pos = 1;
	// return 1;
}
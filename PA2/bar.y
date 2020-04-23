%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror(char*);
%}
%union{
	int iVal;
	float rVal;
	char* sVal;
}

%%
Program :
	;
%%
int main(int argc, char *argv[]){
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	return 0;
}


%{
#include <stdio.h>
int yylex(void);
int yyerror(char*);
%}

%token TINTEGER
%%
START : EXPR    {printf("Result=%d\n", $1);}
EXPR : EXPR '+' TERM    {$$ = $1 + $3; printf("Expr -> Expr + Term\n");}
     | TERM             {$$ = $1; printf("Expr -> Term\n");}
     ;
TERM : TERM '*' TINTEGER    {$$ = $1 * $3; printf("Term -> Term * %d\n", $3);}
     | TINTEGER             {$$ = $1; printf("Term -> %d\n", $1);}
     ;
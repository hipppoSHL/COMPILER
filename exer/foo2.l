%{
#include "y.tab.h"
%}

WS              [ \t]+
INTEGER         0|[1-9][0-9]*
%%
\n              {return 0;}
{INTEGER}       {yylval = atoi(yytext); return TINTEGER;}
\+              {return '+';}
\*              {return '*';}

%{
#include <stdio.h>
%}

WS              [ \t\n]+
TYPE            int|float|double|char|void
DIGIT           [0-9]
LETTER_         [A-Za-z_]
ID              {LETTER_}({LETTER_}|{DIGIT})*

%%

{TYPE}          {printf("<Type>");}
{ID}            {printf("<ID>");}

%%

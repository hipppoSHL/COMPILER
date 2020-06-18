#ifndef _TAC_H_
#define _TAC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
typedef struct lbStack_t LBSTACK;

char* genOutputFN(char* fn);

void buildTAC(ASTNode *root);
char* genTAC(ASTNode *node);

char* mkTmp(void);
char* genLabel(void);

LBSTACK *initLBStack(void);
void pushLabel(LBSTACK *lbStack, char *label);
char *popLabel(LBSTACK *lbStack);
char *topLabel(LBSTACK *lbStack);
#endif

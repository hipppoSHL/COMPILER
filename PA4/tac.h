#ifndef _TAC_H_
#define _TAC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

void buildTAC(ASTNode *root);
void travelNodes(ASTNode *node, SYMTAB *table);
#endif

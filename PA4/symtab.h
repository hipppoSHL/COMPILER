#ifndef _SYMTAB_H_
#define _SYMTAB_H_
#include "ast.h"
typedef struct symtab_t SYMTAB;

SYMTAB *initSymTab(void);
void delSymTab(SYMTAB* table);

void pushSymTab(SYMTAB* table);
void popSymTab(SYMTAB* table);

void addSym(SYMTAB* table, char* id, TYPE t);
void addSymArray(SYMTAB* table, char* id, TYPE t, int size);
void addParam(SYMTAB* table, char* id, TYPE t);
void addParamArray(SYMTAB* table, char* id, TYPE t, int size);

TYPE getThisFuncType(SYMTAB* table);
TYPE getSymType(SYMTAB* table, char* id);
TYPE getParamType(SYMTAB* table, char* func, int index);
int getNumOfParam(SYMTAB* table, char* func);

void printSymTab(SYMTAB* table);

void showTypeError(void);
#endif


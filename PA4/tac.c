#include "tac.h"

void buildTAC(ASTNode *root){
	SYMTAB *table = initSymTab();
	travelNodes(root, table);
	delSymTab(table);
}
void travelNodes(ASTNode *node, SYMTAB *table){
	TKNUM tn = getTkNum(node);
	switch(tn){
		case _PROG:
			break;
		case _VARDEC:
			break;
		case _FUNCDEC:
			break;
		case _ID:
			break;
		case _ID_ARR:
			break;
		case _TYPE:
			break;
		case _VALUE:
			break;
		case _PARAMS:
			break;
		case _PARAM:
			break;
		case _CPDSTMT:
			break;
		case _LDECLIST:
			break;
		case _STMTLIST:
			break;
		case _IFSTMT:
			break;
		case _SWSTMT:
			break;
		case _RTSTMT:
			break;
		case _BRKSTMT:
			break;
		case _WHLSTMT:
			break;
		case _FORSTMT:
			break;
		case _CASE:
			break;
		case _DEFAULT:
			break;
		case _INCDEC_EXP:
			break;
		case _OPER:
			break;
		case _INTEGER:
			break;
		case _REAL:
			break;
		case _ARGS:
			break;
		case _FUNCCALL:
			break;
	}
	if(getChild(node))	travelNodes(getChild(node), table);	
	switch(tn){
		case _PROG:
			break;
		case _VARDEC:
			break;
		case _FUNCDEC:
			break;
		case _ID:
			break;
		case _ID_ARR:
			break;
		case _TYPE:
			break;
		case _VALUE:
			break;
		case _PARAMS:
			break;
		case _PARAM:
			break;
		case _CPDSTMT:
			break;
		case _LDECLIST:
			break;
		case _STMTLIST:
			break;
		case _IFSTMT:
			break;
		case _SWSTMT:
			break;
		case _RTSTMT:
			break;
		case _BRKSTMT:
			break;
		case _WHLSTMT:
			break;
		case _FORSTMT:
			break;
		case _CASE:
			break;
		case _DEFAULT:
			break;
		case _INCDEC_EXP:
			break;
		case _OPER:
			break;
		case _INTEGER:
			break;
		case _REAL:
			break;
		case _ARGS:
			break;
		case _FUNCCALL:
			break;
	}
	if(getSibling(node))	travelNodes(getSibling(node), table);
}



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
			printf("_PROG\n");
			break;
		case _VARDEC:
		{
			// VarDeclaration: TypeSpecifier IDs ';'
			// IDs: IDs ',' Value | Value
			// Value: ID '[' INTEGER ']' | ID
			ASTNode *typenode = getChild(node);
			ASTNode *idsnode = getSibling(typenode);
			do {
				// 만약 배열 타입 아닐 때
				if (getTkNum(idsnode) == _ID) {
					ASTNode *valuenode = idsnode;
					char* var_id = getSVal(valuenode);
					addSym(table, var_id, getType(typenode));
				} else { // 만약 배열 타입일 때
					int var_arr_num = getIVal(getSibling(getChild(idsnode)));
					char* var_id = getSVal(getChild(idsnode));
					int var_arr_type = getType(typenode) + 1;
					addSymArray(table, var_id, var_arr_type, var_arr_num);
				}
			} while (idsnode = getSibling(idsnode));
			break;
		}
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
		{
			pushSymTab(table);
			break;
		}
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
		{
			popSymTab(table);
			break;
		}
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
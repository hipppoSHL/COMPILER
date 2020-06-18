#include "tac.h"
#include "y.tab.h"

extern FILE* yyout;
LBSTACK *lbStack;

void buildTAC(ASTNode *root){
	lbStack = initLBStack();
	genTAC(root);
}

char* genTAC(ASTNode *node){
	ASTNode *n1 = 0, *n2 = 0;
	char *op = 0, *_t = 0;
	if(!node)	return NULL;
	switch(getTkNum(node)){
		case _PROG:
		// 루트 노드일 때, 첫 번째 자식 노드부터 마지막 자식노드에 대해 전부 genTAC 수행하라
			for(n1 = getChild(node); n1; n1 = getSibling(n1))	genTAC(n1);
			break;
		case _FUNCDEC:
		// VARDEC은 할 것 없고, 앞에 함수 이름 레이블로 써주고, beginFunc, 내용 써 주고 endFunc도 해줘야 함
			genTAC(/*CPDSTMT*/getSibling(/*매개변수*/getSibling(/*함수이름*/getSibling(/*타입*/getChild(node)))));
			break;
		case _CPDSTMT:
			if(/*LDECLIST*/n1 = getChild(node))
				if(/*STMTLIST*/getSibling(n1))
					genTAC(getSibling(n1));
			break;
		case _STMTLIST:
			if(n1 = getChild(node))
			// 첫 번째 자식 노드부터 마지막 자식노드에 대해 전부 genTAC 수행하라
				for(;n1;n1 = getSibling(n1)){
					genTAC(n1);
				}
			break;
		case _OPER:
			op = getSVal(node);
			if(!strcmp(op, "+")){
				// 배열 고려하지 않았으므로 
				n2 = getSibling(n1 = getChild(node));
				fprintf(yyout, "\t%s\t= %s\t+ %s\n", _t = mkTmp(), genTAC(n1), genTAC(n2));
				setName(node, _t);
			}
			else if(!strcmp(op, "=")){
				char *nn1 = 0;
				n2 = getSibling(n1 = getChild(node));
				fprintf(yyout, "\t%s\t= %s\n", nn1 = genTAC(n1), genTAC(n2));
				fprintf(yyout, "\t%s\t= %s\n", _t = mkTmp(), nn1);
				setName(node, _t);
			}
	}
	return getName(node);
}


#include "tac.h"
#include "y.tab.h"
#include <string.h>

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
		{
			ASTNode *type = 0, *funcid = 0, *params = 0, *cpdstmt = 0;
			cpdstmt = (params = getSibling(funcid = getSibling(type = getChild(node))));
			fprintf(yyout, "%s:\n", getSVal(funcid));
			fprintf(yyout, "\tBeginFunc\n");
			genTAC(/*CPDSTMT*/getSibling(/*매개변수*/getSibling(/*함수이름*/getSibling(/*타입*/getChild(node)))));
			fprintf(yyout, "\tEndFunc\n");
			break;
		}
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
		{
			ASTNode *left = 0, *right = 0;
			op = getSVal(node);
			if (!strcmp(op, "=")) {
				genTAC(left = getChild(node));
				genTAC(right = getSibling(left));
				setName(node, getName(left));
				setName(node, mkTmp());
				fprintf(yyout, "\t%s = %s\n", getName(left), getName(right));
				fprintf(yyout, "\t%s = %s\n", getName(node), getName(left));
			} else if (!strcmp(op, "++") || !strcmp(op, "--")) {
				;
			} else if (!strcmp(op, "+=") || !strcmp(op, "-=")) {
				right = getSibling(left = getChild(node));
				genTAC(left); genTAC(right);
				char* oper = (!strcmp(op, "+=")) ? "+" : "-";
				setName(node, getName(left));
				setName(node, mkTmp());
				fprintf(yyout, "\t%s = %s %s %s\n", getName(left), getName(left), oper, getName(right));
				fprintf(yyout, "\t%s = %s\n", getName(node), getName(left));
			} else {
				right = getSibling(left = getChild(node));
				genTAC(left); genTAC(right);
				setName(node, mkTmp());
				fprintf(yyout, "\t%s = %s %s %s\n", getName(node), getName(left), op, getName(right));
			}
			break;
		}
		case _INCDEC_EXP:
		{
			ASTNode *left = 0, *right = 0;
			right = getSibling(left = getChild(node));
			if (getTkNum(left) == _OPER) {
				char* op = !strcmp(getSVal(left),"++") ? "+" : "-";
				genTAC(right);
				setName(node, getName(right));
				fprintf(yyout, "\t%s = %s %s 1\n", getName(node), getName(node), op);
			} else {
				char* op = !strcmp(getSVal(right),"++") ? "+" : "-";
				setName(node, mkTmp());
				fprintf(yyout, "\t%s = %s\n", getName(node), getName(left));
				fprintf(yyout, "\t%s = %s %s 1\n", getName(left), getName(left), op);
			}
			break;
		}
		case _WHLSTMT:
		{
			char *lb1 = 0, *lb2 = 0;
			ASTNode *exp = 0, *CpndStmt= 0;
			fprintf(yyout, "%s:\n", lb1 =genLabel());
			genTAC(exp = getChild(node));
			fprintf(yyout, "\tIFZ %s Goto %s\n",getName(exp), lb2 = genLabel());
			pushLabel(lbStack, lb2);
			if (CpndStmt = getSibling(exp))
				genTAC(CpndStmt);
			fprintf(yyout, "\tGoto %s\n", lb1);
			fprintf(yyout, "%s: \n", lb2);
			popLabel(lbStack);
			break;
		}
		case _IFSTMT:
		{
			char *lb1 = 0, *lb2 = 0;
			ASTNode *exp = 0, *else_node = 0;
			genTAC(exp = getChild(node));
			fprintf(yyout, "\tIFZ %s Goto %s\n", getName(exp), lb1 = genLabel());
			if (else_node = getSibling(getSibling(exp))) {
				fprintf(yyout, "\tGoto %s\n", lb2 = genLabel());
			}
			fprintf(yyout, "\tGoto %s\n", topLabel(lbStack));
			fprintf(yyout, "%s: \n", lb1);
			if (else_node) {
				genTAC(else_node);
				fprintf(yyout, "%s: \n", lb2);
			}
			break;
		}
		case _FORSTMT:
		{
			char *lb1 = 0, *lb2 = 0;
			ASTNode *exp1 = 0, *exp2 = 0, *exp3 = 0, *CpndStmt = 0;
			genTAC(exp1 = getChild(node));
			fprintf(yyout, "%s:\n", lb1 = genLabel());
			genTAC(exp2 = getSibling(exp1));
			fprintf(yyout, "\tIFZ %s Goto %s\n", getName(exp2), lb2 = genLabel());
			pushLabel(lbStack, lb2);
			CpndStmt = getSibling(exp3 = getSibling(exp2));
			if (CpndStmt) genTAC(CpndStmt);
			genTAC(exp3);
			fprintf(yyout, "\tGoto %s\n", lb1);
			fprintf(yyout, "%s: \n", lb2);
			popLabel(lbStack);
			break;
		}
		case _SWSTMT:
		{
			// char *lb0 = 0;
			// ASTNode *exp = 0;
			// pushLabel(lbStack, lb0);
			// genTAC(exp = getChild(node));
			// break;
		}
		case _BRKSTMT:
			fprintf(yyout, "\tGoto %s\n", topLabel(lbStack));
			break;
		case _ID:
			setName(node, getSVal(node));
			break;
		case _ID_ARR:
		{
			ASTNode *id = 0, *expr = 0;
			expr = getSibling(id = getChild(node));
			genTAC(id);
			genTAC(expr);
			setName(node, mkTmp());
			fprintf(yyout, "\t%s = %s * %d\n", getName(node), getName(expr), 4);
			char* tmp = getName(node);
			setName(node, mkTmp());
			fprintf(yyout, "\t%s = %s + %s\n", getName(node), getName(id), tmp);
			char *t1 = "*(";
			char *t2 = ")";
			char *t3 = getName(node);
			char *str = malloc(sizeof(char) * (strlen("*(") + strlen(")") + strlen(t3)));
			sprintf(str, "%s%s%s", t1, t3, t2);
			setName(node, str);
			break;
		}
		case _RTSTMT:
		{	
			ASTNode *expr = 0;
			if (getChild(node)) {
				expr = getChild(node);
				genTAC(expr);
				fprintf(yyout, "\tReturn %s\n", getName(expr));
			} else {
				fprintf(yyout, "\tReturn\n");
			}
			break;
		}
		case _FUNCCALL:
		{
			int cnt = 0;
			ASTNode* tmp[100]; 
			ASTNode *funcid = 0, *arguments = 0, *arg = 0;
			arguments = getSibling(funcid = getChild(node));
			// genTAC(arguments);

			for (arg = getChild(arguments); arg; arg = getSibling(arg)) {	
				genTAC(arg);
				// fprintf(yyout, "\tPushParam %s\n", getName(arg));
				cnt++;
				tmp[cnt] = arg;
			}
			for (int i = cnt; i > 0; i--) {
				fprintf(yyout, "\tPushParam %s\n", getName(tmp[i]));
			}
			setName(node, mkTmp());
			fprintf(yyout, "\t%s = LCall %s\n", getName(node), getSVal(funcid));
			fprintf(yyout, "\tPopParam %d\n", 4*cnt);
			break;
		}
	}
	return getName(node);
}


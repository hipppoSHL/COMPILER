#include "tac.h"
#include <string.h>

static int idMode;
int evalVar_type(ASTNode *node, SYMTAB *table);
int evalTerm_type(ASTNode *node, SYMTAB *table);
int evalAddExpr_type(ASTNode *node, SYMTAB *table);
int evalExpr_type(ASTNode *node, SYMTAB *table);
int evalFactor_type(ASTNode *node, SYMTAB *table);
int evalRelExpr_type(ASTNode *node, SYMTAB *table);

int evalExpr_type(ASTNode *node, SYMTAB *table) {
	if (getTkNum(node) == _OPER) {
		char* oper = getSVal(node);

		// AssignExpr
		if ((strcmp(oper,"=") == 0) || (strcmp(oper,"+=") == 0) || (strcmp(oper,"-=") == 0) || (strcmp(oper,"*=") == 0) ||  (strcmp(oper,"/=") == 0) || (strcmp(oper,"%%=") == 0)) {
			ASTNode *var_node = getChild(node);
			int var_type = evalVar_type(var_node, table);
			return var_type;
		}

		// SimpleExpr
		if ((strcmp(oper,"||") == 0)) {
			ASTNode *andexpr_node = getSibling(getChild(node));
			return evalExpr_type(andexpr_node, table);
		}

		// AndExpr
		if ((strcmp(oper,"&&") == 0)) {
			ASTNode *relexpr_node = getSibling(getChild(node));
			return evalRelExpr_type(relexpr_node, table);
		}

		// RelExpr
		if (strcmp(oper,"<")==0 || strcmp(oper,"<=")==0 || strcmp(oper,">")==0 || strcmp(oper,">=")==0 || strcmp(oper,"==")==0 || strcmp(oper,"!=")==0) {
			ASTNode *addexpr_node = getSibling(getChild(node));
			return evalAddExpr_type(addexpr_node, table);
		}

		// AddExpr
		if (strcmp(oper,"+")==0 || strcmp(oper,"-")==0) {
			ASTNode *term_node = getSibling(getChild(node));
			return evalTerm_type(term_node, table);
		}

		// Term
		if (strcmp(oper,"*")==0 || strcmp(oper,"/")==0 || strcmp(oper,"%%")==0) {
			ASTNode *fact_node = getSibling(getChild(node));
			return evalTerm_type(fact_node, table);
		}
	}
	return evalFactor_type(node, table);
}

int evalVar_type(ASTNode *node, SYMTAB *table) {
	// Variable: ID '[' Expr ']'
	// 		   | ID
	if (getTkNum(node) == _ID_ARR) {
		ASTNode *id_node = getChild(node);
		char* id_str = getSVal(id_node);
		return getSymType(table, id_str);
	}
	else {
		char* id_str = getSVal(node);
		return getSymType(table, id_str);
	}
}

int evalFactor_type(ASTNode *node, SYMTAB *table) {
	int ret;

	//       | FunctionCall
	if (getTkNum(node) == _FUNCCALL) {
		ASTNode *funcid_node = getChild(node);
		int functype = getSymType(table, getSVal(funcid_node));
		if (functype == TYPE_INT_FUNC)
			ret = TYPE_INT;
		else if (functype == TYPE_FLOAT_FUNC)
			ret = TYPE_FLOAT;
		else if (functype == TYPE_VOID_FUNC)
			ret = TYPE_VOID;
	}

	//		 | SUB Factor
	else if (getTkNum(node) == _OPER && strcmp(getSVal(node), "-") == 0) {
		ASTNode *nextfact_node = getChild(node);
		ret = evalFactor_type(nextfact_node, table);
	}

	// 		 | NumberLiteral
	else if (getTkNum(getChild(node)) == _INTEGER)
		ret = TYPE_INT;

	//       | IncDec Variable
	else if (getTkNum(getChild(getChild(node))) == _OPER && (strcmp(getSVal(getChild(getChild(node))),"++")==0 || strcmp(getSVal(getChild(getChild(node))),"--")==0)) {
		ASTNode *var_node = getSibling(getChild(node));
		ret = evalVar_type(var_node, table);
	}

	//		 | Variable
	//       | Variable IncDec
	else if (getTkNum(getChild(node)) == _ID || getTkNum(getChild(node)) == _ID_ARR) {
		ret = evalVar_type(node, table);
	}
	
	// Factor: '(' Expr ')'
	else {
		ASTNode *expr_node = getChild(node);
		ret = evalExpr_type(expr_node, table);
	}

	return ret;
}

int evalTerm_type(ASTNode *node, SYMTAB *table) {
	// Term: Term MUL(*,/,%) Factor
	int ret;
	ASTNode *tmp = getChild(node);
	while (getSibling(tmp))
		tmp = getSibling(tmp);
	ret = evalFactor_type(tmp, table);
	return ret;
}

int evalAddExpr_type(ASTNode *node, SYMTAB *table) {
	// AddExpr: AddExpr OP(+,-) Term
	int ret;
	ASTNode *tmp = getChild(node);
	while (getSibling(tmp))
		tmp = getSibling(tmp);
	ret = evalTerm_type(tmp, table);
	return ret;
}

int evalRelExpr_type(ASTNode *node, SYMTAB *table) {
	// RelExpr: RelExpr LESS(OP) AddExpr | AddExpr
	int ret;
	ASTNode *tmp = getChild(node);
	while (getSibling(tmp))
		tmp = getSibling(tmp);
	ret = evalAddExpr_type(tmp, table);
	return ret;
}


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
		{
			// FuncDeclaration: Type ID '(' Params ')' CompoundStmt
			ASTNode *typeNode = getChild(node);
			ASTNode *idNode = getSibling(typeNode);
			int functype;
			if (getType(typeNode) == TYPE_INT)
				functype = TYPE_INT_FUNC;
			else if (getType(typeNode) == TYPE_FLOAT)
				functype = TYPE_FLOAT_FUNC;
			else if (getType(typeNode) == TYPE_VOID)
				functype = TYPE_VOID_FUNC;

			// 심볼 테이블에 함수 추가
			addSym(table, getSVal(idNode), functype);
			break;
		}

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
		{
			// Param: TypeSpecifier Value
			// Value: ID '[' INTEGER ']' | ID
			// 매개변수가 배열이거나, 배열이 아닐 수 있음
			int paramtype = getType(getChild(node));
			ASTNode *value_node = getSibling(getChild(node));
			ASTNode *paramid_node = getChild(value_node);
			char* paramid = getSVal(paramid_node);
			// 만약 매개변수 배열일 때
			if (getSibling(paramid_node)) {
				int param_arr_num = getIVal(getSibling(paramid_node));
				addParamArray(table, paramid, paramtype+1, param_arr_num);
			} else { // 매개변수가 배열이 아닐 때
				addParam(table, paramid, paramtype);
			}
			break;
		}
		case _CPDSTMT:
			pushSymTab(table);
			break;
		case _LDECLIST:
			break;
		case _STMTLIST:
			break;
		case _IFSTMT:
		{
			ASTNode *expr_node = getChild(node);
			int expr_type = evalExpr_type(expr_node, table);
			if (expr_type != TYPE_INT) {
				printf("Type error in if statement!\n");
				exit(-1);
			}
			break;
		}
		case _SWSTMT:
		{
			ASTNode *expr_node = getChild(node);
			int expr_type = evalExpr_type(expr_node, table);
			if (expr_type != TYPE_INT) {
				printf("Type error in if statement!\n");
				exit(-1);
			}
			break;
		}
		case _RTSTMT:
		{
			int defined_ret_type = getThisFuncType(table);
			int ret_type;
			if (getChild(node)) {
				ret_type = evalExpr_type(getChild(node), table);
			} else { ret_type = TYPE_VOID; }
			if ((ret_type == TYPE_VOID) && (defined_ret_type == TYPE_VOID_FUNC)) {}
			else if((ret_type == TYPE_INT) && (defined_ret_type == TYPE_INT_FUNC)) {}
			else if((ret_type == TYPE_FLOAT) && (defined_ret_type == TYPE_FLOAT_FUNC)) {}
			else {
				printf("Return Type error!\n");
				exit(1);
			}
			break;
		}
		case _BRKSTMT:
			break;
		case _WHLSTMT:
		{
			ASTNode *expr_node = getChild(node);
			int expr_type = evalExpr_type(expr_node, table);
			if (expr_type != TYPE_INT) {
				printf("Type error in if statement!\n");
				exit(-1);
			}
			break;
		}
		case _FORSTMT:
		{
			ASTNode *expr_node = getSibling(getChild(node));
			int expr_type = evalExpr_type(expr_node, table);
			if (expr_type != TYPE_INT) {
				printf("Type error in if statement!\n");
				exit(-1);
			}
			break;
		}
		case _CASE:
			break;
		case _DEFAULT:
			break;
		case _INCDEC_EXP:
			break;
		case _OPER:
		{
			char* oper = getSVal(node);
			ASTNode *tmp = getChild(node);
			int childcnt = 0;
			while (getSibling(tmp)) {
				childcnt++;
				tmp = getSibling(tmp);
			}
			
			// Factor: SUB(OP) Factor (unary)
			if (childcnt == 2) {
				ASTNode *fact_node = getChild(node);
				int fact_type = evalFactor_type(fact_node, table);
				if (!(fact_type == TYPE_INT || fact_type == TYPE_FLOAT)) {
					printf("Type error in expression!\n");
					exit(1);
				}
			}

			// AssignExpr: Variable ASGN Expr
			else if (strcmp(oper,"=")==0 || strcmp(oper,"+=")==0 || strcmp(oper,"-=")==0 || strcmp(oper,"*=")==0 || strcmp(oper,"/=")==0) {
				int var_type = evalVar_type(getChild(node), table);
				int expr_type = evalExpr_type(getSibling(getChild(node)), table);
				if (var_type != expr_type) {
					printf("Type error in expression!\n");
					exit(1);
				}
			}
			else if (strcmp(oper,"%%=")==0) {
				int var_type = evalVar_type(getChild(node), table);
				int expr_type = evalExpr_type(getSibling(getChild(node)), table);
				if ((var_type != TYPE_INT) || (var_type != expr_type)) {
					printf("Type error in expression!\n");
					exit(1);
				}
			}

			// RelExpr: RelExpr LESS(OP) AddExpr
			else if (strcmp(oper,"<")==0 || strcmp(oper,"<=")==0 || strcmp(oper,">")==0 || strcmp(oper,">=")==0 || strcmp(oper,"==")==0 || strcmp(oper,"!=")==0) {
				int rel_type = evalRelExpr_type(getChild(node), table);
				int add_type = evalAddExpr_type(getSibling(getChild(node)), table);
				if (rel_type != add_type) {
					printf("Type error in expression!\n");
					exit(1);
				}
			}

			// AddExpr: AddExpr ADD(OP) Term
			else if (strcmp(oper,"+")==0 || strcmp(oper,"-")==0) {
				int add_type = evalAddExpr_type(getChild(node), table);
				int term_type = evalTerm_type(getSibling(getChild(node)), table);
				if (add_type != term_type) {
					printf("Type error in expression!\n");
					exit(1);
				}
			}

			// Term: Term MUL(OP) Factor (특히 %의 경우 두 피연산자 모두 정수여야 함)
			else if (strcmp(oper,"*")==0 || strcmp(oper,"/")==0) {
				int term_type = evalTerm_type(getChild(node), table);
				int factor_type = evalFactor_type(getSibling(getChild(node)), table);
				if (term_type != factor_type) {
					printf("Type error in expression!\n");
					exit(1);
				}
			}
			else if (strcmp(oper,"%%")==0) {
				int term_type = evalTerm_type(getChild(node), table);
				int factor_type = evalFactor_type(getSibling(getChild(node)), table);
				if (!((term_type == TYPE_INT) && (term_type == factor_type))) {
					printf("Type error in expression!\n");
				}
			}

			break;
		}
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
	// ---------------after getChild()---------------
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
			{popSymTab(table);
			break;}
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



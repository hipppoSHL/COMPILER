%{
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
int yylex(void);
int yyerror(char*);
%}

%union{
	int iVal;
	float rVal;
	char *sVal;
}
%token <iVal> INTEGER
%token <rVal> REAL
%token <sVal>ID STRING
%token BREAK CASE CHAR DEFAULT ELSE FLOAT FOR IF INT RETURN STRUCT SWITCH VOID WHILE
%token ADDASGN SUBASGN MULASGN DIVASGN MODASGN EQ NEQ LOE GOE LSHIFT RSHIFT AND OR INCREMENT DECREMENT

%%

Program: DeclarationList {
      		NODE *prog = nodeS("Program", nonterminal, _PROG);
		NODE *declist = pop();
		mkSubtree(prog, declist);
		push(prog);
	 }
       ;
DeclarationList: DeclarationList Declaration { 
	       		NODE *dec = pop();
			NODE *declist = pop();
			NODE *declist_tail = declist;
			while (declist_tail->sibling != NULL) declist_tail = declist_tail->sibling;
			mkSibling(declist_tail, dec);
			push(declist);
		 }
	       | Declaration {}
	       ;
Declaration: VarDeclaration {}
	   | FuncDeclaration {}
	   | StructDeclaration {}
	   ;
VarDeclaration: TypeSpecifier IDs ';' {
	     		NODE *vardec = nodeS("VarDeclaration", nonterminal, _VARDEC);
			NODE *ids = pop();
			NODE *type = pop();
			mkSubtree(vardec, type);
			mkSibling(type, ids);
			push(vardec);
	        }
	      ;
IDs: IDs ',' Value {
   	NODE *value = pop();
	NODE *ids = pop();
	NODE *ids_tail = ids;
	while (ids_tail->sibling != NULL) ids_tail = ids_tail->sibling;
	mkSibling(ids_tail, value);
	push(ids);
    }
   | Value {}
   ;
Value: Value '[' INTEGER ']' { 
     	NODE *integer = nodeI($3, terminal);
	NODE *value = pop();
	NODE *id_arr = NULL;	
	if (value->token.number == _ID) {
		id_arr = nodeS("ID_Arr", nonterminal, _ID_ARR);
		mkSubtree(id_arr, value);
		mkSibling(value, integer);
		push(id_arr);
	}
	else if (value->token.number == _ID_ARR) {
		id_arr = value;
		value = value->child;
		while (value->sibling != NULL) value = value->sibling;
		mkSibling(value, integer);
		push(id_arr);
	}
       }
     | ID {
	NODE *id = nodeS($1, terminal, _ID);
	push(id);
       }
     ;
FuncDeclaration: TypeSpecifier ID '(' Params ')' CompoundStatement { 
	       		NODE *fundec = nodeS("FuncDeclaration", nonterminal, _FUNDEC);
			NODE *cpdstmt = pop();
			NODE *params = pop();
			mkSubtree(fundec, pop()); //TypeSpecifier를 FuncDeclaration 의 자식으로 이어줌
			mkSibling(fundec->child, nodeS($2, terminal, _ID)); //ID를TypeSpecifier 의sibling 으로 이어줌
			mkSibling(fundec->child->sibling, params); //Params를 ID의 sibling으로 이어줌
			mkSibling(params, cpdstmt);
			push(fundec);
		 }
	       | TypeSpecifier ID '(' Params ')' ';' { 
			NODE *fundec = nodeS("FuncDeclaration", nonterminal, _FUNDEC);
			NODE *params = pop();
			mkSubtree(fundec, pop()); //TypeSpecifier를 FuncDeclaration의 자식으로 이어줌
			mkSibling(fundec->child, nodeS($2, terminal, _ID)); //ID를TypeSpecifier 의sibling 으로 이어줌
			mkSibling(fundec->child->sibling, params); //Params를 ID의 sibling으로 이어줌
			push(fundec);
		 }
	       ;
StructDeclaration: StructTypeDeclaration ';' { 
		 	NODE *strdec = nodeS("StructDeclaration", nonterminal, _STRDEC);
			NODE *strtype = pop();
			mkSubtree(strdec, strtype);
			push(strdec);
		   }
		 ;
StructTypeDeclaration: STRUCT ID '{' LocalDeclarationList '}' {
		     	NODE *strtype = nodeS("StructType", nonterminal, _STRTYPE);
			NODE *ldeclist = pop();
			mkSubtree(strtype, nodeS($2, terminal, _ID));
			mkSibling(strtype->child, ldeclist);
			push(strtype);
		       }
		     ;
Params: ParamList {
      		NODE *params = nodeS("Params", nonterminal, _PARAMS);
		NODE *param = pop();
		mkSubtree(params, param);
		push(params);	
	} 
      | VOID {
		NODE *params = nodeS("Params", nonterminal, _PARAMS);
		NODE *voidtype = nodeS("void", terminal, _TYPE);
		mkSubtree(params, voidtype);
		push(params);
	}
      | { push(nodeS("Params", nonterminal, _PARAMS)); }
      ;
ParamList: ParamList ',' Param {
		NODE *param = pop();
		NODE *paramlist = pop();
		NODE *paramlist_tail = paramlist;
		while (paramlist_tail->sibling != NULL) paramlist_tail = paramlist_tail->sibling;	 
		mkSibling(paramlist_tail, param);
		push(paramlist);
	   }
	 | Param {}
	 ;
Param: TypeSpecifier Value {
	NODE *param = nodeS("Param", nonterminal, _PARAM);
	NODE *val = pop();
	NODE *type = pop();
	mkSubtree(param, type);
	mkSibling(type, val);
	push(param);     
}
     ;
TypeSpecifier: INT { push(nodeS("int", terminal, _TYPE)); }
	     | VOID { push(nodeS("void", terminal, _TYPE)); }
	     | CHAR { push(nodeS("char", terminal, _TYPE)); }
	     | FLOAT { push(nodeS("float", terminal, _TYPE)); }
	     | StructType {}
	     ;
StructType: StructTypeDeclaration {}
	  | StructTypeReference {}
	  ;
StructTypeReference: STRUCT ID {
		   	NODE *strtype = nodeS("StructType", nonterminal, _STRTYPE);
			NODE *id = nodeS($2, terminal, _ID);
			mkSubtree(strtype, id);
			push(strtype);
		     }
		   ;
CompoundStatement: '{' LocalDeclarationList StatementList '}' {
		 	NODE *cpdstmt = nodeS("CompoundStatement", nonterminal, _CPDSTMT);
			NODE *stmtlist = pop();
			NODE *ldeclist = pop();
			mkSubtree(cpdstmt, ldeclist);
			mkSibling(ldeclist, stmtlist);
			push(cpdstmt);
		   }
		 ;
LocalDeclarationList: LocalDeclarationList VarDeclaration {
			NODE *vardec = pop();
			NODE *ldeclist = pop();
			NODE *vardec_tail = ldeclist->child;
			if (vardec_tail == NULL) {
				mkSubtree(ldeclist, vardec);
			}
			else {
				while (vardec_tail->sibling != NULL) vardec_tail = vardec_tail->sibling;
				mkSibling(vardec_tail, vardec);
			}
			push(ldeclist);	
		      }
		    | { push(nodeS("LocalDeclarationList", nonterminal, _LDECLIST)); }
		    ;
StatementList: StatementList Statement {
	     	NODE *stmt = pop();
		NODE *stmtlist = pop();
		NODE *stmt_tail = stmtlist->child;
		if (stmt_tail == NULL) {
			mkSubtree(stmtlist, stmt);
		}
		else {
			while (stmt_tail->sibling != NULL) stmt_tail = stmt_tail->sibling;
			mkSibling(stmt_tail, stmt);
		}
		push(stmtlist);	
	       }
	     | { push(nodeS("StatementList", nonterminal, _STMTLIST)); }
	     ;
Statement: MatchedStatement {}
	 | OpenStatement {}
	 ;
MatchedStatement: ExpressionStatement {}
		| ForStatement {}
		| WhileStatement {}
		| ReturnStatement {}
		| CompoundStatement {}
		| BreakStatement {}
		| SwitchStatement {}
		| IF '(' Expression ')' MatchedStatement ELSE MatchedStatement {
			NODE *ifstmt = nodeS("IfStatement", nonterminal, _IFSTMT);
			NODE *false_stmt = pop();
			NODE *true_stmt = pop();
			mkSubtree(ifstmt, pop());
			mkSibling(ifstmt->child, true_stmt);
			mkSibling(true_stmt, false_stmt);
			push(ifstmt);
		  }
		;
OpenStatement: IF '(' Expression ')' Statement {
		NODE *ifstmt = nodeS("IfStatement", nonterminal, _IFSTMT);
		NODE *stmt = pop();
		mkSubtree(ifstmt, pop());
		mkSibling(ifstmt->child, stmt);
		push(ifstmt);
	       }
	     | IF '(' Expression ')' MatchedStatement ELSE OpenStatement {
		NODE *ifstmt = nodeS("IfStatement", nonterminal, _IFSTMT);
		NODE *openstmt = pop();
		NODE *matchedstmt = pop();
		mkSubtree(ifstmt, pop());
		mkSibling(ifstmt->child, matchedstmt);
		mkSibling(matchedstmt, openstmt);
		push(ifstmt);
	       }
	     ;
SwitchStatement: SWITCH '(' Expression ')' '{' CaseList DefaultCase '}' {
			NODE *swstmt = nodeS("SwitchStatement", nonterminal, _SWSTMT);
			NODE *defaultcase = pop();
			NODE *caselist = pop();
			NODE *caselist_tail = caselist;
			while (caselist_tail->sibling != NULL) caselist_tail = caselist_tail->sibling;
			mkSubtree(swstmt, pop());
			mkSibling(swstmt->child, caselist);
			mkSibling(caselist_tail, defaultcase);
			push(swstmt);
		 }
	       ;
CaseList: CaseList CASE INTEGER ':' StatementList {
		NODE *stmtlist = pop();
		NODE *integer = nodeI($3, terminal);
		NODE *newcase = nodeS("case", terminal, _CASE);
		NODE *caselist = pop();
		NODE *caselist_tail = caselist;
		while (caselist_tail->sibling != NULL) caselist_tail = caselist_tail->sibling;
		mkSibling(caselist_tail, newcase);
		mkSubtree(newcase, integer);
		mkSibling(integer, stmtlist);
		push(caselist);
	  }
	| CASE INTEGER ':' StatementList {
		NODE *caselist = nodeS("case", terminal, _CASE);
		NODE *stmtlist = pop();
		NODE *integer = nodeI($2, terminal);
		mkSubtree(caselist, integer);
		mkSibling(integer, stmtlist);
		push(caselist);
	  }
	;
DefaultCase: DEFAULT ':' StatementList {
	   	NODE *defaultstmt = nodeS("default", terminal, _DEFAULT);
		mkSubtree(defaultstmt, pop());
		push(defaultstmt);
	     }
	   | { push(nodeS("default", terminal, _DEFAULT)); }
	   ;
ReturnStatement: RETURN Expression ';' {
			NODE *rtstmt = nodeS("ReturnStatement", nonterminal, _RTSTMT);
			mkSubtree(rtstmt, pop());
			push(rtstmt);
		 }
	       | RETURN ';' { push(nodeS("ReturnStatement", nonterminal, _RTSTMT)); }
	       ;
BreakStatement: BREAK ';' { push(nodeS("BreakStatement", nonterminal, _BRKSTMT));}
	      ;
ExpressionStatement: Expression ';' {}
		   | ';' {}
		   ;
Expression: AssignExpression {}
	  | SimpleExpression {}
	  ;
AssignExpression: Variable Assign Expression {
			NODE *exp = pop();
			NODE *assign = pop();
			NODE *var = pop();
			mkSubtree(assign, var);
			mkSibling(var, exp);
			push(assign);
		  }
		;
Variable: ID { push(nodeS($1, terminal, _ID)); }
	| ID SelectorList {
		NODE *id_slts = nodeS("IDSelectors", nonterminal, _ID_SLTS);
		NODE *sltlist = pop();
		mkSubtree(id_slts, nodeS($1, terminal, _ID));
		mkSibling(id_slts->child, sltlist);
		push(id_slts);
	  }
	;
SelectorList: SelectorList Selector {
	    	NODE *selector = pop();
		NODE *sltlist = pop();
		NODE *slt_tail = sltlist->child;
		while (slt_tail->sibling != NULL) slt_tail = slt_tail->sibling;
		mkSibling(slt_tail, selector);
		push(sltlist);
	      }
	    | Selector {
		NODE *sltlist = nodeS("SelectorList", nonterminal, _SLTLIST);
		mkSubtree(sltlist, pop());
		push(sltlist);
	      }
	    ;
Selector: '.' ID {
		NODE *strmbr = nodeS("StructMember", terminal, _STRMBR);
		mkSubtree(strmbr, nodeS($2, terminal, _ID));
		push(strmbr);
	  }
	| '[' Expression ']' {
		NODE *arrindex = nodeS("ArrayIndex", terminal, _ARRINDEX);
		mkSubtree(arrindex, pop());
		push(arrindex);
	  }
	;
SimpleExpression: SimpleExpression OR AndExpression {
			NODE *andexp = pop();
			NODE *orop = nodeS("||", terminal, _OPER);
			mkSubtree(orop, pop());
			mkSibling(orop->child, andexp);
			push(orop);
		  }
		| AndExpression {}
		;
AndExpression: AndExpression AND RelExpression { 
	     	NODE *relexp = pop();
		NODE *andop = nodeS("&&", terminal, _OPER);
		mkSubtree(andop, pop());
		mkSibling(andop->child, relexp);
		push(andop);
	       }
	     | RelExpression {}
	     ;
RelExpression: RelExpression RelOperator AddExpression {
	     	NODE *addexp = pop();
		NODE *relop = pop();
		mkSubtree(relop, pop());
		mkSibling(relop->child, addexp);
		push(relop);
	       }
	     | AddExpression {}
	     ;
RelOperator: '<' { push(nodeS("<", terminal, _OPER)); }
	   | LOE { push(nodeS("<=", terminal, _OPER)); }
	   | '>' { push(nodeS(">", terminal, _OPER)); }
	   | GOE { push(nodeS(">=", terminal, _OPER)); }
	   | EQ { push(nodeS("==", terminal, _OPER)); }
	   | NEQ { push(nodeS("!=", terminal, _OPER)); }
	   ;
AddExpression: AddExpression Oper1 Term {
	     	NODE *term = pop();
		NODE *oper1 = pop();
		mkSubtree(oper1, pop());
		mkSibling(oper1->child, term);
		push(oper1);
	       }
	     | Term {}
	     ;
Oper1: '+' { push(nodeS("+", terminal, _OPER)); }
     | '-' { push(nodeS("-", terminal, _OPER)); }
     ;
Term: Term Oper2 Factor {
    	NODE *factor = pop();
	NODE *oper2 = pop();
	mkSubtree(oper2, pop());
	mkSibling(oper2->child, factor);
	push(oper2);
      }
    | Factor {}
    ;
Oper2: '*' { push(nodeS("*", terminal, _OPER)); }
     | '/' { push(nodeS("/", terminal, _OPER)); }
     | '%' { push(nodeS("%", terminal, _OPER)); }
     ;
Factor: '(' Expression ')' {}
      | FunctionCall {}
      | '-' Factor {
		NODE *factor = pop();
		NODE *neg = nodeS("-", terminal, _OPER);
		mkSubtree(neg, factor);
		push(neg);
	}
      | Variable {}
      | Variable IncDec {
		NODE *incdecexp = nodeS("IncDecExpression", nonterminal, _INCDEC_EXP);
		NODE *incdec = pop();
		mkSubtree(incdecexp, pop());
		mkSibling(incdecexp->child, incdec);
		push(incdecexp);
	}
      | IncDec Variable {
		NODE *incdecexp = nodeS("IncDecExpression", nonterminal, _INCDEC_EXP);
		NODE *var = pop();
		mkSubtree(incdecexp, pop());
		mkSibling(incdecexp->child, var);
		push(incdecexp);
	}
      | NumberLiteral {}
      ;
NumberLiteral: INTEGER { push(nodeI($1, terminal)); }
	     | REAL { push(nodeR($1, terminal)); }
	     ;
IncDec: INCREMENT { push(nodeS("++", terminal, _OPER)); }
      | DECREMENT { push(nodeS("--", terminal, _OPER)); }
      ;
WhileStatement: WHILE '(' Expression ')' CompoundStatement {
			NODE *whlstmt = nodeS("WhileStatement", nonterminal, _WHLSTMT);
			NODE *cpdstmt = pop();
			mkSubtree(whlstmt, pop());
			mkSibling(whlstmt->child, cpdstmt);
			push(whlstmt);
		}
	      | WHILE '(' Expression ')' ';' {
			NODE *whlstmt = nodeS("WhileStatement", nonterminal, _WHLSTMT);
			mkSubtree(whlstmt, pop());
			push(whlstmt);
		}
	      ;
ForStatement: FOR '(' Expression ';' Expression ';' Expression ')' ';' {
		NODE *forstmt = nodeS("ForStatement", nonterminal, _FORSTMT);
		NODE *exp3 = pop();
		NODE *exp2 = pop();
		mkSubtree(forstmt, pop());
		mkSibling(forstmt->child, exp2);
		mkSibling(exp2, exp3);
		push(forstmt);
	      }
	    | FOR '(' Expression ';' Expression ';' Expression ')' CompoundStatement {
		NODE *forstmt = nodeS("ForStatement", nonterminal, _FORSTMT);
		NODE *cpdstmt = pop();
		NODE *exp3 = pop();
		NODE *exp2 = pop();
		mkSubtree(forstmt, pop());
		mkSibling(forstmt->child, exp2);
		mkSibling(exp2, exp3);
		mkSibling(exp3, cpdstmt);
		push(forstmt);
	      }
	    ;
FunctionCall: ID '(' Arguments ')' {
		NODE *funcall = nodeS("FunctionCall", nonterminal, _FUNCALL);
		NODE *id = nodeS($1, terminal, _ID);
		mkSubtree(funcall, id);
		mkSibling(id, pop());
		push(funcall);
	      }
	    ;
Arguments: ArgumentList {
		NODE *args = nodeS("Arguments", nonterminal, _ARGS);
		mkSubtree(args, pop());
		push(args);
	   }
	 | { push(nodeS("Arguments", nonterminal, _ARGS));}
	 ;
ArgumentList: ArgumentList ',' Expression {
		NODE *exp = pop();
		NODE *arglist = pop();
		NODE *arglist_tail = arglist;
		while (arglist_tail->sibling != NULL) arglist_tail = arglist_tail->sibling;
		mkSibling(arglist_tail, exp);
		push(arglist);
	      }
	    | ArgumentList ',' STRING {
		NODE *str = nodeS($3, terminal, _STRING);
		NODE *arglist = pop();
		NODE *arglist_tail = arglist;
		while (arglist_tail->sibling != NULL) arglist_tail = arglist_tail->sibling;
		mkSibling(arglist_tail, str);
		push(arglist);
	      }
	    | Expression {}
	    | STRING { push(nodeS($1, terminal, _STRING)); }
	    ;
Assign: '=' { push(nodeS("=", terminal, _OPER)); }
      | ADDASGN { push(nodeS("+=", terminal, _OPER)); }
      | SUBASGN { push(nodeS("-=", terminal, _OPER)); }
      | MULASGN { push(nodeS("*=", terminal, _OPER)); }
      | DIVASGN { push(nodeS("/=", terminal, _OPER)); }
      | MODASGN { push(nodeS("%=", terminal, _OPER)); }
      ;
%%
int main(int argc, char* argv[]){
	if(argc == 1)	exit(0);
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	initStack();
	yyparse();
	printTree(pop());
	fclose(yyin);
	return 0;
}


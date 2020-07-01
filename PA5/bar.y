%{
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"
STACK *stack;
int yylex(void);
int yyerror(char*);
void dfs(ASTNode *node);
int check;
int isSyntaxError;
%}

%union{
	int iVal;
	float rVal;
	char* sVal;
}

%token <iVal> INTEGER CHAR
%token <rVal> REAL
%token <sVal> ID STRING OPERATOR
%token BREAK CASE CHAR_K DEFAULT ELSE FLOAT FOR IF RETURN SWITCH VOID WHILE INT DOUBLE ASGN ADD_ASGN SUB_ASGN MUL_ASGN DIV_ASGN MOD_ASGN EQ_CMP EQ_NOT EQ_LES EQ_BIG LSHIFT RSHIFT AND OR INCREMENT DECREMENT ADD SUB MUL DIV MOD LESS BIGG

%%
Program: DeclarationList { 
	ASTNode *prog = makeASTNode(_PROG, NO_TYPE);
	ASTNode *declist = pop(stack);
	push(stack, setChild(prog, declist));
}
	   ;
DeclarationList: DeclarationList Declaration {
	ASTNode *dec = pop(stack);
	ASTNode *declist = pop(stack);
	push(stack, setLastSibling(declist, dec));
}
	| Declaration {}
	;
Declaration: VarDeclaration {}
		   | FuncDeclaration {}
		   ;

FuncDeclaration: TypeSpecifier FuncID '(' Params ')' CompoundStmt {
	ASTNode *cpdstmt = pop(stack);
	ASTNode *params = pop(stack);
	ASTNode *funcid = pop(stack);
	ASTNode *funcdec = makeASTNode(_FUNCDEC, NO_TYPE);
	funcdec = setChild(funcdec, setSibling(pop(stack), setSibling(funcid, setSibling(params, cpdstmt))));
	push(stack, funcdec);
}
| TypeSpecifier FuncID '(' Params ')' ';' {
	ASTNode *funcdec = makeASTNode(_FUNCDEC, NO_TYPE);
	ASTNode *params = pop(stack);
	ASTNode *funcid = pop(stack);
	funcdec = setChild(funcdec, setSibling(setSibling(pop(stack), funcid), params));
	push(stack, funcdec);
}
;

FuncID: ID {
		push(stack, makeASTNodeID($1, NO_TYPE)); 
	}
	;

Params: ParamList { 
		ASTNode *params = makeASTNode(_PARAMS, NO_TYPE);
		push(stack, setChild(params, pop(stack)));
	  }
	  | VOID { 
		ASTNode *params = makeASTNode(_PARAMS, NO_TYPE);
		ASTNode *voidtype = makeASTNode(_TYPE, TYPE_VOID);
		push(stack, setChild(params, voidtype));
	  }
	  | { push(stack, makeASTNode(_PARAMS, NO_TYPE)); }
	  ;
ParamList: ParamList ',' Param { 
		   ASTNode *param = pop(stack);
		   ASTNode *paramlist = pop(stack);
		   push(stack, setLastSibling(paramlist, param));
 		 }
		 | Param {}
		 ;
Param: TypeSpecifier Value {
	   ASTNode *param = makeASTNode(_PARAM, NO_TYPE);
	   ASTNode *value = pop(stack);
	   ASTNode *type = pop(stack);
	   push(stack, setChild(param, setSibling(type, value)));
     }
	 ;
CompoundStmt: '{' LocalDeclarationList StmtList '}' { 
				ASTNode *cpdstmt = makeASTNode(_CPDSTMT, NO_TYPE);
				ASTNode *stmtlist = pop(stack);
				ASTNode *ldeclist = pop(stack);
				push(stack, setChild(cpdstmt, setSibling(ldeclist, stmtlist)));
 			}
	        ;
LocalDeclarationList: LocalDeclarationList VarDeclaration {
						ASTNode *vardec = pop(stack);
						ASTNode *ldeclist = pop(stack);
						if (getChild(ldeclist)) {
							ldeclist = setChild(ldeclist,setLastSibling(getChild(ldeclist), vardec));
							push(stack, ldeclist);
						} else {
							push(stack, setChild(ldeclist, vardec));
						}
					}
					| { push(stack, makeASTNode(_LDECLIST, NO_TYPE)); }
					;
VarDeclaration: TypeSpecifier IDs ';' {
				ASTNode *vardec = makeASTNode(_VARDEC, NO_TYPE);
			  	ASTNode *ids = pop(stack);
				ASTNode *type = pop(stack);
				push(stack, setChild(vardec, setSibling(type, ids)));
			  }
			  ;
TypeSpecifier: INT	{ push(stack, makeASTNode(_TYPE, TYPE_INT)); }
	| VOID 	{ push(stack, makeASTNode(_TYPE, TYPE_VOID)); }
	| CHAR_K	{ push(stack, makeASTNode(_TYPE, TYPE_INT)); }
	| FLOAT	{ push(stack, makeASTNode(_TYPE, TYPE_FLOAT)); }
	;
IDs: IDs ',' Value	{ 
     ASTNode *value = pop(stack);
	 ASTNode *ids = pop(stack);
	 push(stack, setLastSibling(ids, value));
   }
   | Value			{}
   ;
Value: ID '[' INTEGER ']'	{
	   ASTNode *value = makeASTNode(_VALUE, NO_TYPE);
	   ASTNode *integer = makeASTNodeINT($3);
	   ASTNode *id = makeASTNodeID($1, NO_TYPE);
	   push(stack, setChild(value, setSibling(id, integer)));
	 }
	 | ID {
		push(stack, makeASTNodeID($1, NO_TYPE));
	 }
	 ;
StmtList: StmtList Stmt	{
			ASTNode *stmt = pop(stack);
			ASTNode *stmtlist = pop(stack);
			if (getChild(stmtlist)) {
				stmtlist = setChild(stmtlist, setLastSibling(getChild(stmtlist),stmt));
				push(stack, stmtlist);
			} else {
				push(stack, setChild(stmtlist, stmt));
			}
		}
		| { push(stack, makeASTNode(_STMTLIST, NO_TYPE)); }
		;
Stmt: MatchedStmt	{}
	| OpenStmt		{}
	;
MatchedStmt: ExprStmt		{}
		   | ForStmt		{}
		   | WhileStmt		{}
		   | ReturnStmt		{}
		   | CompoundStmt	{}
		   | BreakStmt		{}
		   | SwitchStmt		{}
		   | IF '(' Expr ')' MatchedStmt ELSE MatchedStmt {
			   ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			   ASTNode *false_stmt = pop(stack);
			   ASTNode *true_stmt = pop(stack);
			   ASTNode *expr = pop(stack);
			   push(stack, setChild(ifstmt, setSibling(expr, (setSibling(true_stmt, false_stmt)))));
		   }
		   ;
OpenStmt: IF '(' Expr ')' Stmt	{
			ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			ASTNode *stmt = pop(stack);
			ASTNode *expr = pop(stack);
			push(stack, setChild(ifstmt, setSibling(expr, stmt)));
		}
		| IF '(' Expr ')' MatchedStmt ELSE OpenStmt	{
			ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			ASTNode *openstmt = pop(stack);
			ASTNode *matchedstmt = pop(stack);
			ASTNode *expr = pop(stack);
			push(stack, setChild(ifstmt, setSibling(expr, setSibling(matchedstmt, openstmt))));
		}
		;
SwitchStmt: SWITCH '(' Expr ')' '{' CaseList DefaultCase '}' {
		    ASTNode *swstmt = makeASTNode(_SWSTMT, NO_TYPE);
			ASTNode *defaultcase = pop(stack);
			ASTNode *caselist = pop(stack);
			ASTNode *expr = pop(stack);
			setSibling(expr, caselist);
			setLastSibling(caselist, defaultcase);
			push(stack, setChild(swstmt, expr));
		  }
		  ;
CaseList: CaseList CASE INTEGER ':' StmtList	{
			ASTNode *stmtlist = pop(stack);
			ASTNode *integer = makeASTNodeINT($3);
			ASTNode *caselist = pop(stack);
			push(stack, setChild(caselist, setSibling(integer, stmtlist)));
		}
		| CASE INTEGER ':' StmtList	{
			ASTNode *caselist = makeASTNode(_CASE, NO_TYPE);
			ASTNode *stmtlist = pop(stack);
			ASTNode *integer = makeASTNodeINT($2);
			push(stack, setChild(caselist, setSibling(integer, stmtlist)));
		}
		;
DefaultCase: DEFAULT ':' StmtList	{
		       ASTNode *defaultstmt = makeASTNode(_DEFAULT, NO_TYPE);
			   ASTNode *stmtlist = pop(stack);
			   push(stack, setChild(defaultstmt, stmtlist));
		   }
		   | { push(stack, makeASTNode(_DEFAULT, NO_TYPE)); }
		   ;
ReturnStmt: RETURN Expr ';'	{
		    ASTNode *rtstmt = makeASTNode(_RTSTMT, NO_TYPE);
			push(stack, setChild(rtstmt, pop(stack)));
		  }
		  | RETURN ';'	{
			push(stack, makeASTNode(_RTSTMT, NO_TYPE));
		  }
		  ;
BreakStmt: BREAK ';'	{
			push(stack, makeASTNode(_BRKSTMT, NO_TYPE));
		 }
		 ;
ExprStmt: Expr ';'	{}
		| ';'		{}
		;
Expr: AssignExpr	{}
	| SimpleExpr	{}
	;
AssignExpr: Variable ASGN Expr		{
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable ADD_ASGN Expr	{
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("+=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable SUB_ASGN Expr	{
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("-=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable MUL_ASGN Expr	{
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("*=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable DIV_ASGN Expr	{
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("/=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable MOD_ASGN Expr	{
			ASTNode *expr = pop(stack);
			ASTNode *asgn = makeASTNodeOP("%=", NO_TYPE);
			ASTNode *variable = pop(stack);
			push(stack, setChild(asgn, setSibling(variable, expr)));
		  }
		  ;
Variable: ID '[' Expr ']'	{
			ASTNode *idarr = makeASTNode(_ID_ARR, NO_TYPE);
			ASTNode *expr = pop(stack);
			ASTNode *id = makeASTNodeID($1, NO_TYPE);
			push(stack, setChild(idarr, setSibling(id, expr)));
		}
		| ID	{ push(stack, makeASTNodeID($1, NO_TYPE)); }
		;
SimpleExpr: SimpleExpr OR AndExpr	{
			ASTNode *andexpr = pop(stack);
			ASTNode *orop = makeASTNodeOP("||", NO_TYPE);
			push(stack, setChild(orop, setSibling(pop(stack), andexpr)));
		  }
	      | AndExpr	{}
		  ;
AndExpr: AndExpr AND RelExpr	{
			ASTNode *relexpr = pop(stack);
			ASTNode *andop = makeASTNodeOP("&&", NO_TYPE);
			push(stack, setChild(andop, setSibling(pop(stack), relexpr)));
	   }
	   | RelExpr	{}
	   ;
RelExpr: RelExpr LESS AddExpr	{
			ASTNode *relop = makeASTNodeOP("<", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
	   | RelExpr EQ_LES AddExpr	{
			ASTNode *relop = makeASTNodeOP("<=", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
	   | RelExpr BIGG AddExpr	{
			ASTNode *relop = makeASTNodeOP(">", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
	   | RelExpr EQ_BIG AddExpr	{
			ASTNode *relop = makeASTNodeOP(">=", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
	   | RelExpr EQ_CMP AddExpr	{
			ASTNode *relop = makeASTNodeOP("==", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
	   | RelExpr EQ_NOT AddExpr	{
			ASTNode *relop = makeASTNodeOP("!=", NO_TYPE);
			ASTNode *addexpr = pop(stack);
			push(stack, setChild(relop, setSibling(pop(stack), addexpr)));
	   }
	   | AddExpr	{}
	   ;
AddExpr: AddExpr ADD Term	{
			ASTNode *term = pop(stack);
			ASTNode *oper = makeASTNodeOP("+", NO_TYPE);
			push(stack, setChild(oper, setSibling(pop(stack), term)));
	   }
	   | AddExpr SUB Term	{
			ASTNode *term = pop(stack);
			ASTNode *oper = makeASTNodeOP("-", NO_TYPE);
			push(stack, setChild(oper, setSibling(pop(stack), term)));
	   }
	   | Term	{}
	   ;
Term: Term MUL Factor	{ 
		ASTNode *factor = pop(stack);
		ASTNode *oper = makeASTNodeOP("*", NO_TYPE);
		push(stack, setChild(oper, setSibling(pop(stack), factor)));
 	}
	| Term DIV Factor	{ 
		ASTNode *factor = pop(stack);
		ASTNode *oper = makeASTNodeOP("/", NO_TYPE);
		push(stack, setChild(oper, setSibling(pop(stack), factor)));
 	}
	| Term MOD Factor	{ 
		ASTNode *factor = pop(stack);
		ASTNode *oper = makeASTNodeOP("%", NO_TYPE);
		push(stack, setChild(oper, setSibling(pop(stack), factor)));
 	}
	| Factor			{}
	;
Factor: '(' Expr ')'		{}
	  | FunctionCall		{}
	  | SUB Factor			{
		  ASTNode *factor = pop(stack);
		  ASTNode *neg = makeASTNodeOP("-", NO_TYPE);
		  push(stack, setChild(neg, factor));
	  }
	  | Variable			{}
	  | Variable IncDec		{
		  ASTNode *incdecexp = makeASTNode(_INCDEC_EXP, NO_TYPE);
		  ASTNode *incdec = pop(stack);
		  push(stack, setChild(incdecexp, setSibling(pop(stack), incdec)));
	  }
	  | IncDec Variable		{
		  ASTNode *incdecexp = makeASTNode(_INCDEC_EXP, NO_TYPE);
		  ASTNode *variable = pop(stack);
		  push(stack, setChild(incdecexp, setSibling(pop(stack), variable)));
	  }
	  | NumberLiteral		{}
	  ;
NumberLiteral: INTEGER	{ push(stack, makeASTNodeINT($1)); }
			 | REAL		{ push(stack, makeASTNodeREAL($1)); }
			 ;
IncDec: INCREMENT	{ push(stack, makeASTNodeOP("++", NO_TYPE)); }
	  | DECREMENT	{ push(stack, makeASTNodeOP("--", NO_TYPE)); }
	  ;
WhileStmt: WHILE '(' Expr ')' CompoundStmt	{
			ASTNode *whlstmt = makeASTNode(_WHLSTMT, NO_TYPE);
			ASTNode *cpdstmt = pop(stack);
			ASTNode *expr = pop(stack);
			push(stack, setChild(whlstmt, setSibling(expr, cpdstmt)));
		 }
		 | WHILE '(' Expr ')' ';'	{
			 ASTNode *whlstmt = makeASTNode(_WHLSTMT, NO_TYPE);
			 ASTNode *expr = pop(stack);
			 push(stack, setChild(whlstmt, expr));
		 }
		 ;
ForStmt: FOR '(' Expr ';' Expr ';' Expr ')' CompoundStmt	{
			ASTNode *forstmt = makeASTNode(_FORSTMT, NO_TYPE);
			ASTNode *cpdstmt = pop(stack);
			ASTNode *expr3 = pop(stack);
			ASTNode *expr2 = pop(stack);
			ASTNode *expr1 = pop(stack);
			expr1 = setSibling(expr1, setSibling(expr2, setSibling(expr3, cpdstmt)));
			push(stack, setChild(forstmt, expr1));
	   }
	   | FOR '(' Expr ';' Expr ';' Expr ')' ';'	{
		    ASTNode *forstmt = makeASTNode(_FORSTMT, NO_TYPE);
		    ASTNode *expr3 = pop(stack);
			ASTNode *expr2 = pop(stack);
			ASTNode *expr1 = pop(stack);
			push(stack, setChild(forstmt, setSibling(expr1, setSibling(expr2, expr3))));
	   }
	   ;
FunctionCall: ID '(' Arguments ')'	{
				ASTNode *funccall = makeASTNode(_FUNCCALL, NO_TYPE);
				ASTNode *id = makeASTNodeID($1, NO_TYPE);
				ASTNode *arguments = pop(stack);
				push(stack, setChild(funccall, setSibling(id, arguments)));
			}
		    ;
Arguments: ArgumentList	{
			ASTNode *args = makeASTNode(_ARGS, NO_TYPE);
			push(stack, setChild(args, pop(stack)));
		 }
	     | { push(stack, makeASTNode(_ARGS, NO_TYPE)); }
		 ;
ArgumentList: ArgumentList ',' Expr	{
				ASTNode *expr = pop(stack);
				ASTNode *arglist = pop(stack);
				push(stack, setLastSibling(arglist, expr));
			}
			| Expr	{}
			

%%
void dfs(ASTNode *node) {
	int node_type = getTkNum(node);
	int check2 = 0;
	if (node_type == _FORSTMT || node_type == _WHLSTMT || node_type == _SWSTMT) {
		check++;
		check2 = 1;
	} 
	
	if (node_type == _BRKSTMT) {
		if (check != 1) {
			isSyntaxError = 1;
			return;
		}
	}
	
	ASTNode *child = getChild(node);
	while (child != 0) {
		dfs(child);
		child = getSibling(child);
	}
	if (check2 == 1) check--;
	ASTNode *sibling = getSibling(node);
	while (sibling != 0) {
		dfs(sibling);
		sibling = getSibling(sibling);
	}
	return;
}

int main(int argc, char *argv[]){
	extern FILE *yyin;
	extern FILE *yyout;
	ASTNode *root = 0;
	stack = initStack();

	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);

	root = pop(stack);
	yyout = fopen(genOutputFN(argv[1]), "w");
	buildTAC(root);
	fclose(yyout);
	return 0;
}


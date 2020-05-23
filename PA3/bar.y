%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
STACK *stack;
int yylex(void);
int yyerror(char*);
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
	ASTNode *declist = pop();
	push(setChild(prog, declist));
}
	   ;
DeclarationList: DeclarationList Declaration {
	ASTNode *dec = pop();
	ASTNode *declist = pop();
	if (getChild(declist)) {
		declist = setLastSibling(getChild(declist), dec);
		push(declist);
	} else {
		push(setChild(declist, dec));
	}
}
	| Declaration {}
	;
Declaration: VarDeclaration {}
		   | FuncDeclaration {}
		   ;

FuncDeclaration: Type FuncID '(' Params ')' CompoundStmt {
	ASTNode *cpdstmt = pop();
	ASTNode *params = pop();
	ASTNode *funcid = pop();
	setChild(funcdec, setSibling(setSibling(setSibling(pop(), id), params), cpdstmt));
	push(funcdec);
}
| Type FuncID '(' Params ')' ';' {
	ASTNode *funcdec = makeASTNode(_FUNDEC, NO_TYPE);
	ASTNode *params = pop();
	ASTNode *funcid = pop();
	setChild(funcdec, setSibling(setSibling(pop(), funcid), params));
	push(funcdec);
}
;

FuncID: ID { push(makeASTNodeID($1, NO_TYPE)); }
	  ;

Params: ParamList { 
		ASTNode *params = makeASTNode(_PARAMS, NO_TYPE);
		push(setChild(params, pop()));
	  }
	  | VOID { 
		ASTNode *params = makeASTNode(_PARAMS, NO_TYPE);
		ASTNode *voidtype = makeASTNode(_TYPE, TYPE_VOID);
		push(setChild(params, voidtype));
	  }
	  | { push(makeASTNode(_PARAMS, NO_TYPE)); }
	  ;
ParamList: ParamList ',' Param { 
		   ASTNode *param = pop();
		   ASTNode *paramlist = pop();
		   if (getChild(paramlist)) {
			   paramlist = setLastSibling(getChild(paramlist), param);
		 	   push(paramlist);
		   } else {
		 	   push(setChild(paramlist, param));
		   }
 		 }
		 | Param {}
		 ;
Param: Type Value {
	   ASTNode *param = makeASTNode(_PARAM, NO_TYPE);
	   ASTNode *value = pop();
	   ASTNode *type = pop();
	   push(setChild(param, setSibling(type, value)));
     }
	 ;
CompoundStmt: '{' LocalDeclarationList StmtList '}' { 
				ASTNode *cpdstmt = makeASTNode(_CPDSTMT, NO_TYPE);
				ASTNode *stmtlist = pop();
				ASTNode *ldeclist = pop();
				push(setChild(cpdstmt, setSibling(ldeclist, stmtlist)));
 			}
	        ;
LocalDeclarationList: LocalDeclarationList VarDeclaration {
						ASTNode *vardec = pop();
						ASTNode *ldeclist = pop();
						if (getChild(ldeclist)) {
							ldeclist = setLastSibling(getChild(ldeclist), vardec);
							push(ldeclist);
						} else {
							push(setChild(ldeclist, vardec));
						}
					}
					| { ASTNode *ldeclist = makeASTNode(_LDECLIST, NO_TYPE); }
					;
VarDeclaration: Type IDs ';' {
				ASTNode *vardec = makeASTNode(_VARDEC, NO_TYPE);
			  	ASTNode *ids = pop();
				ASTNode *type = pop();
				push(setChild(vardec, setSibling(type, ids)));
			  }
			  ;
Type: INT	{ push(makeASTNode(_TYPE, TYPE_INT)); }
	| VOID 	{ push(makeASTNode(_TYPE, TYPE_VOID)); }
	| CHAR_K	{ push(makeASTNode(_TYPE, NO_TYPE)); }
	| FLOAT	{ push(makeASTNode(_TYPE, TYPE_FLOAT)); }
	;
IDs: IDs ',' Value	{ 
     ASTNode *value = pop();
	 ASTNode *ids = pop();
	 if (getChild(ids)) {
		 ids = setLastSibling(getChild(ids), value);
		 push(ids);
	 } else {
		 push(setChild(ids, value));
	 }
   }
   | Value			{}
   ;
Value: ID '[' INTEGER ']'	{
	   ASTNode *value = makeASTNode(_VALUE, NO_TYPE);
	   ASTNode *integer = makeASTNodeINT($3);
	   ASTNode *id = makeASTNodeID($1, NO_TYPE);
	   push(setChild(value, setSibling(id, integer)));
	 }
	 | ID {
		ASTNode *id = makeASTNodeID($1, NO_TYPE);
	 }
	 ;
StmtList: StmtList Stmt	{
			ASTNode *stmt = pop();
			ASTNode *stmtlist = pop();
			if (getChild(stmtlist)) {
				stmtlist = setLastSibling(getchild(stmtlist),stmt);
				push(stmtlist);
			} else {
				push(setChild(stmtlist, stmt));
			}
		}
		| { push(makeASTNode(_STMTLIST, NO_TYPE)); }
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
			   // 이부분 잘 모르겠음... 이상...
			   ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			   ASTNode *false_stmt = pop();
			   ASTNode *true_stmt = pop();
			   ASTNode *expr = pop();
			   push(setChild(ifstmt, setSibling(expr, (setSibling(true_stmt, false_stmt)))));
		   }
		   ;
OpenStmt: IF '(' Expr ')' Stmt	{
			ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			ASTNode *stmt = pop();
			ASTNode *expr = pop();
			push(setChild(ifstmt, setSibling(expr, stmt)));
		}
		| IF '(' Expr ')' MatchedStmt ELSE OpenStmt	{
			ASTNode *ifstmt = makeASTNode(_IFSTMT, NO_TYPE);
			ASTNode *openstmt = pop();
			ASTNode *matchedstmt = pop();
			ASTNode *expr = pop();
			push(setChild(ifstmt, setSibling(expr, setSibling(matchedstmt, openstmt))));
		}
		;
SwitchStmt: SWITCH '(' Expr ')' '{' CaseList DefaultCase '}' {
		    ASTNode *swstmt = makeASTNode(_SWSTMT, NO_TYPE);
			ASTNode *defaultcase = pop();
			ASTNode *caselist = pop();
			ASTNode *expr = setSibling(pop(), setSibling(caselist, defaultcase));
			push(setChild(swstmt, expr));
		  }
		  ;
CaseList: CaseList CASE INTEGER ':' StmtList	{
			ASTNode *stmtlist = pop();
			ASTNode *integer = makeASTNodeINT($3);
			ASTNode *caselist = pop();
			push(setChild(caselist, setSibling(integer, stmtlist)));
		}
		| CASE INTEGER ':' StmtList	{
			ASTNode *caselist = makeASTNodeID(_CASE, NO_TYPE);
			ASTNode *stmtlist = pop();
			ASTNode *integer = makeASTNodeINT($2);
			push(setChild(caselist, setSibling(integer, stmtlist)));
		}
		;
DefaultCase: DEFAULT ':' StmtList	{
		       ASTNode *defaultstmt = makeASTNode(_DEFAULT, NO_TYPE);
			   ASTNode *stmtlist = pop();
			   push(setChild(defaultstmt, stmtlist));
		   }
		   | { push(makeASTNode(_DEFAULT, NO_TYPE)); }
		   ;
ReturnStmt: RETURN Expr ';'	{
		    ASTNode *rtstmt = makeASTNode(_RTSTMT, NO_TYPE);
			push(setChild(rtstmt, pop()));
		  }
		  | RETURN ';'	{
			push(makeASTNode(_RTSTMT, NO_TYPE));
		  }
		  ;
BreakStmt: BREAK ';'	{
			// 이상함... 
			push(makeASTNode(_BRKSTMT, NO_TYPE));
		 }
		 ;
ExprStmt: Expr ';'	{}
		| ';'		{}
		;
Expr: AssignExpr	{}
	| SimpleExpr	{}
	;
AssignExpr: Variable ASGN Expr		{
			ASTNode *expr = pop();
			ASTNode *asgn = pop();
			ASTNode *variable = pop();
			push(setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable ADD_ASGN Expr	{
			ASTNode *expr = pop();
			ASTNode *asgn = pop();
			ASTNode *variable = pop();
			push(setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable SUB_ASGN Expr	{
			ASTNode *expr = pop();
			ASTNode *asgn = pop();
			ASTNode *variable = pop();
			push(setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable MUL_ASGN Expr	{
			ASTNode *expr = pop();
			ASTNode *asgn = pop();
			ASTNode *variable = pop();
			push(setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable DIV_ASGN Expr	{
			ASTNode *expr = pop();
			ASTNode *asgn = pop();
			ASTNode *variable = pop();
			push(setChild(asgn, setSibling(variable, expr)));
		  }
		  | Variable MOD_ASGN Expr	{
			ASTNode *expr = pop();
			ASTNode *asgn = pop();
			ASTNode *variable = pop();
			push(setChild(asgn, setSibling(variable, expr)));
		  }
		  ;
Variable: ID '[' Expr ']'	{
			ASTNode *idarr = makeASTNode(_ID_ARR, NO_TYPE);
			ASTNode *expr = pop();
			ASTNode *id = makeASTNodeID($1, NO_TYPE);
			push(setChild(idarr, setSibling(id, expr)));
		}
		| ID	{ push(makeASTNodeID($1, NO_TYPE)); }
		;
SimpleExpr: SimpleExpr OR AndExpr	{
			ASTNode *andexpr = pop();
			ASTNode *orop = makeASTNodeOP("||", NO_TYPE);
			push(setChild(orop, setSibling(pop(), andexpr)));
		  }
	      | AndExpr	{}
		  ;
AndExpr: AndExpr AND RelExpr	{
			ASTNode *relexpr = pop();
			ASTNode *andop = makeASTNodeOP("&&", NO_TYPE);
			push(setChild(andop, setSibling(pop(), relexpr)));
	   }
	   | RelExpr	{}
	   ;
RelExpr: RelExpr LESS AddExpr	{
			ASTNode *addexpr = pop();
			ASTNode *relop = pop();
			push(setChild(relop, setSibling(pop(), addexpr)));
	   }
	   | RelExpr EQ_LES AddExpr	{
			ASTNode *addexpr = pop();
			ASTNode *relop = pop();
			push(setChild(relop, setSibling(pop(), addexpr)));
	   }
	   | RelExpr BIGG AddExpr	{
			ASTNode *addexpr = pop();
			ASTNode *relop = pop();
			push(setChild(relop, setSibling(pop(), addexpr)));
	   }
	   | RelExpr EQ_BIG AddExpr	{
			ASTNode *addexpr = pop();
			ASTNode *relop = pop();
			push(setChild(relop, setSibling(pop(), addexpr)));
	   }
	   | RelExpr EQ_CMP AddExpr	{
			ASTNode *addexpr = pop();
			ASTNode *relop = pop();
			push(setChild(relop, setSibling(pop(), addexpr)));
	   }
	   | RelExpr EQ_NOT AddExpr	{
			ASTNode *addexpr = pop();
			ASTNode *relop = pop();
			push(setChild(relop, setSibling(pop(), addexpr)));
	   }
	   | AddExpr	{}
	   ;
AddExpr: AddExpr ADD Term	{
			ASTNode *term = pop();
			ASTNode *oper = pop();
			push(setChild(oper, setSibling(pop(), term)));
	   }
	   | AddExpr SUB Term	{
			ASTNode *term = pop();
			ASTNode *oper = pop();
			push(setChild(oper, setSibling(pop(), term)));
	   }
	   | Term	{}
	   ;
Term: Term MUL Factor	{ 
		ASTNode *factor = pop();
		ASTNode *oper = pop();
		push(setChild(oper, setSibling(pop(), factor)));
 	}
	| Term DIV Factor	{ 
		ASTNode *factor = pop();
		ASTNode *oper = pop();
		push(setChild(oper, setSibling(pop(), factor)));
 	}
	| Term MOD Factor	{ 
		ASTNode *factor = pop();
		ASTNode *oper = pop();
		push(setChild(oper, setSibling(pop(), factor)));
 	}
	| Factor			{}
	;
Factor: '(' Expr ')'		{}
	  | FunctionCall		{}
	  | SUB Factor			{
		  ASTNode *factor = pop();
		  ASTNode *neg = makeASTNodeOP("-", NO_TYPE);
		  push(setChild(neg, factor));
	  }
	  | Variable			{}
	  | Variable IncDec		{
		  ASTNode *incdecexp = makeASTNode(_INCDEC_EXP, NO_TYPE);
		  ASTNode *incdec = pop();
		  push(setChild(incdecexp, setSibling(pop(), incdec)));
	  }
	  | IncDec Variable		{
		  ASTNode *incdecexp = makeASTNode(_INCDEC_EXP, NO_TYPE);
		  ASTNode *variable = pop();
		  push(setChild(incdecexp, setSibling(pop(), variable)));
	  }
	  | NumberLiteral		{}
	  ;
NumberLiteral: INTEGER	{ push(makeASTNodeINT($1)); }
			 | REAL		{ push(makeASTNodeREAL($1)); }
			 ;
IncDec: INCREMENT	{ push(makeASTNodeOP("++", NO_TYPE)); }
	  | DECREMENT	{ push(makeASTNodeOP("--", NO_TYPE)); }
	  ;
WhileStmt: WHILE '(' Expr ')' CompoundStmt	{
			ASTNode *whlstmt = makeASTNode(_WHLSTMT, NO_TYPE);
			ASTNode *cpdstmt = pop();
			ASTNode *expr = pop();
			push(setChild(whlstmt, setSibling(expr, cpdstmt)));
		 }
		 | WHILE '(' Expr ')' ';'	{
			 ASTNode *whlstmt = makeASTNode(_WHLSTMT, NO_TYPE);
			 ASTNode *expr = pop();
			 push(setChild(whlstmt, expr));
		 }
		 ;
ForStmt: FOR '(' Expr ';' Expr ';' Expr ')' CompoundStmt	{
			ASTNode *forstmt = makeASTNode(_FORSTMT, NO_TYPE);
			ASTNode *cpdstmt = pop();
			ASTNode *expr3 = pop();
			ASTNode *expr2 = pop();
			ASTNode *expr1 = pop();
			expr1 = setSibling(expr1, setSibling(expr2, setSibling(expr3, cpdstmt)));
			push(setChild(forstmt, expr1));
	   }
	   | FOR '(' Expr ';' Expr ';' Expr ')' ';'	{
		    ASTNode *forstmt = makeASTNode(_FORSTMT, NO_TYPE);
		    ASTNode *expr3 = pop();
			ASTNode *expr2 = pop();
			ASTNode *expr1 = pop();
			push(setChild(forstmt, setSibling(expr1, setSibling(expr2, expr3))));
	   }
	   ;
FunctionCall: ID '(' Arguments ')'	{
				ASTNode *funccall = makeASTNode(_FUNCCALL, NO_TYPE);
				ASTNode *id = makeASTNodeID($1, NO_TYPE);
				ASTNode *arguments = pop();
				push(setChild(funccall, setSibling(id, arguments)));
			}
		    ;
Arguments: ArgumentList	{
			ASTNode *args = makeASTNode(_ARGS, NO_TYPE);
			push(setChild(args, pop()));
		 }
	     | { push(makeASTNode(_ARGS, NO_TYPE)); }
		 ;
ArgumentList: ArgumentList ',' Expr	{
				ASTNode *expr = pop();
				ASTNode *arglist = pop();
				// 아리까리함...
				push(setLastSibling(arglist, expr));
			}
			| Expr	{}
			

%%
int main(int argc, char *argv[]){
	extern FILE *yyin;
	stack = initStack();
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	printAST(pop(stack));
	return 0;
}


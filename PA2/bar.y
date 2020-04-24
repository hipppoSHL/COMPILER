%{
#include <stdio.h>
#include <stdlib.h>
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
%token <sVal> COMMENT ID STRING OPERATOR EQUAL ADD 
%token break case char default else float for if int return switch void while int float double char void ASGN ADD_ASGN SUB_ASGN MUL_ASGN DIV_ASGN MOD_ASGN EQ_CMP EQ_NOT EQ_BIG EQ_LES LSHIFT RSHIFT AND OR INCREMENT DECREMENT ADD SUB MUL DIV MOD LESS BIGG

%%
Program: DeclarionList { printf("Program -> DeclarionList\n"); }
	   ;
DeclarionList: DeclarionList Declaration { printf("DeclarationList -> DeclarationList Declaration\n"); }
		     | Declaration { printf("DeclarationList -> Declaration\n"); }
			 ;
Declaration: VarDeclaration { printf("Declaration -> VarDeclaration\n";) }
		   | FuncDeclaration { printf("Declaration -> FuncDeclaration\n"); }
		   ;
FuncDeclaration: Type ID '(' Params ')' CompoundStmt { printf("FuncDeclaration -> Type $2 ( Params ) CompoundStmt\n"); }
			   | Type ID '(' Params ')' ';' { printf("FuncDeclaration -> Type $2 ( Params ) ;\n"); }
			   ;
Params: ParamList { printf("Params -> ParamList\n"); }
	  | void { printf("Params -> void\n"); }
	  | { printf("Params -> Empty\n"); }
	  ;
ParamList: ParamList ',' Param { printf("ParamList -> ParamList , Param\n"); }
		 | Param { printf("ParamList -> Param\n"); }
		 ;
Param: Type Value { printf("Param -> Type Value\n"); }
	 ;
CompoundStmt: '{' LocalDeclarationList StmtList '}' { printf("CompoundStmt -> { LocalDeclarationList StmtList }\n"); }
	        ;
LocalDeclarationList: LocalDeclarationList VarDeclaration { printf("LocalDeclarationList -> LocalDeclarationList VarDeclaration\n"); }
					| { printf("LocalDeclarationList -> Empty\n"); }
					;
VarDeclaration: Type IDs ';' { printf("VarDeclaration -> Type IDs ;\n"); }
			  ;
Type: int	{ printf("Type -> int\n"); }
	| void 	{ printf("Type -> void\n"); }
	| char	{ printf("Type -> char\n"); }
	| float	{ printf("Type -> float\n"); }
	;
IDs: IDs ',' Value	{ printf("IDs -> IDs , Value\n"); }
   | Value			{ printf("IDs -> Value\n"); }
   ;
Value: ID '[' INTEGER ']'	{ printf("Value -> $1 [ $3 ]\n"); }
	 | ID 					{ printf("Value -> $1\n"); }
	 ;
StmtList: StmtList Stmt	{ printf("StmtList -> StmtList Stmt\n"); }
		| { printf("StmtList -> Empty\n"); }
		;
Stmt: MatchedStmt	{ printf("Stmt -> MatchedStmt\n"); }
	| OpenStmt		{ printf("Stmt -> OpenStmt\n"); }
	;
MatchedStmt: ExprStmt		{ printf("MatchedStmt -> ExprStmt\n"); }
		   | ForStmt		{ printf("MatchedStmt -> ForStmt\n"); }
		   | WhileStmt		{ printf("MatchedStmt -> WhileStmt\n"); }
		   | ReturnStmt		{ printf("MatchedStmt -> ReturnStmt\n"); }
		   | CompoundStmt	{ printf("MatchedStmt -> CompoundStmt\n"); }
		   | BreakStmt		{ printf("MatchedStmt -> BreakStmt\n"); }
		   | SwitchStmt		{ printf("MatchedStmt -> SwitchStmt\n"); }
		   | if '(' Expr ')' MatchedStmt else MatchedStmt { printf("MatchedStmt -> if ( Expr ) MatchedStmt else MatchedStmt\n"); }
		   ;
OpenStmt: if '(' Expr ')' Stmt	{ printf("OpenStmt -> if ( Expr ) Stmt\n"); }
		| if '(' Expr ')' MatchedStmt else OpenStmt	{ printf("OpenStmt -> if ( Expr ) MatchedStmt else OpenStmt\n"); }
		;
SwitchStmt: switch '(' Expr ')' '{' CaseList DefaultCase '}'	{ printf("SwitchStmt -> switch ( Expr ) { CaseList DefaultCase }\n"); }
		  ;
CaseList: CaseList case INTEGER ':' StmtList	{ printf("CaseList -> CaseList case $3 : StmtList\n";) }
		| case INTEGER ':' StmtList	{ printf("CaseList -> case $2 : StmtList\n"); }
		;
DefaultCase: default ':' StmtList	{ printf("DefaultCase -> default : StmtList\n"); }
		   | { printf("DefaultCase -> Empty\n"); }
		   ;
ReturnStmt: return Expr ';'	{ printf("ReturnStmt -> return Expr ;\n"); }
		  | return ';'	{ printf("ReturnStmt -> return ;\n"); }
		  ;
BreakStmt: break ';'	{ printf("BreakStmt -> break ;\n"); }
		 ;
ExprStmt: Expr ';'	{ printf("ExprStmt -> Expr ;\n"); }
		| ';'		{ printf("ExprStmt -> ;\n"); }
		;
Expr: AssignExpr	{ printf("Expr -> AssignExpr\n"); }
	| SimpleExpr	{ printf("Expr -> SimpleExpr\n"); }
	;
AssignExpr: Variable ASGN Expr		{ printf("AssignExpr -> Variable = Expr\n"); }
		  | Variable ADD_ASGN Expr	{ printf("AssignExpr -> Variable += Expr\n"); }
		  | Variable SUB_ASGN Expr	{ printf("AssignExpr -> Variable -= Expr\n"); }
		  | Variable MUL_ASGN Expr	{ printf("AssignExpr -> Variable *= Expr\n"); }
		  | Variable DIV_ASGN Expr	{ printf("AssignExpr -> Variable /= Expr\n"); }
		  | Variable MOD_ASGN Expr	{ printf("AssignExpr -> Variable %%= Expr\n"); }
		  ;
Variable: ID '[' Expr ']'	{ printf("Variable -> $1 [ Expr ]\n"); }
		| ID	{ printf("Variable -> $1 [ Expr ]\n"); }
		;
SimpleExpr: SimpleExpr OR AndExpr	{ printf("SimpleExpr -> SimpleExpr || AndExpr\n"); }
	      | AndExpr	{ printf("SimpleExpr -> AndExpr\n"); }
		  ;
AndExpr: AndExpr AND RelExpr	{ printf("AndExpr -> AndExpr && RelExpr\n"); }
	   | RelExpr	{ printf("AndExpr -> RelExpr\n"); }
	   ;
RelExpr: RelExpr LESS AddExpr	{ printf("RelExpr -> RelExpr < AddExpr\n"); }
	   | RelExpr EQ_LES AddExpr	{ printf("RelExpr -> RelExpr <= AddExpr\n"); }
	   | RelExpr BIGG AddExpr	{ printf("RelExpr -> RelExpr > AddExpr\n"); }
	   | RelExpr EQ_BIG AddExpr	{ printf("RelExpr -> RelExpr >= AddExpr\n"); }
	   | RelExpr EQ_CMP AddExpr	{ printf("RelExpr -> RelExpr == AddExpr\n"); }
	   | RelExpr EQ_NOT AddExpr	{ printf("RelExpr -> RelExpr != AddExpr\n"); }
	   | AddExpr	{ printf("RelExpr ->  AddExpr\n"); }
	   ;
AddExpr: AddExpr ADD Term	{ printf("AddExpr -> AddExpr + Term\n"); }
	   | AddExpr SUB Term	{ printf("AddExpr -> AddExpr - Term\n"); }
	   | Term	{ printf("AddExpr -> Term\n"); }
	   ;
Term: Term MUL Factor	{ printf("Term -> Term * Factor\n"); }
	| Term DIV Factor	{ printf("Term -> Term / Factor\n"); }
	| Term MOD Factor	{ printf("Term -> Term % Factor\n"); }
	| Term				{ printf("Term -> Term\n"); }
	;
Factor: '(' Expr ')'		{ printf("Factor -> ( Expr )\n"); }
	  | FunctionCall		{ printf("Factor -> FunctionCall\n"); }
	  | SUB Factor			{ printf("Factor -> - Factor\n"); }
	  | Variable			{ printf("Factor -> Variable\n"); }
	  | Variable IncDec		{ printf("Factor -> Variable IncDec\n"); }
	  | IncDec Variable		{ printf("Factor -> IncDec Variable\n"); }
	  | NumberLiteral		{ printf("Factor -> NumberLiteral\n"); }
	  ;
NumberLiteral: INTEGER	{ printf("NumberLiteral -> $1\n"); }
			 | REAL		{ printf("NumberLiteral -> $1\n"); }
			 ;
IncDec: INCREMENT	{ printf("IncDec -> ++\n"); }
	  | DECREMENT	{ printf("IncDec -> --\n"); }
	  ;
WhileStmt: while '(' Expr ')' CompoundStmt	{ printf("WhileStmt -> while ( Expr ) CompoundStmt\n"); }
		 | while '(' Expr ')' ';'	{ printf("WhileStmt -> while ( Expr ) ;\n"); }
		 ;
ForStmt: for '(' Expr ';' Expr ';' Expr ')' CompoundStmt	{ printf("ForStmt -> for ( Expr ; Expr ; Expr ) CompoundStmt\n"); }
	   | for '(' Expr ';' Expr ';' Expr ')' ';'	{ printf("ForStmt -> for ( Expr ; Expr ; Expr ) ;\n"); }
	   ;
FunctionCall: ID '(' Arguments ')'	{ printf("FunctionCall -> $1 ( Arguments )\n"); }
		    ;
Arguments: ArgumentList	{ printf("Arguments -> ArgumentList\n"); }
	     ;
ArgumentList: ArgumentList ',' Expr	{ printf("ArgumentList -> ArgumentList , Expr\n"); }
		    | ArgumentList ',' STRING	{ printf("ArgumentList -> ArgumentList , $3\n"); }
			| Expr	{ printf("ArgumentList -> Expr\n"); }
			| STRING	{ printf("ArgumentList -> $1\n"); }

%%
int main(int argc, char *argv[]){
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	return 0;
}


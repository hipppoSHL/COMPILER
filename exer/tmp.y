%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror(char*);
%}

%union{
	int iVal;
	float rVal;
}
%token <iVal> INTEGER
%token <rVal> REAL
%token ID STRING
%token BREAK CASE CHAR DEFAULT ELSE FLOAT FOR IF INT RETURN STRUCT SWITCH VOID WHILE
%token ADDASGN SUBASGN MULASGN DIVASGN MODASGN EQ NEQ LOE GOE LSHIFT RSHIFT AND OR INCREMENT DECREMENT

%%

Program: DeclarationList { printf("Program -> DeclarationList\n"); }
       ;
DeclarationList: DeclarationList Declaration { printf("DeclarationList -> DeclarationList Declaration\n"); }
	       | Declaration { printf("DeclarationList -> Declaration\n"); }
	       ;
Declaration: VarDeclaration { printf("Declaration -> VarDeclaration\n"); }
	   | FuncDeclaration { printf("Declaration -> FuncDeclaration\n"); }
	   | StructDeclaration { printf("Declaration -> StructDeclaration\n"); }
	   ;
VarDeclaration: TypeSpecifier IDs ';' { printf("VarDeclaration -> TypeSpecifier IDs ;\n"); }
	      ;
IDs: IDs ',' Value { printf("IDs -> IDs , Value\n"); }
   | IDs ',' Value '=' Expression { printf("IDs -> IDs , Value = Expression\n"); }
   | IDs ',' Value '=' STRING { printf("IDs -> IDs , Value = STRING\n"); }
   | Value { printf("IDs -> Value\n"); }
   | Value '=' Expression { printf("IDs -> Value = Expression\n"); }
   | Value '=' STRING { printf("IDs -> Value = STRING\n"); }
   ;
Value: Value '[' INTEGER ']' { printf("Value -> Value [ %d ]\n", $3); }
     | ID { printf("Value -> ID\n"); }
     ;
FuncDeclaration: TypeSpecifier ID '(' Params ')' CompoundStatement { printf("FuncDeclaration -> TypeSpecifier ID ( Params ) CompoundStatement\n"); }
	       | TypeSpecifier ID '(' Params ')' ';' { printf("FuncDeclaration -> TypeSpecifier ID ( Params ) ;\n"); }
	       ;
StructDeclaration: StructTypeDeclaration ';' { printf("StructDeclaration -> StructTypeDeclaration ;\n"); }
		 ;
StructTypeDeclaration: STRUCT ID '{' LocalDeclarationList '}' { printf("StructTypeDeclaration -> struct ID { LocalDeclarationList }\n"); }
		     ;
Params: ParamList { printf("Params -> ParamList\n"); }
      | VOID { printf("Params -> void\n"); }
      | { printf("Params -> Empty\n"); }
      ;
ParamList: ParamList ',' Param { printf("ParamList -> ParamList , Param\n"); }
	 | Param { printf("ParamList -> Param\n"); }
	 ;
Param: TypeSpecifier Value { printf("Param -> TypeSpecifier Value\n"); }
     ;
TypeSpecifier: INT { printf("TypeSpecifier -> int\n"); }
	     | VOID { printf("TypeSpecifier -> void\n"); }
	     | CHAR { printf("TypeSpecifier -> char\n"); }
	     | FLOAT { printf("TypeSpecifier -> float\n"); }
	     | StructType { printf("TypeSpecifier -> StructType\n"); }
	     ;
StructType: StructTypeDeclaration { printf("StructType -> StructTypeDeclaration\n"); }
	  | StructTypeReference { printf("StructType -> StructTypeReference\n"); }
	  ;
StructTypeReference: STRUCT ID { printf("StructTypeReference -> struct ID\n"); }
		   ;
CompoundStatement: '{' LocalDeclarationList StatementList '}' { printf("CompoundStatement -> { LocalDeclarationList StatementList }\n"); }
		 ;
LocalDeclarationList: LocalDeclarationList VarDeclaration { printf("LocalDeclarationList -> LocalDeclarationList VarDeclaration\n"); }
		    | { printf("LocalDeclarationList -> Empty\n"); }
		    ;
StatementList: StatementList Statement { printf("StatementList -> StatementList Statement\n"); }
	     | { printf("StatementList -> Empty\n"); }
	     ;
Statement: MatchedStatement { printf("Statement -> MatchedStatement\n"); }
	 | OpenStatement { printf("Statement -> OpenStatement\n"); }
	 ;
MatchedStatement: ExpressionStatement { printf("MatchedStatement -> ExpressionStatement\n"); }
		| ForStatement { printf("MatchedStatement -> ForStatement\n"); }
		| WhileStatement { printf("MatchedStatement -> WhileStatement\n"); }
		| ReturnStatement { printf("MatchedStatement -> ReturnStatement\n"); }
		| CompoundStatement { printf("MatchedStatement -> CompoundStatement\n"); }
		| BreakStatement { printf("MatchedStatement -> BreakStatement\n"); }
		| SwitchStatement { printf("MatchedStatement -> SwitchStatement\n"); }
		| IF '(' Expression ')' MatchedStatement ELSE MatchedStatement { printf("MatchedStatement -> if ( Expression ) MatchedStatement else MatchedStatement\n"); }
		;
OpenStatement: IF '(' Expression ')' Statement { printf("OpenStatement -> if ( Expression ) Statement\n"); }
	     | IF '(' Expression ')' MatchedStatement ELSE OpenStatement { printf("OpenStatement -> if ( Expression ) MatchedStatement else OpenStatement\n"); }
	     ;
SwitchStatement: SWITCH '(' Expression ')' '{' CaseList DefaultCase '}' { printf("SwitchStatement -> switch ( Expression ) { CaseList DefaultCase }\n"); }
	       ;
CaseList: CaseList CASE INTEGER ':' StatementList { printf("CaseList -> CaseList case %d : StatementList\n", $3); }
	| CASE INTEGER ':' StatementList { printf("CaseList -> case %d : StatementList\n", $2); }
	;
DefaultCase: DEFAULT ':' StatementList { printf("DefaultCase -> default : StatementList\n"); }
	   | { printf("DefaultCase -> Empty\n"); }
	   ;
ReturnStatement: RETURN Expression ';' { printf("ReturnStatement -> return Expression ;\n"); }
	       | RETURN ';' { printf("ReturnStatement -> return ;\n"); }
	       ;
BreakStatement: BREAK ';' { printf("BreakStatement -> break ;\n"); }
	      ;
ExpressionStatement: Expression ';' { printf("ExpressionStatement -> Expression ;\n"); }
		   | ';' { printf("ExpressionStatement -> ;\n"); }
		   ;
Expression: AssignExpression { printf("Expression -> AssignExpression\n"); }
	  | SimpleExpression { printf("Expression -> SimpleExpression\n"); }
	  ;
AssignExpression: Variable Assign Expression { printf("AssignExpression -> Variable Assign Expression\n"); }
		;
Variable: ID { printf("Variable -> ID\n"); }
	| ID SelectorList { printf("Variable -> ID SelectorList\n"); }
	;
SelectorList: SelectorList Selector { printf("SelectorList -> SelectorList Selector\n"); }
	    | Selector { printf("SelectorList -> Selector\n"); }
	    ;
Selector: '.' ID { printf("Selector -> . ID\n"); }
	| '[' Expression ']' { printf("Selector -> [ Expression ]\n"); }
	;
SimpleExpression: SimpleExpression OR AndExpression { printf("SimpleExpression -> SimpleExpression || AndExpression\n"); }
		| AndExpression { printf("SimpleExpression -> AndExpression\n"); }
		;
AndExpression: AndExpression AND RelExpression { printf("AndExpression -> AndExpression && RelExpression\n"); }
	     | RelExpression { printf("AndExpression -> RelExpression\n"); }
	     ;
RelExpression: RelExpression RelOperator AddExpression { printf("RelExpression -> RelExpression RelOperator AddExpression\n"); }
	     | AddExpression { printf("RelExpression -> AddExpression\n"); }
	     ;
RelOperator: '<' { printf("RelOperator -> <\n"); }
	   | LOE { printf("RelOperator -> <=\n"); }
	   | '>' { printf("RelOperator -> >\n"); }
	   | GOE { printf("RelOperator -> >=\n"); }
	   | EQ { printf("RelOperator -> ==\n"); }
	   | NEQ { printf("RelOperator -> !=\n"); }
	   ;
AddExpression: AddExpression Oper1 Term { printf("AddExpression -> AddExpression Oper1 Term\n"); }
	     | Term { printf("AddExpression -> Term\n"); }
	     ;
Oper1: '+' { printf("Oper1 -> +\n"); }
     | '-' { printf("Oper1 -> -\n"); }
     ;
Term: Term Oper2 Factor { printf("Term -> Term Oper2 Factor\n"); }
    | Factor { printf("Term -> Factor\n"); }
    ;
Oper2: '*' { printf("Oper2 -> *\n"); }
     | '/' { printf("Oper2 -> /\n"); }
     | '%' { printf("Oper2 -> %%\n"); }
     ;
Factor: '(' Expression ')' { printf("Factor -> ( Expression )\n"); }
      | FunctionCall { printf("Factor -> FunctionCall\n"); }
      | '-' Factor { printf("Factor -> - Factor\n"); }
      | Variable { printf("Factor -> Variable\n"); }
      | Variable IncDec { printf("Factor -> Variable IncDec\n"); }
      | IncDec Variable { printf("Factor -> IncDec Variable\n"); }
      | NumberLiteral { printf("Factor -> NumberLiteral\n"); }
      ;
NumberLiteral: INTEGER { printf("NumberLiteral -> %d\n", $1); }
	     | REAL { printf("NumberLiteral -> %lf\n", $1); }
	     ;
IncDec: INCREMENT { printf("IncDec -> ++\n"); }
      | DECREMENT { printf("IncDec -> --\n"); }
      ;
WhileStatement: WHILE '(' Expression ')' CompoundStatement { printf("WhileStatement -> while ( Expression ) CompoundStatement\n"); }
	      | WHILE '(' Expression ')' ';' { printf("WhileStatement -> while ( Expression ) ;\n"); }
	      ;
ForStatement: FOR '(' Expression ';' Expression ';' Expression ')' ';' { printf("ForStatement -> for ( Expression ; Expression ; Expression ) ;\n"); }
	    | FOR '(' Expression ';' Expression ';' Expression ')' CompoundStatement { printf("ForStatement -> for ( Expression ; Expression ; Expression ) CompoundStatement\n"); }
	    ;
FunctionCall: ID '(' Arguments ')' { printf("FunctionCall -> ID ( Arguments )\n"); }
	    ;
Arguments: ArgumentList { printf("Arguments -> ArgumentList\n"); }
	 | { printf("Arguments -> Empty\n");}
	 ;
ArgumentList: ArgumentList ',' Expression { printf("ArgumentList -> ArgumentList , Expression\n"); }
	    | ArgumentList ',' STRING { printf("ArgumentList -> ArgumentList , STRING\n"); }
	    | Expression { printf("ArgumentList -> Expression\n"); }
	    | STRING { printf("ArgumentList -> STRING\n"); }
	    ;
Assign: '=' { printf("Assign -> =\n"); }
      | ADDASGN { printf("Assign -> +=\n"); }
      | SUBASGN { printf("Assign -> -=\n"); }
      | MULASGN { printf("Assign -> *=\n"); }
      | DIVASGN { printf("Assign -> /=\n"); }
      | MODASGN { printf("Assign -> %%=\n"); }
      ;
%%
int main(int argc, char* argv[]){
	if(argc == 1)	exit(0);
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	return 0;
}


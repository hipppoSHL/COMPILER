#ifndef _AST_H_
#define _AST_H_
typedef enum {_PROG, _VARDEC, _FUNCDEC, _ID, _ID_ARR, _TYPE, _VALUE, _PARAMS, _PARAM, _CPDSTMT, _LDECLIST, _STMTLIST, _IFSTMT, _SWSTMT, _RTSTMT, _BRKSTMT, _WHLSTMT, _FORSTMT, _CASE, _DEFAULT, _INCDEC_EXP, _OPER, _INTEGER, _REAL, _ARGS, _FUNCCALL} TKNUM;

typedef enum {NO_TYPE, TYPE_INT, TYPE_INT_ARRAY, TYPE_FLOAT, TYPE_FLOAT_ARRAY, TYPE_VOID, TYPE_INT_FUNC, TYPE_FLOAT_FUNC, TYPE_VOID_FUNC, TYPE_ERROR} TYPE;

typedef struct astNodeType ASTNode;
typedef struct stack_t STACK;

ASTNode* makeASTNode(TKNUM tknum, TYPE t);
ASTNode* makeASTNodeID(char *id, TYPE t);
ASTNode* makeASTNodeOP(char *op, TYPE t);
ASTNode* makeASTNodeINT(int n);
ASTNode* makeASTNodeREAL(float r);

ASTNode* getSibling(ASTNode* n);
ASTNode* getChild(ASTNode* n);

ASTNode* setSibling(ASTNode* l, ASTNode* r);
ASTNode* setLastSibling(ASTNode* l, ASTNode* r);
ASTNode* setChild(ASTNode* p, ASTNode* c);

void setType(ASTNode *n, TYPE t);
int getIVal(ASTNode *n);
float getRVal(ASTNode *n);
char* getSVal(ASTNode *n);

TKNUM getTkNum(ASTNode *n);
TYPE getType(ASTNode *n);

void printType(TYPE t);
void printAST(ASTNode* head);

STACK* initStack(void);
void delStack(STACK* s);
void push(STACK* s, ASTNode* n);
ASTNode* pop(STACK *s);
void printStack(STACK *s);

#endif


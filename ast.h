#ifndef AST_H
#define AST_H

#include "symbol_table.h"

//===========================================================

typedef struct AstNode {
	int node_type; // an operator, identifier, number, etc...
	char* node_value; // the actual "+" or "233.33" or "avar1" etc as required
	
	struct type_tableEntry *type;
	//symbolType type; // Actual type of the value
	symbolPassType passType; // Reference or value (values have literals and operations)
	
	struct AstNode* left;       // pointer to left child
	struct AstNode* right;      // pointer to right child
} AstNode;
//===================================================================

typedef struct stack_elem{
	int off;
	char *label;
} stack_elem;

typedef struct set_label{
	char *label;
	struct set_label *next;
} set_label;

typedef struct set_elem{
	int fill;
	char *var;
	char *label;
} set_elem;

AstNode* makeNode( int NodeType, char *NodeValue,type_tableEntry *type, symbolPassType passType, AstNode *Left, AstNode *Right );
AstNode *make_new_node(AstNode *Left, AstNode *Right );
void postOrder(AstNode* root);
void print_elem();
void init();
#endif

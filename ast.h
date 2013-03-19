#ifndef AST_H
#define AST_H

#include "symbol_table.h"

//===========================================================

typedef struct AstNode {
	int node_type; // an operator, identifier, number, etc...
	char* node_value; // the actual "+" or "233.33" or "avar1" etc as required
	
	symbolType type; // Actual type of the value
	symbolPassType passType; // Reference or value (values have literals and operations)
	
	struct AstNode* left;       // pointer to left child
	struct AstNode* right;      // pointer to right child
} AstNode;
//===================================================================

AstNode* makeNode( int NodeType, char *NodeValue, symbolType type, symbolPassType passType, AstNode *Left, AstNode *Right );
void postOrder(AstNode* root);
#endif

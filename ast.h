#ifndef AST_H
#define AST_H

#include "symbol_table.h"

//place all your definitions here that are needed by various source files.

// a basic node definition which could easily be improved.
// Only a C-struct definition shown, easily converted to a C++ class if needed.

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

#endif

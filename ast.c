#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
#include "symbol_table.h"

AstNode* makeNode( int NodeType, char *NodeValue, symbolType type, symbolPassType passType, AstNode *Left, AstNode *Right )
{
	AstNode* node_pointer;

	node_pointer = (AstNode*)malloc( sizeof(AstNode) );
	node_pointer->node_type = NodeType;
	
	if( NodeValue != NULL )
	{
		node_pointer->node_value = strdup(NodeValue);
	}
	else
	{
		node_pointer->node_value = NodeValue;
	}
	node_pointer->type = type;
	node_pointer->passType = passType;
	node_pointer->left = Left;
	node_pointer->right = Right;
	return node_pointer;
}

void postOrder(AstNode* node)
{
	if(node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	printf("%s\n", node->node_value);
}

AstNode *make_new_node(AstNode *Left, AstNode *Right ){
	if (Right == NULL)
		return Left;
	else{
		Right -> left = Left;
		return Right;
	}
}
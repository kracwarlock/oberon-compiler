#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
#include "symbol_table.h"

char *make_str_copy( char *astring)
{
	char *news;
	news = (char *)(malloc(strlen(astring)+1));
	strcpy( news, astring);
	return news;
}

AstNode* makeNode( int NodeType, char *NodeValue, symbolType type, symbolPassType passType, AstNode *Left, AstNode *Right )
{
	AstNode* node_pointer;

	node_pointer = (AstNode*)malloc( sizeof(AstNode) );
	node_pointer->node_type = NodeType;
	
	if( NodeValue != NULL )
	{
		node_pointer->node_value = make_str_copy(NodeValue);
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
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
#include "symbol_table.h"

int varT = 0, lineL = 0;

AstNode* makeNode( int NodeType, char *NodeValue, type_tableEntry *type, symbolPassType passType, AstNode *Left, AstNode *Right )
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

int tac(AstNode* node)
{
	if (!strcmp(node->node_value, "IF")) {
		int t1 = tac(node->left);
		printf("IF t%d==0 goto L%d\n", t1-1, lineL);
		postOrder(node->right->left);
		printf("L%d:\n", lineL++);
		postOrder(node->right->right);
	}
	else if(!strcmp(node->node_value,"CASE")){
		int t1 = tac(node->left);
		printf("Next%d:\n", lineL++);
	}
	else if(!strcmp(node->node_value, "REPEAT")){
		printf("L%d:\n", lineL);
		//printf("mayaya3 %s",node->left->node_value);
		postOrder(node->left);
		//int l2 = lineL++;
		//printf("mayaya2");
		int t2 = tac(node->right->right);
		//printf("mayaya");
		printf("IF t%d==1 goto L%d\n", t2-1, lineL);
		lineL++;
		//printf("goto L%d\nL%d:\n", l1, l2);
	}
	else if (!strcmp(node->node_value, "WHILE")) {
		//printf("itisrepeat2");
		printf("L%d:\n", lineL);
		int l1 = lineL++;
		int t1 = tac(node->left);
		printf("IF t%d==0 goto L%d\n", t1-1, lineL);
		int l2 = lineL++;
		postOrder(node->right);
		printf("goto L%d\nL%d:\n", l1, l2);
	}
	else if (!strcmp(node->node_value, "[]"))
	{
		printf("t%d = &%s\n", varT++, node->left->node_value);
		int t1 = varT;
		if (node->right->node_type == 342) {
			int t2 = tac(node->right);
			printf("t%d = t%d + t%d\n", varT, t1-1, t2-1);
		}
		else printf("t%d = t%d + %s\n", varT, varT-1, node->right->node_value);
		return ++varT;
	}
	else if (!strcmp(node->node_value,":=")) {
		//printf("lplp");
		if (node->right->node_type == 342 && node->left->node_type == 342) {
			//printf("lplpl2222");
			int t1 = tac(node->left);
			//varT++;
			int t2 = tac(node->right);
			//if (!strcmp(node->left->node_value,"[]")) printf("*");
			printf("t%d = t%d\n", t1-1, t2-1);
		}
		else if (node->right->node_type == 342) {
			//varT++;
			int t1 = tac(node->right);
			printf("%s = t%d\n", node->left->node_value, t1-1 );
		}
		else if (node->left->node_type == 342) {
			//varT++;
			int t1 = tac(node->left);
			//if (!strcmp(node->left->node_value,"[]")) printf("*");
			printf("t%d = %s\n", t1-1, node->right->node_value);
		}
		else {
			//printf("popoppppp");
			printf("%s=%s\n", node->left->node_value, node->right->node_value);
		}
	}
	/*handling all other operations */
	else {
		if (node->right->node_type == 342 && node->left->node_type == 342) {
			int t1 = tac(node->left);
			int t2 = tac(node->right);
			printf("t%d = t%d %s t%d\n", varT, t1-1, node->node_value, t2-1);
		}
		else if (node->left->node_type == 342) {
			int t1 = tac(node->left);
			printf("t%d = t%d %s %s\n", varT, t1-1, node->node_value, node->right->node_value);
		}
		else if (node->right->node_type == 342) {
			int t2 = tac(node->right);
			printf("t%d = %s %s t%d\n", varT, node->left->node_value, node->node_value, t2-1);
		}
		else printf("t%d = %s %s %s\n", varT, node->left->node_value, node->node_value, node->right->node_value);

		return ++varT;
	}
	return -1;
}

AstNode *make_new_node(AstNode *Left, AstNode *Right ){
	if (Right == NULL)
		return Left;
	else{
		Right -> left = Left;
		return Right;
	}
}

int isOper(AstNode* node)
{
	if (node->node_type != 342) return 0;
	char *s = strdup(node->node_value);
	if (!(strcmp(s, ":=") && strcmp(s, "*") && strcmp(s, "+") && strcmp(s, "-") && strcmp(s, "/") && strcmp(s, "[]")
		&& strcmp(s, "WHILE") && strcmp(s, "IF") && strcmp(s, "REPEAT") && strcmp(s, ".")))
		return 1;
	return 0;
}
void postOrder(AstNode* node)
{
	//printf("hiiamm");
	if (node == NULL)
		return;
	//printf("%s %d\n", node->node_value, node->node_type);
	//printf(" %s ",node->node_value);
	//if (node->left) postOrder(node->left);
	//if (node->right) postOrder(node->right);
	 if (node->left && isOper(node->left)) tac(node->left);	else postOrder(node->left);
	 if (node->right && isOper(node->right)) tac(node->right);	else postOrder(node->right);
}

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
#include "symbol_table.h"

int varT = 0, lineL = 0;
int arr[1000];
int first = 1;
int last = 0;

stack_elem elem_list[1000];

void print_elem(){
	int i;
	for (i=0;i<1000;i++){
		if (elem_list[i].off==-1){
			break;
		}
		//printf("print %s\n",elem_list[i].label);
	}
	return ;
}

int search_elem(char *str){
	int i;
	for (i=0;i<1000;i++){
		if (!strcmp(elem_list[i].label,str)){
		//	printf("search_complete %d\n",elem_list[i].off);
			return elem_list[i].off;
		}
	}
}

void insert_elem(int val,char *str){
	int i;
	for (i=0;i<1000;i++){
		if (elem_list[i].off==-1){
			elem_list[i].off=val;
			elem_list[i].label=str;
			return;
		}
	}
}

void init(){
	int i;
	for (i=0;i<1000;i++){
		arr[i]=-1;
		elem_list[i].off=-1;
	}
}

void insert(int t){
	last++;
	arr[last] = t;
}

void pop(){
	arr[last]=-1;
	last--;
}

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
		insert(lineL);
		printf("IF t%d==0 goto L%d\n", t1-1, arr[last]);
		lineL++;
		postOrder(node->right->left);
		printf("L%d:\n", arr[last]);
		lineL++;
		pop();
		postOrder(node->right->right);
	}
	else if(!strcmp(node->node_value,"CASE")){
		//printf("asas%s",node->left->node_value);
		int t1 = 0;
		if (node->left->node_type==342)
			t1 = tac(node->left);
	    AstNode *cases = node->right->left;
	     while (!strcmp(cases->node_value,"CASE_OR")){
	     	int t2;
	     	if (cases->left == NULL){
	     		//printf("qwww$_%s",cases->right->left->node_value);
	     		insert(lineL);
	     		if (node->left->node_type==342 && cases->right->left->node_type==342){
	     			t2 = tac(cases->right->left);
	       			printf("IF t%d != t%d goto L%d\n", t1-1,t2-1, arr[last]);
	       		}
	       		else if(node->left->node_type==342){
	       			printf("IF t%d != %s goto L%d\n", t1-1,cases->right->left->node_value, arr[last]);
	       		}
	       		else if(cases->right->left->node_type==342){
	     			t2 = tac(cases->right->left);
	       			printf("IF %s != t%d goto L%d\n", node->left->node_value,t2-1, arr[last]);
	       		}
	       		else{
	       			printf("IF %s != %s goto L%d\n", node->left->node_value,cases->right->left->node_value, arr[last]);	
	       		}
	       		postOrder(cases->right->right);
	       		printf("goto Next\n");
	       		printf("L%d:\n", arr[last]);
	       		lineL++;
	       		pop();
	     	}
	     	else {
	     		insert(lineL);
	       	 	if (node->left->node_type==342 && cases->left->left->node_type==342){
	     			 t2 = tac(cases->left->left);
	       	 		printf("IF t%d != t%d goto L%d\n", t1-1,t2-1, arr[last]);
	       	 	}
	       	 	else if(node->left->node_type==342){
	       	 		printf("IF t%d != %s goto L%d\n", t1-1,cases->left->left->node_value, arr[last]);
	       	 	}
	       	 	else if(cases->left->left->node_type==342){
	     			t2 = tac(cases->left->left);
	       	 		printf("IF %s != t%d goto L%d\n", node->left->node_value,t2-1, arr[last]);
	       	 	}
	       	 	else{
	       	 		printf("IF %s != %s goto L%d\n", node->left->node_value,cases->left->left->node_value, arr[last]);	
	       	 	}
	       		postOrder(cases->left->right);
	       		printf("goto Next\n");
	       		printf("L%d:\n", arr[last]);
	       		lineL++;
	       		pop();
	       	}
	       cases=cases->right;
	    }
	    lineL++;
	    postOrder(node->right->right);
	    printf("Next:\n");
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
	else if(!strcmp(node->node_value, "PROC")){
		//printf("i am in a procedure\n");
		printf("%s:\n",node->left->left->node_value);
		postOrder(node->left->right->right->right);
		postOrder(node->left->right->right->left);
	}
	else if(!strcmp(node->node_value, "MAIN")){
		printf("i am in a main procedure\n");
		//printf("main: %s\n",node->left->node_value);
	}
	else if(!strcmp(node->node_value, "MAIN_AUX")){
		printf("i am in a main proceduiiiiire\n");
		//printf("main: %s\n",node->left->node_value);
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
			insert_elem(varT,"t1");
			search_elem("t1");
			printf("t%d = t%d + t%d\n", varT, t1-1, t2-1);
		}
		else {
			insert_elem(varT,"t2");
			search_elem("t2");
			printf("t%d = t%d + %s\n", varT, varT-1, node->right->node_value);
		}
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
			insert_elem(t1-1,"t3");
			search_elem("t3");
			printf("t%d = t%d\n", t1-1, t2-1);
		}
		else if (node->right->node_type == 342) {
			//varT++;
			int t1 = tac(node->right);
			insert_elem(t1-1,node->left->node_value);
			search_elem(node->left->node_value);
			printf("%s = t%d\n", node->left->node_value, t1-1 );
		}
		else if (node->left->node_type == 342) {
			//varT++;
			int t1 = tac(node->left);
			insert_elem(t1-1,node->right->node_value);
			search_elem(node->right->node_value);
			//if (!strcmp(node->left->node_value,"[]")) printf("*");
			printf("t%d = %s\n", t1-1, node->right->node_value);
		}
		else {
			//printf("popoppppp");
			insert_elem(100,node->left->node_value);
			search_elem(node->left->node_value);
			printf("%s=%s\n", node->left->node_value, node->right->node_value);
		}
	}
	/*handling all other operations */
	else {
		if (node->right->node_type == 342 && node->left->node_type == 342) {
			int t1 = tac(node->left);
			int t2 = tac(node->right);
			insert_elem(varT,"t4");
			search_elem("t4");
			printf("t%d = t%d %s t%d\n", varT, t1-1, node->node_value, t2-1);
		}
		else if (node->left->node_type == 342) {
			int t1 = tac(node->left);
			insert_elem(t1-1,"t5");
			search_elem("t5");
			printf("t%d = t%d %s %s\n", varT, t1-1, node->node_value, node->right->node_value);
		}
		else if (node->right->node_type == 342) {
			int t2 = tac(node->right);
			insert_elem(t2-1,"t7");
			search_elem("t7");
			printf("t%d = %s %s t%d\n", varT, node->left->node_value, node->node_value, t2-1);
		}
		else {
			insert_elem(varT,"t8");
			search_elem("t8");
			printf("t%d = %s %s %s\n", varT, node->left->node_value, node->node_value, node->right->node_value);
		}

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
		&& strcmp(s, "WHILE") && strcmp(s, "IF") && strcmp(s, "REPEAT") && strcmp(s, "PROC") && strcmp(s, "CASE") && strcmp(s, ".")))
		return 1;
	return 0;
}
void postOrder(AstNode* node)
{
	//printf("hiiamm");
	if (node == NULL)
		return;
	//printf("%s %d\n", node->node_value, node->node_type);

	if (!strcmp(node->node_value,"MAIN_AUX")){
		printf("MAIN:");
	}
	//printf(" %s ",node->node_value);
	//if (node->left) postOrder(node->left);
	//if (node->right) postOrder(node->right);
	 if (node->left && isOper(node->left)) tac(node->left);	else postOrder(node->left);
	 if (node->right && isOper(node->right)) tac(node->right);	else postOrder(node->right);
}

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
#include "symbol_table.h"

int varT = 0, lineL = 0 , retT = 0;
int arr[1000];
int first = 1;
int last = 0;

stack_elem elem_list[1000];
stack_elem elem_list2[1000];

set_elem set_nota[1000];

void print_set(){
	int i;
	int check=0;
	set_label *l;
	for (i=0;i<1000;i++){
		check=0;
		if (set_nota[i].fill==-1){
			break;
		}
		else{
			printf("-- %s ",set_nota[i].var);
			set_label *lo = set_nota[i].lab;
			while (lo!=NULL){
				printf(" %s ",lo->label);
				lo=lo->next;
			}
		}
		printf("\n");
	}
}

void search_insert(char *laba,char *new){
	int i;
	int check=0;
	printf("newww%s",new);
	set_label* lp;
	for (i=0;i<1000;i++){
		check=0;
		if (set_nota[i].fill==-1){
			break;
		}
		else{
			set_label *lo = set_nota[i].lab;
			set_label *prev = lo;
			while (lo!=NULL){
				//printf("inside_%s_%s",laba,new);
				if (!strcmp(lo->label,laba)){
						lp= (set_label*)malloc(sizeof(set_label));
						lp->label = new;
						lp->next = NULL;
						check=1;
				}
				prev = lo;
				lo=lo->next;
			}
			if (check==1)
				prev->next = lp;
		}
	}
}

void insert_new(char *value,char *labels){
	int i;
	for (i=0;i<1000;i++){
		if (set_nota[i].fill==-1){
			set_nota[i].fill =1;
			set_nota[i].var = value;
			set_label *l = (set_label*)(malloc(sizeof(set_label)));
			l->label = labels;
			l->next=NULL;
			set_nota[i].lab = l;
			break;
		}
	}
	return;
}

void print_elem2(){
	int i;
	for (i=0;i<1000;i++){
		if (elem_list2[i].off==-1){
			break;
		}
		//breakprintf("print2_%s\n",elem_list2[i].label);
	}
	return ;
}

int search_elem2(char *str){
	int i;
	for (i=0;i<1000;i++){
		if (!strcmp(elem_list2[i].label,str)){
		//	printf("search_complete %d\n",elem_list[i].off);
			return elem_list2[i].off;
		}
	}
}

void insert_elem2(int val,char *str){
	int i;
	for (i=0;i<1000;i++){
		if (elem_list2[i].off==-1){
			elem_list2[i].off=val;
			elem_list2[i].label=str;
			return;
		}
	}
}

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
		elem_list2[i].off=-1;
		set_nota[i].fill = -1;
		set_nota[i].lab = NULL;
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
		//printf("IF t%d==0 goto L%d\n", t1-1, arr[last]);
		printf("beqz\t(find address for 't%d' from symbol table)$sp,L%d\n",t1-1,arr[last]);
		lineL++;
		postOrder(node->right->left);
		printf("b\tEnd%d\n", arr[last]);
		printf("\nL%d:\n", arr[last]);
		lineL++;
		pop();
		postOrder(node->right->right);
		printf("\nEnd%d:\n", arr[last]+1);	//**************check if arr[last]+1 is correct
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
		if (node->left->type->type == SET_TYPE){
			set_call(node);
		}
		else if (node->right->type->type == PROC_TYPE){
			proc_call_def(node);
		}
		else{
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
		&& strcmp(s, "WHILE") && strcmp(s, "IF") && strcmp(s, "REPEAT") && strcmp(s, "CASE") && strcmp(s, ".")))
		return 1;
	return 0;
}

void stack_main(AstNode *node,int p,char *tex){
	printf("addui $sp, $sp, -%d\n",p*4);
	int i;
	for (i=0;i<p-1;i++){
		printf("sw $a%d, %d($sp)\n",i,i*4);
		//varT++;
	}
	printf("sw $ra, %d($sp)\n",i*4);
	return ;
}

void stack_main_2(AstNode *node,int p,char *tex){
	int i = p-1;
	printf("lw $ra, %d($sp)\n",i*4);
	for (i=p-2;i>=0;i--){
		printf("lw $a%d, %d($sp)\n",i,i*4);
		//varT++;
	}
	printf("addui $sp, $sp, %d\n",p*4);
	return ;
}

int count_formal(AstNode *node){
	int total = 0;
	int total2 =0; 
	if (node == NULL)
		return 0;
	else{
		if (!strcmp(node->node_value,"FORMAL_PARAMS")){
				total = 1 + count_formal(node->right) + count_formal(node->left);
				return total;
		}
		else{
				total = count_formal(node->right) + count_formal(node->left);
				return total;	
		}
	}
}

void proc_call(AstNode *node){
	int formal = 0;
	if(!strcmp(node->node_value, "PROC")){
		//printf("i am in a procedure\n");
		while (node != NULL){
			printf("%s:\n",node->left->left->node_value);
			formal = count_formal(node->left->right->left);
			//printf("total_args_%d",formal);
			stack_main(node,formal+1,node->left->left->node_value);
			postOrder(node->left->right->right->right);
			stack_main_2(node,formal+1,node->left->left->node_value);
			postOrder(node->left->right->right->left);
			node = node->right;
		}
	}
}

void proc_call_def(AstNode *node){
	int formal = 0;
	int t1;
	//printf("0aaaaaa_%s ",node->left->node_value);
	AstNode *temp = node->right->right;
	while (!strcmp(temp->node_value,"EXPR")){
		if (temp->left->node_type==340){
			printf("move $a%d, %s \n",formal,temp->left->node_value);
			temp = temp->right;
		}
		else{
			t1 = tac(temp->left);
			printf("move $a%d, t%d \n",formal,t1-1);
			temp = temp->right;
		}
		formal++;
	}
	if (temp->node_type==340){
		printf("move $a%d, %s \n",formal,temp->node_value);
	}
	else{
		t1 = tac(temp);
		printf("move $a%d, t%d \n",formal,t1-1);
	}
	printf("jalr %s\n",node->right->left->node_value);
}

void set_call(AstNode *node){
	printf("sets_%s",node->left->node_value);
	char str[3];
	if (!strcmp(node->right->node_value,"+")){
		printf("Union Happenning");
		search_insert(node->right->left->node_value,node->left->node_value);
		search_insert(node->right->right->node_value,node->left->node_value);
	}
	else if (!strcmp(node->right->node_value,"-")){
		
	}
	else if (!strcmp(node->right->node_value,"*")){

	}
	else if (!strcmp(node->right->node_value,"/")){

	}
	else if (node->right->node_type==340){
		search_insert(node->right->node_value,node->left->node_value);
	}
	else{
		AstNode *temp = node->right->right;
		AstNode *temp2 = node->right->right;
		while (!strcmp(temp->node_value,"SET_ELEM")){
			if (isOper(temp->left)){
				printf("SEEE%s",temp->left->node_value);
				int t1 = tac(temp->left);
				char *s = (char*)malloc(sizeof(char));
				sprintf(s, "t%d", t1-1);
				printf("mrea_%s",s);
				insert_new(s,node->left->node_value);
				// one problem with the char [] to char * conversion
			}
			else{
				insert_new(temp->left->node_value,node->left->node_value);
			}
			temp2 = temp;
			temp = temp->right;
		}
		insert_new(temp2->right->node_value,node->left->node_value);
	}
	print_set();
	return ;
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
	if (!strcmp(node->node_value,"PROC")){
		//printf("proccc_%s",node->node_value);
		proc_call(node);
	}
	else{
	//printf(" %s ",node->node_value);
	//if (node->left) postOrder(node->left);
	//if (node->right) postOrder(node->right);
	 if (node->left && isOper(node->left)) tac(node->left);	else postOrder(node->left);
	 if (node->right && isOper(node->right)) tac(node->right);	else postOrder(node->right);
	}
}

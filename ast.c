#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
#include "symbol_table.h"

int varT = 0, lineL = 0 , retT = 0, lineM = 0 , endL = 0 ;
int arr[1000];
int first = 1;
int last = 0;

stack_elem elem_list[1000];
stack_elem elem_list2[1000];

set_elem set_nota[1000];
string_p string_list[1000];

int sp = 0, sp_offset = 12, used_t = 0;

void insert_strings(char *str, char * label)
{
	int i;
	for (i = 0; i < 1000; i++)
	{
		//printf("yaayyaa_%d",string_list[i].fills);
		if (string_list[i].fills == -1)
		{
			break;
		}
	}
	//printf("yaha hain_%d",i);
	//string_list+(i*(sizeof(string_p))) = (string_p *)malloc(sizeof(string_p));
	string_list[i].fills = 1;
	string_list[i].name_str = label;
	string_list[i].val_str = str;
	return;
}

void string_copy(char * src_label, char * dest_label, char * label)
{
	int i;
	int c1=0;
	int c2=0;
	int c3=0;
	int l1,l2,l3;
	for (i = 0; i < 1000; i++)
	{
		//printf("ek_hi-baar");
		if (string_list[i].fills == -1)
		{
			break;
		}
		else
		{
			//printf("mahaaan_%s_%s_%s_%s",string_list[i].name_str,src_label,dest_label,label);
			if (!strcmp(string_list[i].name_str,src_label))
			{
				//printf("popppp");
				l1 = i;
				c1=1;
			}
			if (!strcmp(string_list[i].name_str,dest_label))
			{
				//printf("popppp2");
				l2 = i;
				c2=1;
			}
			if (!strcmp(string_list[i].name_str,label))
			{
				//printf("popppp3");
				l3 = i;
				c3=1;
			}
		}
	}
	if (c1==1 && c2==1 && c3==1)
	{
		char *str = (char*)malloc(sizeof(char));
		strcpy(str,string_list[l1].val_str);
		string_list[l2].val_str = str;
		string_list[l3].val_str = str;
		printf("\ncopy_dest_%s__source_%s__label_%s\n",string_list[l2].val_str,string_list[l1].val_str,string_list[l3].val_str);
	}
	else if (c1==1 && c2==1 && c3==0)
	{
		insert_strings(NULL,label);
		string_copy(src_label,dest_label,label);
	}
	return;
}

string_concatenate(char * src_label, char * dest_label, char * label)
{
	int i;
	int c1=0;
	int c2=0;
	int c3=0;
	int l1,l2,l3;
	for (i = 0; i < 1000; i++)
	{
		//printf("ek_hi-baar");
		if (string_list[i].fills == -1)
		{
			break;
		}
		else
		{
			//printf("mahaaan_%s_%s_%s_%s",string_list[i].name_str,src_label,dest_label,label);
			if (!strcmp(string_list[i].name_str,src_label))
			{
				//printf("popppp");
				l1 = i;
				c1=1;
			}
			if (!strcmp(string_list[i].name_str,dest_label))
			{
				//printf("popppp2");
				l2 = i;
				c2=1;
			}
			if (!strcmp(string_list[i].name_str,label))
			{
				//printf("popppp3");
				l3 = i;
				c3=1;
			}
		}
	}
	if (c1==1 && c2==1 && c3==1)
	{
		char *str = (char*)malloc(sizeof(char));
		strcpy(str,string_list[l2].val_str);
		strcat(str,string_list[l1].val_str);
		string_list[l3].val_str = str;
		string_list[l2].val_str = str;
		printf("concatenate_dest : %s_source : %s_conc : %s\n",string_list[l2].val_str,string_list[l1].val_str,string_list[l3].val_str);
	}
	else if (c1==1 && c2==1 && c3==0)
	{
		insert_strings(NULL,label);
		string_concatenate(src_label,dest_label,label);
	}
	return ;
}

int string_compare (char * src_label, char * dest_label)
{
	int i,a;
	int c1=0;
	int c2=0;
	int c3=0;
	int l1,l2,l3;
	for (i = 0; i < 1000; i++)
	{
		//printf("ek_hi-baar");
		if (string_list[i].fills == -1)
		{
			break;
		}
		else
		{
			//printf("mahaaan_%s_%s_%s_%s",string_list[i].name_str,src_label,dest_label,label);
			if (!strcmp(string_list[i].name_str,src_label))
			{
				//printf("popppp");
				l1 = i;
				c1=1;
			}
			if (!strcmp(string_list[i].name_str,dest_label))
			{
				//printf("popppp2");
				l2 = i;
				c2=1;
			}
		}
	}
	if (c1==1 && c2==1 )
	{
		char *str = (char*)malloc(sizeof(char));
		strcpy(str,string_list[l2].val_str);
		a = strcmp(str,string_list[l1].val_str);
		//string_list[l3].val_str = str;
		//printf("compare_dest : %s_ source : %s_ res : %d\n",string_list[l2].val_str,string_list[l1].val_str,a);
	}
	if (a==0)
		return 0;
	else
		return 1;
}

int string_length(char * src_label)
{
	int i,a;
	int c1=0;
	int c2=0;
	int c3=0;
	int l1,l2,l3;
	for (i = 0; i < 1000; i++)
	{
		//printf("ek_hi-baar");
		if (string_list[i].fills == -1)
		{
			break;
		}
		else
		{
			//printf("mahaaan_%s_%s_%s_%s",string_list[i].name_str,src_label,dest_label,label);
			if (!strcmp(string_list[i].name_str,src_label))
			{
				//printf("popppp");
				l1 = i;
				c1=1;
			}
		}
	}
	if (c1==1)
	{
		int i;
		int count;
		char *str = (char*)malloc(sizeof(char));
		strcpy(str,string_list[l1].val_str);
		a = strlen(str);
		for (i=0;i<strlen(str);i++){
			//if (str[i] == '"')
				//a--; 
		}
		//printf("length_string : %s_ length : %d\n",string_list[l1].val_str,a);
	}
	return a;
}

char * string_reverse(char * str,char * label)
{
	int a,i,mid;
	char *tmp;
	int c1=0;
	int c2=0;
	int c3=0;
	int l1,l2,l3;
	for (i = 0; i < 1000; i++)
	{
		//printf("ek_hi-baar");
		if (string_list[i].fills == -1)
		{
			break;
		}
		else
		{
			//printf("mahaaan_%s_%s_%s_%s",string_list[i].name_str,src_label,dest_label,label);
			if (!strcmp(string_list[i].name_str,str))
			{
				//printf("popppp");
				l1 = i;
				c1=1;
			}
			if (!strcmp(string_list[i].name_str,label))
			{
				//printf("popppp");
				l3 = i;
				c3=1;
			}
		}
	}
	if (c1==1 && c3==1)
	{
		char *str1 = (char*)malloc(sizeof(char));
		strcpy(str1,string_list[l1].val_str);
		a = strlen(str1);
		//printf("str_%s_rev_length_%d\n",str1,a);
		char rev[a];
		strcpy(rev,str1);
		//printf("qwert_%s",rev);
		if (a%2==0)
		{
			mid=a/2;
		}
		else 
		{
			mid = (a/2) + 1;
		}
		for (i = 0; i <= mid-1; i++)
		{
			tmp = rev[i];
			//printf("hihihihi%c\n",rev[i]);
			rev[i] = rev[a-i-1];
			rev[a-i-1] = tmp;
		}
		printf("reverse_%s of string : %s\n",rev,str1);
	}
	else if(c1 ==1 && c3 == 0 )
	{
		insert_strings(NULL,label);
		string_reverse(str,label);
	}
	//return str1;
}

char * remove_q(char * q)
{
	int a,b,i;
	a = strlen(q);
	char res[a];
	char aux[a-2];
	strcpy(res,q);
	for (i = 0; i <= a-3; i++)
	{
		aux[i] = res[i+1];
	}
	aux[i] = res[a];
	return aux;
}

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
			printf(" %s \n",set_nota[i].label);
		}
	}
}

void inter_new(char *label1,char *label2,char *label3){
	int i;
	int j;
	int check=0;
	set_label* lp;
	for (i=0;i<1000;i++){
		if (set_nota[i].fill == -1){
			break;
		}
		for (j=0;j<1000;j++){
			if (set_nota[j].fill == -1){
				break;
			}
			//printf("--%s %s ",set_nota[i].var,set_nota[j].var);
			if (!strcmp(set_nota[i].label,label1) && !strcmp(set_nota[j].label,label2) && !strcmp(set_nota[i].var,set_nota[j].var)){
				printf("ho gaya kya");
				insert_new(set_nota[j].var,label3);
			}
		}
	}
}

void as_new(char *label1,char *label3){
	int i;
	int j;
	int check=0;
	set_label* lp;
	for (i=0;i<1000;i++){
		if (set_nota[i].fill == -1){
			break;
		}
		if (!strcmp(set_nota[i].label,label1)){
			insert_new(set_nota[i].var,label3);
		}
	}
}

void diff_new(char *label1,char *label2,char *label3){
	int i;
	int j;
	int check=0;
	set_label* lp;
	for (i=0;i<20;i++){
		check = 0;
		if (set_nota[i].fill == -1){
			break;
		}
		for (j=0;j<1000;j++){
			if (set_nota[j].fill == -1){
				break;
			}
			else if (!strcmp(set_nota[i].label,label1) && !strcmp(set_nota[j].label,label2)){
				if (!strcmp(set_nota[i].var,set_nota[j].var))
					check =1;
			}
		}
		if (check == 0 && !strcmp(set_nota[i].label,label1)){
			insert_new(set_nota[i].var,label3);
		}
	}
}

void sym_new(char *label1,char *label2,char *label3){
	int i;
	int j;
	int check=0;
	set_label* lp;
	for (i=0;i<20;i++){
		check = 0;
		if (set_nota[i].fill == -1){
			break;
		}
		for (j=0;j<1000;j++){
			if (set_nota[j].fill == -1){
				break;
			}
			else if (!strcmp(set_nota[i].label,label1) && !strcmp(set_nota[j].label,label2)){
				if (!strcmp(set_nota[i].var,set_nota[j].var))
					check =1;
			}
		}
		if (check == 0 && !strcmp(set_nota[i].label,label1)){
			insert_new(set_nota[i].var,label3);
		}
	}
}

void union_new(char *label1,char *label2,char *label3){
	int i;
	int j;
	int k;
	int check=0;
	set_label* lp;
	for (i=0;i<1000;i++){
		if (set_nota[i].fill == -1){
			break;
		}
		if (!strcmp(set_nota[i].label,label1))
			insert_new(set_nota[i].var,label3);
	}
	for (j=0;j<1000;j++){
		check = 0;
		if (set_nota[j].fill == -1){
				break;
		}
		if (!strcmp(set_nota[j].label,label2)){
			for (k=0;k<1000;k++){
				if (set_nota[k].fill == -1){
					break;
				}
				if (!strcmp(set_nota[k].label,label3) && !strcmp(set_nota[j].var,set_nota[k].var)){
					check=1;
				}
			}
			if (check!=1)
				insert_new(set_nota[j].var,label3);
		}
	}
}

void insert_new(char *value,char *labels){
	int i;
	for (i=0;i<1000;i++){
		if (set_nota[i].fill==-1){
			set_nota[i].fill =1;
			set_nota[i].var = value;
			set_nota[i].label = labels;
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
		if (elem_list[i].off==-1){
			break;
		}
		//printf("search_complete %d %s\n",elem_list[i].off,elem_list[i].label);
		if (!strcmp(elem_list[i].label,str)){
			//printf("search_complete %d %s\n",elem_list[i].off,elem_list[i].label);
			return elem_list[i].off;
		}
	}
	return -1;
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
		string_list[i].fills = -1;
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
	node_pointer->val = NULL;
	return node_pointer;
}

int tac(AstNode* node)
{
	if (!strcmp(node->node_value, "IF")) {
		int t1 = tac(node->left);
		insert(lineL);
		//printf("IF t%d==0 goto L%d\n", t1-1, arr[last]);
		char * str;
			str = (char *)malloc(sizeof(char));
			sprintf(str,"t%d\0",t1-1);
		//printf("\n%s\n",str);
		//printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(str));
		printf("beqz\t$t9,L%d\n",arr[last]);
		lineL++;
		postOrder(node->right->left);
		int ww = endL++;
		printf("b\tEnd%d\n", ww);
		printf("\nL%d:\n", arr[last]);
		lineL++;
		pop();
		postOrder(node->right->right);
		printf("\nEnd%d:\n", ww);	//**************check if arr[last]+1 is correct
	}
	else if (!strcmp(node->node_value, "STRCMP")) {
		int b = string_compare(node->left->node_value,node->right->node_value);
		if (b == 0)
			printf("t%d = TRUE\n",varT);
		else
			printf("t%d = FALSE\n",varT);
		
		return ++varT;
	}
	else if (!strcmp(node->node_value, "STRLEN")) {
		int d = string_length(node->left->node_value);
		printf("t%d = %d\n",varT,d);
		return ++varT;
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
		long long int a = lineL++;
		printf("\nL%d:\n", a);

		
		//printf("mayaya3 %s",node->left->node_value);
		postOrder(node->left);
		//int l2 = lineL++;
		//printf("mayaya2");
		int t2 = tac(node->right->right);
		printf("bgtz $t9 L%d\n", a);
		//printf("IF t%d==1 goto L%d\n", t2-1, a);
		//lineL++;
		//printf("goto L%d\nL%d:\n", l1, l2);
	}
	else if(!strcmp(node->node_value, "FOR")){
		// printf("nahi be");
		int pp = lineL++;
		int pp1 = lineL++;
		printf("%s = %s\n",node->left->node_value,node->right->left->node_value);
		printf("L%d:\n", pp);
		printf("t%d = %s <= %s\n",varT,node->left->node_value,node->right->right->left->node_value);
		printf("IF t%d==0 goto L%d\n", varT, pp1);
		varT++;
		postOrder(node->right->right->right->right);
		//printf("print.. %s",node->right->right->right->right->node_value);
		printf("t%d = %s + %s\n",varT,node->left->node_value,node->right->right->right->left->node_value);
		printf("%s = t%d\n",node->left->node_value,varT);
		printf("goto L%d\nL%d:\n", pp, pp1);
	}
	else if (!strcmp(node->node_value, "WHILE")) {
		printf("\nL%d:\n", lineL);
		int l1 = lineL++;
		int t1 = tac(node->left);
		//printf("IF t%d==0 goto L%d\n", t1-1, lineL);
		char * str;
			str = (char *)malloc(sizeof(char));
			sprintf(str,"t%d\0",t1-1);
		printf("beqz\t$t9,L%d\n",lineL);
		int l2 = lineL++;
		postOrder(node->right);
		printf("b\tL%d\n\nL%d:\n", l1, l2);
	}
	else if (!strcmp(node->node_value, "[]"))
	{
		printf("t%d = &%s\n", varT++, node->left->node_value);
		int t1 = varT;
		if (node->right->node_type == 342) {
			int t2 = tac(node->right);
			//insert_elem(varT,"t1");
			//search_elem("t1");
			printf("t%d = t%d + t%d\n", varT, t1-1, t2-1);
		}
		else {
			//insert_elem(varT,"t2");
			//search_elem("t2");
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
		else if (node->left->type->type == ARRAY_TYPE && node->left->type->tp->type == CHAR){
			string_call(node);
		}
		else{
		if (node->right->node_type == 342 && node->left->node_type == 342) {
			//printf("lplpl2222");
			int t1 = tac(node->left);
			//varT++;
			int t2 = tac(node->right);
			//if (!strcmp(node->left->node_value,"[]")) printf("*");
			//insert_elem(t1-1,"t3");
			//search_elem("t3");
			printf("t%d = t%d\n", t1-1, t2-1);
		}
		else if (node->right->node_type == 342) {
			//varT++;
			int t1 = tac(node->right);
			//insert_elem(t1-1,node->left->node_value);
			//search_elem(node->left->node_value);
			//printf("%s = t%d\n", node->left->node_value, t1-1 );
			//lw t%d's val
			//sw val %s's address
			char * str;
			str = (char *)malloc(sizeof(char));
			sprintf(str,"t%d\0",t1-1);
			insert_elem(sp_offset,str);
			sp_offset += 4;
			printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(str));
			printf("sw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
		}
		else if (node->left->node_type == 342) {
			if (!strcmp(node->left->node_value, "^")) {
				printf("t%d = %s\n", varT, node->right->node_value);
				printf("%s = &t%d\n",node->left->left->node_value,varT);
				return varT++;
			}
			else{
				//varT++;
				int t1 = tac(node->left);
				//insert_elem(t1-1,node->right->node_value);
				//search_elem(node->right->node_value);
				//if (!strcmp(node->left->node_value,"[]")) printf("*");
				printf("t%d = %s\n", t1-1, node->right->node_value); 
			}
		}
		else {
			//printf("popoppppp");
			if(node->right->node_type == 341)
			{
				printf("li\t$t%d,%s\n",used_t,node->right->node_value);
				if(search_elem(node->left->node_value)==-1)
				{
					printf("sw\t$t%d,%d($sp)\n",used_t,sp_offset);
					insert_elem(sp_offset,node->left->node_value);
					node->left->val = node->right;	//*******************************	
					sp_offset +=4;
				}
				else
				{
					printf("sw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
				}
				
				//printf("%s=%s\n", node->left->node_value, node->right->node_value);
				//printf("The name is %s\n", node->left->node_value);
				//printf("It is stored at an offset of %d\n\n", search_elem(node->left->node_value));
			}
			else if(node->right->node_type == 340)
			{
				printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->right->node_value));
				printf("sw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
				node->left->val = node->right->val;
			}
		}
	}
	}
	/*handling all other operations */
	else {
		if (node->right->node_type == 342 && node->left->node_type == 342) {
			int t1 = tac(node->left);
			int t2 = tac(node->right);
			//insert_elem(varT,"t4");
			//search_elem("t4");
			printf("t%d = t%d %s t%d\n", varT, t1-1, node->node_value, t2-1);
		}
		else if (node->left->node_type == 342) {
			int t1 = tac(node->left);
			//insert_elem(t1-1,"t5");
			//search_elem("t5");
			printf("t%d = t%d %s %s\n", varT, t1-1, node->node_value, node->right->node_value);
		}
		else if (node->right->node_type == 342) {
			int t2 = tac(node->right);
			//insert_elem(t2-1,"t7");
			//search_elem("t7");
			printf("t%d = %s %s t%d\n", varT, node->left->node_value, node->node_value, t2-1);
			/*if(strcmp(node->node_value,"<")==0)
			{
				char str[3];
				sprintf(str,"t%d",varT);
				insert_elem(sp_offset,str);
				search_elem(str);
				if(atoi(node->left->val->node_value) < atoi(node->right->val->node_value))
				{
					printf("li\t$t%d,1\n",used_t);
				}
				else
				{
					printf("li\t$t%d,0\n",used_t);
				}
				printf("sw\t$t%d,%d($sp)\n",used_t,sp_offset);
				sp_offset += 4;
			}*/
		}
		else {
			//insert_elem(varT,"t8");
			//search_elem("t8");
			//printf("t%d = %s %s %s\n", varT, node->left->node_value, node->node_value, node->right->node_value);
			int i;
			if (!strcmp(node->node_value,"IN")){
				int ind = 0;
				int fal = 0;
				//printf("INIT_%s_%s",node->left->node_value,node->right->node_value);
				//insert(lineL);
				int ww1 = lineL++;
				for (i=0;i<1000;i++){
					if (set_nota[i].fill == -1){
						break;
					}
					else{
						if (!strcmp(set_nota[i].label,node->right->node_value)){
							ind = i;
							printf("IF %s == %s goto L%d\n",set_nota[i].var,node->left->node_value, ww1);
						}
						else
							fal = i;
					}
				}
				printf("t%d = %s %s %s\n", varT, set_nota[fal].var, "=" , node->left->node_value);
				int ww2 = lineL++;
				printf("goto L%d\n",ww2);
				printf("L%d:\n", ww1);
				printf("t%d = %s %s %s\n", varT, set_nota[ind].var, "=" , node->left->node_value);
				printf("L%d:\n", ww2);
			}
			else{

				char * str;
				str = (char *)malloc(sizeof(char));
				sprintf(str,"t%d\0",varT);
				insert_elem(sp_offset,str);
				//printf("Just inserted |%s| \n",str);
				//printf("At %d\n",search_elem(str));

				if(strcmp(node->node_value,"<=")==0 && node->left->node_type==340 && node->right->node_type==340)
				{
	/*				if(atoi(node->left->val->node_value) <= atoi(node->right->val->node_value))
					{
						printf("li\t$t%d,1\n",used_t);
					}
					else
					{
						printf("li\t$t%d,0\n",used_t);
					}
					printf("sw\t$t%d,%d($sp)\n",used_t,sp_offset);
					sp_offset += 4;*/
					printf("lw\t$t7,%d($sp)\n",search_elem(node->left->node_value));
					printf("lw\t$t8,%d($sp)\n",search_elem(node->right->node_value));
					printf("ble\t$t7,$t8,M%d\n",lineM);
					printf("li\t$t9,0\n");
					int ww = endL++;
					printf("b\tEnd%d\n",ww);
					printf("\nM%d:\n",lineM);
					lineM++;
					printf("li\t$t9,1\n");
					printf("\nEnd%d:\n",ww);
				}
				else if(strcmp(node->node_value,"=")==0 && node->left->node_type==340 && node->right->node_type==340)
				{
					printf("lw\t$t7,%d($sp)\n",search_elem(node->left->node_value));
					printf("lw\t$t8,%d($sp)\n",search_elem(node->right->node_value));
					printf("beq\t$t7,$t8,M%d\n",lineM);
					printf("li\t$t9,0\n");
					int ww = endL++;
					printf("b\tEnd%d\n",ww);
					printf("\nM%d:\n",lineM);
					lineM++;
					printf("li\t$t9,1\n");
					printf("\nEnd%d:\n",ww);
				}
				else if(strcmp(node->node_value,"=")==0 && node->left->node_type==340 && node->right->node_type==341)
				{
					printf("lw\t$t7,%d($sp)\n",search_elem(node->left->node_value));
					printf("li\t$t8,%d\n",atoi(node->right->node_value));
					printf("beq\t$t7,$t8,M%d\n",lineM);
					printf("li\t$t9,0\n");
					int ww = endL++;
					printf("b\tEnd%d\n",ww);
					printf("\nM%d:\n",lineM);
					lineM++;
					printf("li\t$t9,1\n");
					printf("\nEnd%d:\n",ww);
				}
				else if(strcmp(node->node_value,"=")==0 && node->left->node_type==341 && node->right->node_type==341)
				{
					printf("lw\t$t7,%d\n",atoi(node->left->node_value));
					printf("li\t$t8,%d\n",atoi(node->right->node_value));
					printf("beq\t$t7,$t8,M%d\n",lineM);
					printf("li\t$t9,0\n");
					int ww = endL++;
					printf("b\tEnd%d\n",ww);
					printf("\nM%d:\n",lineM);
					lineM++;
					printf("li\t$t9,1\n");
					printf("\nEnd%d:\n",ww);
				}
				else if(strcmp(node->node_value,"<")==0 && node->left->node_type==340 && node->right->node_type==341)
				{
					printf("lw\t$t9,%d($sp)\n",search_elem(node->left->node_value));
					insert(lineL);
					printf("blt\t$t9,%d,M%d\n",atoi(node->right->node_value),lineM);
				//	lineL++;
					printf("li\t$t9,0\n");
					int ww = endL++;
					printf("b\tEnd%d\n",ww);
					printf("\nM%d:\n",lineM);
					lineM++;
					printf("li\t$t9,1\n");
					printf("\nEnd%d:\n",ww);
				//	pop();
				}
				else if(strcmp(node->node_value,"+")==0)
				{	//t1 = v1 + 1
					
					if(node->right->node_type==341 && node->left->node_type==340)
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
						printf("addiu\t$t%d,$t%d,%d\n",used_t+1,used_t,atoi(node->right->node_value));
						used_t++;
						printf("sw\t$t%d,%d($sp)\n",used_t,sp_offset);
						used_t--;
						sp_offset += 4;
					}
					else if(node->right->node_type==341 && node->left->node_type==341) //both numbers
					{
						printf("li\t$t%d,%d\n",used_t,atoi(node->left->node_value));
						printf("addiu\t$t%d, $t%d, %d\n",used_t+1, used_t, atoi(node->right->node_value));
						used_t++;
						printf("sw\t$t%d,%d($sp)\n",used_t,sp_offset);
						used_t--;
						sp_offset += 4;
					}
					else if(node->right->node_type==340 && node->left->node_type==340) //both var
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
						printf("lw\t$t%d,%d($sp)\n",used_t+1,search_elem(node->right->node_value));
						printf("add\t$t%d,$t%d,$t%d\n",used_t+2,used_t+1,used_t);
						printf("sw\t$t%d,%d($sp)\n",used_t+2,sp_offset);
						sp_offset += 4;
					}
					else
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->right->node_value));
						printf("addiu\t$t%d,$t%d,%d\n",used_t+1,used_t,atoi(node->left->node_value));
						used_t++;
						printf("sw\t$t%d,%d($sp)\n",used_t,sp_offset);
						used_t--;
						sp_offset += 4;
					}
				}
				else if(strcmp(node->node_value,"-")==0)
				{	//t1 = v1 + 1
					
					if(node->right->node_type==341 && node->left->node_type==340) 
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
						printf("li\t$t%d,%d\n",used_t+1,atoi(node->right->node_value));
						printf("subu\t$t%d,$t%d,%d\n",used_t+2,used_t+1,used_t);
						printf("sw\t$t%d,%d($sp)\n",used_t+2,sp_offset);
						sp_offset += 4;
					}
					else if(node->right->node_type==341 && node->left->node_type==341) //both numbers
					{
						printf("li\t$t%d,%d\n",used_t,atoi(node->left->node_value));
						printf("li\t$t%d,%d\n",used_t+1,atoi(node->right->node_value));
						printf("subu\t$t%d,$t%d,%d\n",used_t+2,used_t+1,used_t);
						printf("sw\t$t%d,%d($sp)\n",used_t+2,sp_offset);
						sp_offset += 4;
					}
					else if(node->right->node_type==340 && node->left->node_type==340) //both var
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
						printf("lw\t$t%d,%d\n",used_t+1,search_elem(node->right->node_value));
						printf("subu\t$t%d,$t%d,%d\n",used_t+2,used_t+1,used_t);
						printf("sw\t$t%d,%d($sp)\n",used_t+2,sp_offset);
						sp_offset += 4;
					}
					else
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->right->node_value));
						printf("li\t$t%d,%d\n",used_t+1,atoi(node->left->node_value));
						printf("subu\t$t%d,$t%d,%d\n",used_t+2,used_t+1,used_t);
						printf("sw\t$t%d,%d($sp)\n",used_t+2,sp_offset);
						sp_offset += 4;
					}
				}
				else if(strcmp(node->node_value,"*")==0)
				{	//t1 = v1 + 1
					
					if(node->right->node_type==341 && node->left->node_type==340) 
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
						printf("li\t$t%d,%d\n",used_t+1,atoi(node->right->node_value));
					}
					else if(node->right->node_type==341 && node->left->node_type==341) //both numbers
					{
						printf("li\t$t%d,%d\n",used_t,atoi(node->left->node_value));
						printf("li\t$t%d,%d\n",used_t+1,atoi(node->right->node_value));
					}
					else if(node->right->node_type==340 && node->left->node_type==340) //both var
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->left->node_value));
						printf("lw\t$t%d,%d\n",used_t+1,search_elem(node->right->node_value));
					}
					else
					{
						printf("lw\t$t%d,%d($sp)\n",used_t,search_elem(node->right->node_value));
						printf("li\t$t%d,%d\n",used_t+1,atoi(node->left->node_value));
					}
					printf("mult\t$t%d,$t%d\n",used_t,used_t+1);				
					printf("MFLO\t$t%d\n",used_t+2);
					printf("sw\t$t%d,%d($sp)\n",used_t+2,sp_offset);
					sp_offset += 4;
				}
			}
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
		&& strcmp(s, "WHILE") && strcmp(s, "IF") && strcmp(s, "REPEAT") && strcmp(s, "CASE") && strcmp(s, "FOR")
		&& strcmp(s, ".")))
		return 1;
	return 0;
}

void stack_main(AstNode *node,int p,char *tex){
	printf("addiu\t$sp, $sp, -%d\n",p*4);
	int i;
	AstNode *as = node->left->right->left;
	for (i=0;i<p-1;i++){
		printf("sw\t$a%d, %d($sp)\n",i,i*4);
		insert_elem(i*4,as->left->node_value);
		as = as->right;

		//insert_elem()
		//varT++;
	}
	printf("sw\t$ra, %d($sp)\n",i*4);
	return ;
}

void stack_main_2(AstNode *node,int p,char *tex){
	int i = p-1;
	//printf("mamamamma");
	printf("lw\t$ra, %d($sp)\n",i*4);
	
	for (i=p-2;i>=0;i--){
		printf("lw\t$a%d, %d($sp)\n",i,i*4);
		//printf("abcd\n");
		//printf("idiidi_%s\n",as->left->node_value);
		
		//varT++;
	}
	printf("addiu\t$sp, $sp, %d\n\n",p*4);
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
	int i;
	if(!strcmp(node->node_value, "PROC")){
		//printf("i am in a procedure\n");
		while (node != NULL){
			printf("%s:\n",node->left->left->node_value);
			formal = count_formal(node->left->right->left);
			//printf("total_args_%d",formal);
			stack_main(node,formal+1,node->left->left->node_value);
			postOrder(node->left->right->right->right);
			
			AstNode *nop = node->left->right->right->right->right;
			while(strcmp(nop->node_value,"RETURN") != 0)
			{
				nop = nop->right;
			}
			//printf("return state is:_%s_\n",nop->right->node_value);
			//printf("return offset is:_%d_\n",search_elem(nop->right->node_value));
			//printf("sw\t$v1,%d($sp)\n",search_elem(nop->right->node_value));
			printf("lw\t$v1,%d($sp)\n",search_elem(nop->right->node_value));

			stack_main_2(node,formal+1,node->left->left->node_value);
			
			postOrder(node->left->right->right->left);
			node = node->right;
		}
	}
}

void string_call(AstNode *node){
	if (!strcmp(node->right->node_value,"STRCAT")){
		string_concatenate(node->right->right->node_value,node->right->left->node_value,node->left->node_value);
	}
	else if (!strcmp(node->right->node_value,"STRREV")){
			string_reverse(node->right->left->node_value,node->left->node_value);
	}
	else if (!strcmp(node->right->node_value,"STRCPY")){	
			string_copy(node->right->right->node_value,node->right->left->node_value,node->left->node_value);
	}
	else{
			//printf("inserts_%d_%s_",strlen(remove_q(node->right->node_value)),node->right->node_value);
			char *subbuff = (char*)malloc(sizeof(char));
			char *b = node->right->node_value;
			memcpy(subbuff,(b+1),strlen(node->right->node_value)-2);
			subbuff[strlen(node->right->node_value)-2] = '\0';
			insert_strings(subbuff,node->left->node_value);
	}
}

void proc_call_def(AstNode *node){
	int formal = 0;
	int t1;
	//printf("0aaaaaa_%s ",node->left->node_value);
	AstNode *temp = node->right->right;
	while (!strcmp(temp->node_value,"EXPR")){
		if (temp->left->node_type==340){
			printf("lw\t$a%d,%d($sp)\n",formal,search_elem(temp->left->node_value));
			temp = temp->right;
		}
		else{
			t1 = tac(temp->left);
			
			char * str;
			str = (char *)malloc(sizeof(char));
			sprintf(str,"t%d\0",t1-1);
			//printf("STR =>>>>>>>> |%s|\n",str);

			//printf("At %d\n",search_elem(str));
			printf("lw\t$a%d, %d($sp)\n",formal,search_elem(str));
			//printf("hmm\n");
			temp = temp->right;
		}
		formal++;
	}
	if (temp->node_type==340){
		printf("lw\t$a%d,%d($sp)\n",formal,search_elem(temp->node_value));
	}
	else if (temp->node_type==341){
		printf("li\t$a%d,%s \n",formal,temp->node_value);
	}
	else{
		t1 = tac(temp);
		char * str;
			str = (char *)malloc(sizeof(char));
			sprintf(str,"t%d\0",t1-1);
			printf("lw\t$a%d, %d($sp) \n",formal,search_elem(str));
	}
	printf("jalr\t%s\n\n",node->right->left->node_value);
}

void set_call(AstNode *node){
	printf("sets_%s",node->left->node_value);
	//char str[3];
	if (!strcmp(node->right->node_value,"+")){
		printf("Union Happenning");
		union_new(node->right->left->node_value,node->right->right->node_value,node->left->node_value);
		//search_insert(node->right->left->node_value,node->left->node_value);
		//search_insert(node->right->right->node_value,node->left->node_value);
	}
	else if (!strcmp(node->right->node_value,"-")){
		diff_new(node->right->left->node_value,node->right->right->node_value,node->left->node_value);	
	}
	else if (!strcmp(node->right->node_value,"*")){
		inter_new(node->right->left->node_value,node->right->right->node_value,node->left->node_value);
	}
	else if (!strcmp(node->right->node_value,"/")){
		diff_new(node->right->left->node_value,node->right->right->node_value,node->left->node_value);
		diff_new(node->right->right->node_value,node->right->left->node_value,node->left->node_value);
	}
	else if (node->right->node_type==340){
		as_new(node->right->node_value,node->left->node_value);
	}
	else{
		AstNode *temp = node->right->right;
		AstNode *temp2 = node->right->right;
		while (!strcmp(temp->node_value,"SET_ELEM")){
			if (isOper(temp->left)){
				//printf("SEEE%s",temp->left->node_value);
				int t1 = tac(temp->left);
				char *s = (char*)malloc(sizeof(char));
				sprintf(s, "t%d\0", t1-1);
				//printf("mrea_%s",s);
				insert_new(s,node->left->node_value);
				// one problem with the char [] to char * conversion
			}
			else{
				insert_new(temp->left->node_value,node->left->node_value);
			}
			temp2 = temp;
			temp = temp->right;
		}
		if (isOper(temp2->right)){
			int t1 = tac(temp2->right);
			char *s = (char*)malloc(sizeof(char));
			sprintf(s, "t%d\0", t1-1);
			insert_new(s,node->left->node_value);
		}
		else
			insert_new(temp2->right->node_value,node->left->node_value);
	}
	//print_set();
	return ;
}

void postOrder(AstNode* node)
{
	//printf("hiiamm");
	if (node == NULL)
		return;
	//printf("%s %d\n", node->node_value, node->node_type);

	if (!strcmp(node->node_value,"MAIN_AUX")){
		printf("main:\n");
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

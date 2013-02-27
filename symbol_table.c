#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "y.tab.h"

#define IDENT_TOKEN 1

int check=0;

struct ListNode *Insert(char *value){
	struct ListNode *newNode;
	newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
	newNode->lexeme = (char *)malloc(1 + strlen(value)*sizeof(char));
	strcpy(newNode->lexeme, value);
	//printf("Inserted %s\n",newNode->lexeme);
	newNode->Type = IDENT_TOKEN;
	newNode->NextNode = NULL;

	if (check==0){
		SymbolTable_Head = newNode;
		SymbolTable_Next = newNode;
		check=1;
	}
	else{
		SymbolTable_Next->NextNode = newNode;
		SymbolTable_Next = newNode;
	}

	return newNode;
}

struct ListNode *Lookup(char *value){
	struct ListNode *list = SymbolTable_Head;
	while(list!=NULL && strcmp(list->lexeme, value)!=0){
		list = list->NextNode;
	}
	if(list!=NULL)
		return list;
	return NULL;
}

void print_token(){
	struct ListNode *list = SymbolTable_Head;
	while(list!=NULL){
		printf("\n ###### %s ###### \n",list->lexeme);
		list = list->NextNode;
	}
}

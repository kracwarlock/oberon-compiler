#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	char *lexeme;
	int Type;
	int keyWordNum;
	struct ListNode *NextNode;
	
};

struct ListNode *SymbolTable_Head;
struct ListNode *SymbolTable_Next;
void print_token();
struct ListNode *Insert(char *value);
struct ListNode *Lookup(char *value);

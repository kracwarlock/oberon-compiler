#include <stdio.h>
#include <malloc.h>
#include "symbol_table.h"
#include "ast.h"

extern unsigned long lineCount;

#define NULL 0

void createSymbolTable(SymbolTable* symbolTable)
{
	int scope = 0;
	tableEntry* owner;
	tableEntry* param;
	
	// This is a special case, since it's the first entry.
	symbolTable->first = createTableEntry("ORD",NULL,VAL,FUNC_NAME,0,NULL,NULL,++scope,0,NULL);
	symbolTable->last = symbolTable->first;	
	// addFormalParameter(symbolTable, createTableEntry("_ORD",NULL,VAL,IDENTIFIER,0,NULL,NULL,NULL,0,NULL));
	// // This is how it should normally be, with the optional addition of formal parameters.
	// addSymbolTableEntry(symbolTable, createTableEntry("CHR",NULL,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));	
	// addFormalParameter(symbolTable, createTableEntry("_CHR",NULL,VAL,IDENTIFIER,0,NULL,NULL,NULL,NULL,0,NULL));
	
	// addSymbolTableEntry(symbolTable, createTableEntry("TOINT",NULL,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));
	// addFormalParameter(symbolTable, createTableEntry("_TOINT",NULL,VAL,IDENTIFIER,0,NULL,NULL,NULL,NULL,0,NULL));
	
	// addSymbolTableEntry(symbolTable, createTableEntry("TRUE",BOOLEAN,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));
	
	// addSymbolTableEntry(symbolTable, createTableEntry("FALSE",BOOLEAN,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));	
}

void destroySymbolTable(SymbolTable* symbolTable)
{
	tableEntry* te = symbolTable->first;
	tableEntry* last = te;
	
	while (te != NULL)
	{
		last = te;
		te = te->next;
		free(last);
	}	
}

void addSymbolTableEntry(SymbolTable* symbolTable, tableEntry* entry)
{
	printf("wwwwwwwwwwwwwwwwwwww %s\n",entry->name);
	if (findEntry(symbolTable, entry->name, entry->entry_owner) != NULL)
	{
		if (entry->mode == PROC_NAME || entry->mode == FUNC_NAME)
		{
			printf("******  Procedure redeclared ******** %s \n",entry->name);
		}
		else if (entry->mode == IDENTIFIER)
		{
			printf("******  Identifier Redeclared ******** %s \n",entry->name);
		}
		//free(entry);
		return;
	}
	else
	{
		symbolTable->last->next = entry;
		symbolTable->last = symbolTable->last->next;
		return;
	}
	printf("khtam\n");
}

tableEntry* findEntry(SymbolTable* symbolTable, char* name, tableEntry *owner_func)
{
	tableEntry *ret = NULL;
	while (owner_func != NULL){
		tableEntry* te = symbolTable->first;
		while (te != NULL)
		{
			if (te->entry_owner != NULL)
				printf("asasasasasasmm_%s_%s_%d_%s\n",te->name,name,te->mode,te->entry_owner->name);
			else
				printf("asasasasasas %s %d\n",te->name,te->mode);
			printf("dddddddddd");
			if (te->mode == PROC_NAME && te == owner_func){
				printf("maa me\n");
				tableEntry *goi = te->type->formal_params;
				while (goi != NULL)
				{
					if (strcmp(goi->name,name) == 0){
						printf("rang_de_basanti\n");
						ret = goi;
						break;
					}
					goi = goi->next;
				}
			}
			else if (strcmp(te->name,name) == 0 && te->entry_owner == owner_func)
			{
				printf("rerererere %s\n",name);
				ret = te;
			}		
			te = te->next;
		}	
		owner_func = owner_func->next_owner;
	}
	return ret;
}

void changeVariableType(SymbolTable* symbolTable, type_tableEntry *ty,int type)
{
	tableEntry* te = symbolTable->first;
	
	while (te != NULL)
	{
		if (te->type == NULL && ty != NULL)
		{
			printf("lplpl %s %d\n",te->name,ty->type);
			te->type = ty;
			te->t = type;
		}
		te = te->next;
	}
}

tableEntry* createTableEntry(char* name, type_tableEntry *type_st, int passType, int mode, int order,
							tableEntry* owner, int scope, int procScope,tableEntry* next , tableEntry *owner_func)
{
	tableEntry* te = (tableEntry*)malloc(sizeof(tableEntry));
	if (te == NULL) return NULL;
	
	te->name = name;
	te->type = type_st;
	te->passType = passType;
	te->mode = mode;
	te->order = order;
	te->owner = owner;
	te->scope = scope;
	te->procScope = procScope;
	te->next = NULL;
	te->entry_owner = owner_func;
	
	return te;
}

type_tableEntry* create_typeEntry(int type, type_tableEntry* tp, tableEntry* formal)
{
	type_tableEntry* te = (type_tableEntry*)malloc(sizeof(type_tableEntry));
	if (te == NULL) return NULL;
	

	printf("maa %d\n",type);
	te->type = type;
	te->tp = tp;
	te->formal_params = formal;
	
	return te;
}


tableEntry* getOwner(tableEntry* entry)
{
	if (entry == NULL) return NULL;
	
	while(entry->owner != NULL)
	{
		entry = entry->owner;
	}
	
	return entry;
}

tableEntry* getScopeOwner(SymbolTable* symbolTable, int scope)
{
	if (scope == 0) return NULL;
	
	tableEntry* te = symbolTable->first;
	while (te != NULL)
	{
		if (te->procScope == scope) return te;
		
		te = te->next;
	}
	
	return NULL;
}

void add_type_FormalParameter(type_tableEntry *p,tableEntry *t){
	if (p->formal_params == NULL){
		p->formal_params = t;
		t->next = NULL;
	}
	else{
		tableEntry *k;
		k = p->formal_params;
		while (k->next != NULL){
			k=k->next;
		}
		k->next = t;
	}
}

void change_type_FormalParamType (type_EntryTable *p , type_tableEntry *t){
	type_tableEntry *k = p->last;
	tableEntry  *u = k->formal_params;
	while (u != NULL){
		printf("dddddddmmm %s\n",u->name);
		if (u->type == NULL){
			printf("mummy %s %d\n",u->name,t->type);
			u->type = t;
		}
		u=u->next;
	}
}

type_EntryTable *createtypeEntry(){
	type_EntryTable *p = (type_EntryTable*)malloc(sizeof(type_EntryTable));
	p->first = NULL;
	p->last = p->first;
	return p;
}

void insert_last(type_EntryTable *t,type_tableEntry *p){
	if (t->first == NULL){
		printf("ho_gaya");
		t->first = p;
		t->last = p;
	}
	else{
		type_tableEntry *k = t->first;
		while(k->next != NULL){
			k=k->next;
		}
		printf("insert_%d_%d",t->last->type,p->type);
		k->next = p;
		t->last = p;
	}
}

void remove_last(type_EntryTable *t){
	if (t->first == NULL)
		return;
	if (t->first->next == NULL){
		printf("nahi_ho_gaya");
		//free(t->first);
		t->first = NULL;
		t->last = t->first ;
	}
	else{
		type_tableEntry *k = t->first;
		type_tableEntry *prev = t->first;
		while(k->next != NULL){
			prev = k;
			k=k->next;
		}
		//free(k);
		prev->next = NULL;
		t->last = prev;
	}
}

type_tableEntry *type_lookup(SymbolTable *sym,char *look,int scope){
	tableEntry* te = sym->first;
	while (te != NULL)
	{
		if (strcmp(te->name,look) == 0 && te->scope == scope && te->t == TYPE_VALUE)
		{
			return te->type;
		}		
		te = te->next;
	}	
	return NULL;
}

int module_lookup_bool(SymbolTable *sym,char *look){
	tableEntry* te = sym->first;
	while (te != NULL)
	{
		if (strcmp(te->name,look) == 0 && te->t == MODULE_VALUE)
		{
			return 1;
		}		
		te = te->next;
	}	
	return 0;
}

void print_Symbol(SymbolTable* symbolTable){
	tableEntry *te = symbolTable -> first;
	while (te!=NULL){
		printf("***********%s*********** \n",te->name);
		te=te->next;
	}
}

tableEntry *find_formal_entry(char *name,tableEntry *t){
	tableEntry *p = t;
	while (p!=NULL){
		printf("checking... %s",name);
		if (strcmp(t->name,name) == 0){
			return t;
		}
		p=p->next;
	}
	return NULL;
}

int type_check(type_tableEntry *first,type_tableEntry *second){
	//printf("sds_%d_%d_",first->type,second->type);
	tableEntry *f1;
	tableEntry *f2;
	while (first->tp!=NULL && second->tp!=NULL){
		printf("in_here1_%d_%d\n",first->type,second->type);
		if (first->type==second->type){
			if (type_check(first->tp,second->tp)){
				if (first->formal_params != NULL && second->formal_params != NULL){
					f1=first->formal_params;
					f2=second->formal_params;
					while(f1 !=NULL && f2 !=NULL){
						if (!type_check(f1->type,f2->type))
							return 0;
						f1=f1->next;
						f2=f2->next;
					}
				}
				else{
					if (first->formal_params == NULL && second->formal_params == NULL)
						return 1;
					else
						return 0;
				}
			}
			else
				return 0;
		}
		else
			return 0;
		first=first->tp;
		second=second->tp;
	}
	if (second->tp==NULL && first->type==second->type){
				printf("in_here2_%d_%d\n",first->type,second->type);
				if (first->formal_params != NULL && second->formal_params != NULL){
					f1=first->formal_params;
					f2=second->formal_params;
					while(f1 !=NULL && f2 !=NULL){
						if (!type_check(f1->type,f2->type))
							return 0;
						f1=f1->next;
						f2=f2->next;
					}
					return 1;
				}
				else{
					if (first->formal_params == NULL && second->formal_params == NULL)
						return 1;
					else
						return 0;
				}
	}
	else
		return 0;
}

void type_printf(SymbolTable* symbolTable){
	tableEntry *te = symbolTable -> first;
	while (te!=NULL){
		if (te->type->type != NULL || te->type != NULL){
			// if (te->type->type == RECORD_TYPE){
			// 	tableEntry *l = te->type->formal_params;
			// 	while  (l != NULL){
			// 		if (l->type->type == 5 && l->type->next != NULL)
			// 			printf("new_namne_%s_%d",l->name,l->type->next->type);
			// 		printf("name_ident_%s %d\n",l->name,l->type->type);
			// 		l=l->next;
			// 	}
			// }
			if (te->type->type==6 && te->type->formal_params!=NULL)
				printf("popl_%d",te->type->formal_params->type->tp->tp->type);
			printf("type_pr_%s %d \n",te->name,te->type->type);
		}
		te=te->next;
	}
}

#include <stdio.h>
#include "symbol_table.h"
#include "ast.h"

extern unsigned long lineCount;

void createSymbolTable(SymbolTable* symbolTable)
{
	int scope = 0;
	tableEntry* owner;
	tableEntry* param;
	
	// This is a special case, since it's the first entry.
	symbolTable->first = createTableEntry("ORD",INTEGER,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL);
	symbolTable->last = symbolTable->first;	
	addFormalParameter(symbolTable, createTableEntry("_ORD",CHAR,VAL,IDENTIFIER,0,NULL,NULL,NULL,NULL,0,NULL));
	
	// This is how it should normally be, with the optional addition of formal parameters.
	addSymbolTableEntry(symbolTable, createTableEntry("CHR",CHAR,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));	
	addFormalParameter(symbolTable, createTableEntry("_CHR",INTEGER,VAL,IDENTIFIER,0,NULL,NULL,NULL,NULL,0,NULL));
	
	addSymbolTableEntry(symbolTable, createTableEntry("TOINT",INTEGER,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));
	addFormalParameter(symbolTable, createTableEntry("_TOINT",REAL,VAL,IDENTIFIER,0,NULL,NULL,NULL,NULL,0,NULL));
	
	addSymbolTableEntry(symbolTable, createTableEntry("TRUE",BOOLEAN,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));
	
	addSymbolTableEntry(symbolTable, createTableEntry("FALSE",BOOLEAN,VAL,FUNC_NAME,0,NULL,0,++scope,NULL,0,NULL));	
}

void destroySymbolTable(SymbolTable* symbolTable)
{
	tableEntry* te = symbolTable->first;
	tableEntry* last = te;
	
	while (te != NULL)
	{
		free(last);
		last = te;
		te = te->next;
	}	
}

int addSymbolTableEntry(SymbolTable* symbolTable, tableEntry* entry)
{
	if (findEntry(symbolTable, entry->name, entry->scope) != NULL)
	{
		if (entry->mode == PROC_NAME || entry->mode == FUNC_NAME)
		{
			SEM_ERR_REDECLARE_PROCEDURE(lineCount, entry->name);
		}
		else if (entry->mode == IDENTIFIER)
		{
			SEM_ERR_REDECLARE_VARIABLE(lineCount, entry->name);
		}
		free(entry);
		return 0;
	}
	else
	{
		symbolTable->last->next = entry;
		symbolTable->last = symbolTable->last->next;
		return 1;
	}
}

void addFormalParameter(SymbolTable* symbolTable, tableEntry* entry)
{
	tableEntry* owner = symbolTable->last;
	owner->formal_params = entry;
	entry->order = owner->order + 1;
	
	entry->owner = getOwner(owner);
	
	entry->scope = entry->owner->procScope;
	entry->procScope = entry->owner->procScope;
	++entry->owner->num_params;
	if (0 == addSymbolTableEntry(symbolTable,entry))
	{
		owner->formal_params = NULL;
		--owner->owner->num_params;
	}
}

tableEntry* findEntry(SymbolTable* symbolTable, char* name, int scope)
{
	tableEntry* te = symbolTable->first;
	while (te != NULL)
	{
		if (strcmp(te->name,name) == 0 && te->scope == scope)
		{
			return te;
		}		
		te = te->next;
	}	
	return NULL;
}

void changeFormalParamType(tableEntry* owner, int type)
{
	tableEntry* te = owner;
	while (te->formal_params != NULL)
	{
		te = te->formal_params;
		if (te->type == NOTSET)
		{
			te->type = type;
		}
	}
}

void changeFormalFunctionType(tableEntry* function, int type)
{
	function->type = type;
	
	if (type != VOID && type != ERROR)
	{
		function->mode = FUNC_NAME;
	}
}

void changeVariableType(SymbolTable* symbolTable, int type)
{
	tableEntry* te = symbolTable->first;
	
	while (te != NULL)
	{
		if (te->type == NOTSET)
		{
			te->type = type;
		}
		te = te->next;
	}
}

tableEntry* createTableEntry(char* name, int type, int passType, int mode, int order,
							tableEntry* owner, int scope, int procScope, tableEntry* formal_params,
							int num_params, tableEntry* next)
{
	tableEntry* te = (tableEntry*)malloc(sizeof(tableEntry));
	if (te == NULL) return NULL;
	
	te->name = name;
	te->type = type;
	te->passType = passType;
	te->mode = mode;
	te->order = order;
	te->owner = owner;
	te->scope = scope;
	te->procScope = procScope;
	te->formal_params = formal_params;
	te->num_params = num_params;
	te->next = next;
	
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

int getTypesCompatible(symbolType target, symbolType exp)
{
	switch(target)
	{
		case INTEGER:
			if (exp == INTEGER) return 1;
			break;
		case REAL:
			if (exp == REAL || exp == INTEGER) return 1;
			break;
		case BOOLEAN:
			if (exp == BOOLEAN) return 1;
			break;
		case CHAR:
			if (exp == CHAR) return 1;
			break;
	}	
	return 0;
}

symbolType determineType(symbolType t1, symbolType t2, operationType op, char* symbol)
{
	if (op != LOGICAL)
	{
		if (t1 != NOTSET && t2 == NOTSET) return t1;
		if (t1 == NOTSET && t2 != NOTSET) return t2;
	}
	
	switch (op)
	{
		case ARITHMETIC:
			if (t1 == REAL)
			{
				if (t2 == REAL) return REAL;
				if (t2 == INTEGER) return REAL;
			}
			else if (t1 == INTEGER)
			{
				if (t2 == REAL) return REAL;
				if (t2 == INTEGER) return INTEGER;
			}
			else if (t1 == CHAR && t2 == CHAR) return CHAR;
			break;
		case RELATIONAL:
			if (t1 == REAL)
			{
				if (t2 == REAL) return BOOLEAN;
				if (t2 == INTEGER) return BOOLEAN;
			}
			else if (t1 == INTEGER)
			{
				if (t2 == REAL) return BOOLEAN;
				if (t2 == INTEGER) return BOOLEAN;
			}
			else if (t1 == BOOLEAN && t2 == BOOLEAN) return BOOLEAN;
			else if (t1 == CHAR && t2 == CHAR) return BOOLEAN;
			break;
		case LOGICAL:
			if (t1 == BOOLEAN && t2 == BOOLEAN) return BOOLEAN;
	}
	
	if (t1 != ERROR && t2 != ERROR)
	{
		switch (op)
		{
			case ARITHMETIC:
				SEM_ERR_OPERATION_TYPE_ERROR(lineCount, symbol);
				break;
			case RELATIONAL:
				SEM_ERR_RELATION_TYPE_ERROR(lineCount, symbol);
				break;
			case LOGICAL:
				SEM_ERR_UNARY_TYPE_ERROR(lineCount, symbol);
				break;
		}
	}
	
	return ERROR;
}

void printSymbolTableHtml(SymbolTable* symbolTable)
{
	tableEntry* te = symbolTable->first;
	printf("<table border=1>\n");
	printf("<tr><td>NAME</td><td>TYPE</td><td>PASSTYPE</td><td>MODE</td><td>ORDER</td><td>OWNER</td><td>SCOPE</td><td>PROCSCOPE</td><td>FORMPARAMS</td><td>NUMPARAMS</td><td>NEXT</td></tr>\n");
	while (te != NULL)
	{
		printf("<tr id=\"entry-%s%d\">\n",te->name,te->scope);
		printf("<td><a href=\"#define-%s%d\" class=\"symboltable\">%s</a></td>",te->name,te->scope,te->name);
		printf("<td>%s</td>",getSymbolType(te->type));
		printf("<td>%s</td>",getSymbolPassType(te->passType));
		printf("<td>%s</td>",getSymbolMode(te->mode));
		printf("<td>%d</td>",te->order);
		printf("<td><a href=\"#entry-%s%d\" class=\"symboltable\">%s</a></td>",(te->owner != NULL ? te->owner->name : "&nbsp;"),(te->owner != NULL ? te->owner->scope : 0),(te->owner != NULL ? te->owner->name : "&nbsp;"));
		printf("<td>%d</td>",te->scope);
		printf("<td>%d</td>",te->procScope);
		printf("<td><a href=\"#entry-%s%d\" class=\"symboltable\">%s</a></td>",(te->formal_params != NULL ? te->formal_params->name : "&nbsp;"),(te->formal_params != NULL ? te->formal_params->scope : 0),(te->formal_params != NULL ? te->formal_params->name : "&nbsp;"));
		printf("<td>%d</td>",te->num_params);
		printf("<td><a href=\"#entry-%s%d\" class=\"symboltable\">%s</a></td>",(te->next != NULL ? te->next->name : "&nbsp;"),(te->next != NULL ? te->next->scope : 0),(te->next != NULL ? te->next->name : "&nbsp;"));
		printf("</td>\n");
		te = te->next;
	}
	printf("</table><hr>");
}

void printSymbolTable(SymbolTable* symbolTable)
{
	tableEntry* te = symbolTable->first;
	int bp = 1;
	while (te != NULL)
	{
		printf("%s\t",te->name);
		printf("%d ",te->type);
		printf("%d ",te->passType);
		printf("%d ",te->mode);
		printf("%d ",te->order);
		printf("%s\t",(te->owner != NULL ? te->owner->name : ""));
		printf("%d ",te->scope);
		printf("%d ",te->procScope);
		printf("%s\t",(te->formal_params != NULL && te->formal_params->name != NULL ? te->formal_params->name : ""));
		printf("%d ",te->num_params);
		printf("%s\n",(te->next != NULL ? te->next->name : ""));
		te = te->next;
	}
}

char* getSymbolType(symbolType type)
{
	switch (type)
	{
		case INTEGER:
			return "INTEGER";
		case REAL:
			return "REAL";
		case CHAR:
			return "CHAR";
		case BOOLEAN:
			return "BOOLEAN";
		case VOID:
			return "VOID";
		case ERROR:
			return "ERROR";
		case NOTSET:
			return "NOTSET";
	}
	return "UNKNOWN";
}

char* getSymbolPassType(symbolPassType type)
{
	switch (type)
	{
		case REF:
			return "REF";
		case VAL:
			return "VAL";
	}
	return "UNKNOWN";
}

char* getSymbolMode(symbolMode type)
{
	switch (type)
	{
		case IDENTIFIER:
			return "IDENTIFIER";
		case NUMBER:
			return "NUMBER";
		case PROC_NAME:
			return "PROC_NAME";
		case FUNC_NAME:
			return "FUNC_NAME";
	}
	return "UNKNOWN";
}

char* getOperationType(operationType type)
{
	switch (type)
	{
		case ARITHMETIC:
			return "ARITHMETIC";
		case RELATIONAL:
			return "RELATIONAL";
		case LOGICAL:
			return "LOGICAL";
	}
	return "UNKNOWN";
}

void printEntryStats(tableEntry* te)
{
	if (te != NULL)
	{
		printf("\n\t\tEntry %s Stats:\n",te->name);
		printf("\t\tType: %s\n",getSymbolType(te->type));
		printf("\t\tPassType: %s\n",getSymbolPassType(te->passType));
	}
	else
	{
		printf("\n\t\tNULL Entry\n");
	}
}




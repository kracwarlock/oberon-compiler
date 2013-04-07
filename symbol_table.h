#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

typedef enum type_ident{
	TYPE_VALUE,
	VAR_VALUE,
	MODULE_VALUE
} type_ident;

typedef enum operationType
{
	ARITHMETIC,
	RELATIONAL,
	LOGICAL,
	NUM_OP_TYPES
} operationType;
char* getOperationType(operationType type);

typedef enum symbolType
{
	INTEGER,   //1
	REAL,// 2
	BOOLEAN,// 3
	CHAR,// 4
	LONGREAL,// 5
	ARRAY_TYPE,// 6
	RECORD_TYPE,// 7
	PROC_TYPE,// 8
	POINTER_TYPE,// 9
	SET_TYPE,// 10
	QUALIDENT_TYPE,// 11
	VOID,// 12
	ERROR,	// 13
	NOTSET,// 14
	NO,
	NUM_SYMBOL_TYPES// 15
} symbolType;
char* getSymbolType(symbolType type);

typedef enum symbolPassType
{
	REF,
	VAL,
	NUM_PASS_TYPES
} symbolPassType;
char* getSymbolPassType(symbolPassType type);

typedef enum symbolMode
{
	IDENTIFIER,
	NUMBER,
	PROC_NAME,
	FUNC_NAME,
	NUM_MODES
} symbolMode;
char* getSymbolMode(symbolMode mode);

typedef struct type_tableEntry {
	int num; // for constant values
	symbolType type; //INTEGER, REAL, BOOLEAN, CHAR, NULL
	int num_params;
	struct tableEntry *formal_params;
	struct type_tableEntry* tp;
	struct type_tableEntry *next;
} type_tableEntry;

typedef struct tableEntry {
	char* name ; //A string containing the characters for the identifier
	struct type_tableEntry* type;
	symbolPassType passType; //if it is REFERENCE or VALUE for a proc formal parameter
	symbolMode mode; //identifier, number, procedure_name, function_name
	type_ident t;
	int order; //the order of a formal parameter (position in the declaration)
	struct tableEntry* owner; //point to the owner of this identifier (formal parameter) – proc it is declared INTEGER
	struct tableEntry *entry_owner;
	int scope; //the scope level: 0, 1, 2, 3,....
	int procScope; //for a proc_id, the scope number of the proc/func body
	struct tableEntry *next_owner;
	struct tableEntry* next; // point to next table entry in a linked-list structure
} tableEntry;

typedef struct SymbolTable {
	tableEntry* first;
	tableEntry* last;
} SymbolTable;

typedef struct type_EntryTable {
	type_tableEntry* first;
	type_tableEntry* last;
} type_EntryTable;

typedef struct owner_list {
	tableEntry* first;
	tableEntry* last;
} owner_list;

void createSymbolTable(SymbolTable* symbolTable);
void destroySymbolTable(SymbolTable* symbolTable);

tableEntry* findEntry(SymbolTable* symbolTable, char* name, tableEntry *owner_func);
tableEntry* getOwner(tableEntry* entry);
tableEntry* getScopeOwner(SymbolTable* symbolTable, int scope);

void addSymbolTableEntry(SymbolTable* symbolTable, tableEntry* entry);
void addFormalParameter(SymbolTable* symbolTable, tableEntry* entry);
tableEntry* createTableEntry(char* name, type_tableEntry* type_st ,int passType, int mode,int order, tableEntry* owner, int scope, int procScope, tableEntry* next,tableEntry *owner_func);

void changeFormalParamType(tableEntry* owner, int type);
void changeVariableType(SymbolTable* symbolTable,  type_tableEntry *ty,int type);

#endif

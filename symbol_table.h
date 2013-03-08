#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

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
	INTEGER_TYPE,
	REAL_TYPE,
	BOOLEAN_TYPE,
	CHAR_TYPE,
	VOID,
	ERROR,	
	NOTSET,
	NUM_SYMBOL_TYPES
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

typedef struct tableEntry {
	char* name ; //A string containing the characters for the identifier
	symbolType type; //INTEGER, REAL, BOOLEAN, CHAR, NULL
	symbolPassType passType; //if it is REFERENCE or VALUE for a proc formal parameter
	symbolMode mode; //identifier, number, procedure_name, function_name
	int order; //the order of a formal parameter (position in the declaration)
	struct tableEntry* owner; //point to the owner of this identifier (formal parameter) – proc it is declared in
	int scope; //the scope level: 0, 1, 2, 3,....
	int procScope; //for a proc_id, the scope number of the proc/func body
	struct tableEntry* formal_params; //pointer to first formal parameter for a proc_id, or the next formal_parm i
	int num_params; // the number of formal parameters
	struct tableEntry* next; // point to next table entry in a linked-list structure
} tableEntry;

typedef struct SymbolTable {
	tableEntry* first;
	tableEntry* last;
} SymbolTable;

void createSymbolTable(SymbolTable* symbolTable);
void destroySymbolTable(SymbolTable* symbolTable);

tableEntry* findEntry(SymbolTable* symbolTable, char* name, int scope);
tableEntry* getOwner(tableEntry* entry);
tableEntry* getScopeOwner(SymbolTable* symbolTable, int scope);

int addSymbolTableEntry(SymbolTable* symbolTable, tableEntry* entry);
void addFormalParameter(SymbolTable* symbolTable, tableEntry* entry);
tableEntry* createTableEntry(char* name, int type, int passType, int mode, int order, tableEntry* owner, int scope, int procScope, tableEntry* formal_params, int num_params, tableEntry* next);

void changeFormalParamType(tableEntry* owner, int type);
void changeVariableType(SymbolTable* symbolTable, int type);

symbolType determineType(symbolType t1, symbolType t2, operationType op, char* symbol);
int getTypesCompatible(symbolType target, symbolType exp);

void printEntryStats(tableEntry* te);

void printSymbolTable(SymbolTable* symbolTable);
void printSymbolTableHtml(SymbolTable* symbolTable);
#endif
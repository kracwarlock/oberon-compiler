all : clean oberon

oberon :	y.tab.o lex.yy.o
	gcc -o oberon symbol_table.c y.tab.o lex.yy.o  -ly -ll

y.tab.o : 	y.tab.c
	gcc -c y.tab.c

lex.yy.o :	lex.yy.c y.tab.h 
	gcc -c lex.yy.c

y.tab.c :	oberon.y
	yacc -d oberon.y

lex.yy.c :	lex.l
	lex lex.l

clean : 
	-rm y.tab.*
	-rm lex.yy.*
	-rm out*
	-rm oberon

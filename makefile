all: lex.l
	lex lex.l
	gcc lex.yy.c -lfl

test:
	./a.out < sample/input_2.m

clean:
	rm a.out lex.yy.c
#!/bin/bash

yacc -d oberon.y
lex lex.l
gcc lex.yy.c y.tab.c -o main

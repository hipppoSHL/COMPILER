c-- : y.tab.o lex.yy.o tac.o util.a
	gcc -o c-- y.tab.o lex.yy.o tac.o util.a -ly -ll

tac.o : tac.c
	gcc -c -o tac.o tac.c

y.tab.o : y.tab.c
	gcc -c -o y.tab.o y.tab.c

lex.yy.o : lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

y.tab.c : bar.y
	yacc -d bar.y

lex.yy.c : foo.l
	flex foo.l

clean :
	rm -f c-- lex.yy.o lex.yy.c y.tab.o y.tab.c y.tab.h tac.o

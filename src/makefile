LEX = flex 
YACC = bison -d
CC = g++

eula: lex.yy.c parser.tab.c
	g++ lex.yy.c parser.tab.c -o eula

lex.yy.c: lex.l
	flex lex.l

parser.tab.c: parser.y
	bison -d --report=state parser.y

clean:
	rm lex.yy.c parser.tab.* parser.output eula
LEX = flex 
YACC = bison -d
CC = g++

eula: lex.yy.c parser.tab.c
	$(CC) lex.yy.c parser.tab.c -o eula

lex.yy.c: lex.l
	$(LEX) lex.l

parser.tab.c: parser.y
	$(YACC) -d --report=state parser.y

clean:
	rm lex.yy.c parser.tab.* parser.output eula
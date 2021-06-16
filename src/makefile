LEXER   = flex 
PARSER  = bison
POPT    = -vd
CXX     = g++
COPT    = -g

default:
	($(PARSER) $(POPT) parser.y && \
	$(LEXER) lex.l && \
	$(CXX) $(COPT) symbol_table.cpp ast.cpp parser.tab.c lex.yy.c token.cpp utilities.cpp -o eula.out) || \
	(echo -e "\n\e[1;31mError. \e[0mCompilation termined." && exit 1)
	make clean
	echo -e "\n\e[1;36mCompilation successfully.\e[0m"

clean:
	rm lex.yy.c parser.tab.* parser.output
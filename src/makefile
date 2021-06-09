LEXER   = flex 
PARSER  = bison
POPT    = -vd
CXX     = g++
COPT    = -g

default:
	($(PARSER) $(POPT) parser.y && \
	$(LEXER) lex.l && \
	$(CXX) $(COPT) parser.tab.c lex.yy.c token.h token.cpp utilities.h utilities.cpp -o eula) || \
	(echo -e "\n\e[1;31mError. \e[0mCompilation termined." && exit 1)
	make clean
	echo -e "\n\e[1;36mCompilation successfully.\e[0m"

clean:
	rm lex.yy.c parser.tab.* parser.output
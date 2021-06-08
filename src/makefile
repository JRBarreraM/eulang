LEXER   = flex 
PARSER  = bison
POPT    = -vd
CXX     = g++
COPT    = -g

default:
	($(PARSER) $(POPT) parser.y && \
	$(LEXER) lex.l && \
	$(CXX) $(COPT) parser.tab.c lex.yy.c -o eula) || \
	(echo -e "\n\e[1;31mError. \e[0mCompilation termined." && exit 1)
	make clean
	echo -e "\n\e[1;36mCompilation successfully.\e[0m"

clean:
	rm *.c *.h
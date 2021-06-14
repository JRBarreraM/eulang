#include "utilities.hpp"

std::string t_names [] =
    {
        "SEMICOLON",
        "COMMA",
        "DOT",
        "DTWODOTS",
        "SOFORTH",
        "ASSIGN",
        "LET",
        "TINT",
        "TBOOL",
        "TFLOAT",
        "TCHAR",
        "TSTR",
        "TSTRUCT",
        "TUNION",
        "TLIST",
        "TILDE",
        "DEREF",
        "ROOF",
        "FUNC",
        "PROC",
        "IF",
        "ELIF",
        "ELSE",
        "FOR",
        "IN",
        "WHILE",
        "RETURN",
        "PRINT",
        "INPUT",
        "NEW",
        "VENGEANCE",
        "OCURLYBRACKET",
        "CCURLYBRACKET",
        "OBRACKET",
        "CBRACKET",
        "OPAR",
        "CPAR",
        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "MOD",
        "POW",
        "PLUSPLUS",
        "MINUSMINUS",
        "NOT",
        "OR",
        "AND",
        "EQUALS",
        "NEQUALS",
        "GREATER",
        "LESS",
        "GEQ",
        "LEQ",
        "NUMBER",
        "DECIMAL",
        "ID",
        "CHAR",
        "STRING",
        "TRUE",
        "FALSE"
    };

void show_queue(std::queue<std::string> gq)
{
    std::queue<std::string> g = gq;
    while (!g.empty()) {
        std::cout << g.front();
        g.pop();
    }
}
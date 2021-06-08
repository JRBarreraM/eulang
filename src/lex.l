%option noyywrap

%{
    #include <string>
    #include <queue>
    #include <iostream>
    #include <regex>
    #include "parser.tab.h"
    using namespace std;
/*
    enum yytokentype {
        NUMBER = 1,
        DECIMAL,
        ID,

        SEMICOLON,
        COMMA,
        DOT,
        DTWODOTS,
        SOFORTH,

        ASSIGN,

        LET,
        TINT,
        TBOOL,
        TFLOAT,
        TCHAR,
        TSTR,
        TSTRUCT,
        TUNION,
        TLIST,
        TILDE,
        DEREF,
        ROOF,

        TRUE,
        FALSE,
        
        FUNC,
        PROC,
        IF,
        ELIF,
        ELSE,
        FOR,
        FOREACH,
        IN,
        WHILE,
        RETURN,
        PRINT,
        INPUT,

        NEW,
        VENGEANCE,

        OCURLYBRACKET,
        CCURLYBRACKET,
        OBRACKET,
        CBRACKET,
        OPAR,
        CPAR,

        CHAR,
        STRING,

        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        POW,
        PLUSPLUS,
        MINUSMINUS,

        NOT,
        OR,
        AND,

        EQUALS,
        NEQUALS,
        GREATER,
        LESS,
        GEQ,
        LEQ
    };

    string tokens [] =
    {
        "NUMBER",
        "DECIMAL",
        "ID",
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
        "TRUE",
        "FALSE",
        "FUNC",
        "PROC",
        "IF",
        "ELIF",
        "ELSE",
        "FOR",
        "FOREACH",
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
        "CHAR",
        "STRING",
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
        "LEQ"
    };
*/
    regex extension("(.*)\\.eula");

    int yycolumn = 1;
    string temp;

    queue<string> detectedTokens;
    queue<string> errors;

    int countLines(char* text)
    {
        int count = 0;
        for (int i=0; i<strlen(text); i++)
        {
            char x = text[i];
            if(x == '\n')
            {
                count++;
            }
        }
        return count;
    }
%}

number  [0-9]+
letter  [a-zA-Z]

%%
(\/\/)(.*?)([\n\r])          { yylineno++; yycolumn = 0; /* ignorar comentarios */ }
\/\*[^(\$\})]*\*\/           { yylineno = yylineno + countLines(yytext); /* ignorar comentarios */ }
[ \t]                        { yycolumn++; /* ignorar espacios en blanco */ }

";"                          { return SEMICOLON; }
","                          { return COMMA; }
"."                          { return DOT; }
"::"                         { return DTWODOTS; }
"..."                        { return SOFORTH; }

"="                          { return ASSIGN; }

"let"                        { return LET; }
"char"                       { return TCHAR; }
"int"                        { return TINT; }
"bool"                       { return TBOOL; }
"float"                      { return TFLOAT; }
"str"                        { return TSTR; }
"struct"                     { return TSTRUCT; }
"union"                      { return TUNION; }
"list"                       { return TLIST; }
"~"                          { return TILDE; }
"&"                          { return DEREF; }
"^"                          { return ROOF; }

"true"                       { return TRUE; }
"false"                      { return FALSE; }

"func"                       { return FUNC; }
"proc"                       { return PROC; }
"if"                         { return IF; }
"elif"                       { return ELIF; }
"else"                       { return ELSE; }
"for"                        { return FOR; }
"in"                         { return IN; }
"while"                      { return WHILE; }
"return"                     { return RETURN; }
"print"                      { return PRINT; }
"input"                      { return INPUT; }

"new"                        { return NEW; }
"vengeance"                  { return VENGEANCE; }

"{"                          { return OCURLYBRACKET; }
"}"                          { return CCURLYBRACKET; }
"["                          { return OBRACKET; }
"]"                          { return CBRACKET; }
"("                          { return OPAR; }
")"                          { return CPAR; }

\'.\'                        { yylval.ch = yytext[1]; return CHAR; }
\"(?:[^"\\\n]|\\.)*\"        { yylval.str = strdup(yytext); return STRING; }

"+"                          { return ADD; }
"-"                          { return SUB; }
"*"                          { return MUL; }
"/"                          { return DIV; }
"%"                          { return MOD; }
"**"                         { return POW; }
"++"                         { return PLUSPLUS; }
"--"                         { return MINUSMINUS; }

"!"                          { return NOT; }
"||"                         { return OR; }
"&&"                         { return AND; }

"=="                         { return EQUALS; }
"!="                         { return NEQUALS; }
">"                          { return GREATER; }
"<"                          { return LESS; }
">="                         { return GEQ; }
"<="                         { return LEQ; }

{number}                     { yylval.integer = atoi(yytext); return NUMBER; }
{number}\.{number}           { yylval.flot = stof(yytext); return DECIMAL; } 
{letter}({letter}|_|\-|{number})* { yylval.str = strdup(yytext); return ID; }

\n                           { yylineno++; yycolumn = 0; /* ignorar */ }
.                            { temp = strdup(yytext); 
                                errors.push("Error: Unexpected character " + temp + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n"); }
%%
/*
void show_queue(queue<string> gq)
{
    queue<string> g = gq;
    while (!g.empty()) {
        cout << g.front();
        g.pop();
    }
}
int main(int argc, char **argv)
{
    if(argc < 2) 
    {
        cout << "No file given" << endl;
        return -1;
    }

    if(!regex_match(argv[1], extension))
    {
        cout << "File extension doesn't match." << endl;
        return -1;
    }

    FILE *m_file = fopen(argv[1], "r");
    
    if (!m_file) 
    {
        cout << "Can't open the file!" << endl;
        return -1;
    }
    yyin = m_file;

    int tok;

    while(tok = yylex()) 
    {
        if(tok == NUMBER || tok == DECIMAL || tok == ID || tok == CHAR || tok == STRING) 
            detectedTokens.push(tokens[tok - 1] + " = " + yylval + "\n");
        else 
            detectedTokens.push(tokens[tok - 1] + "\n");
        yycolumn += strlen(yytext);
    }

    fclose(m_file);

    if(errors.empty())
        show_queue(detectedTokens);
    else
        show_queue(errors);
}
*/
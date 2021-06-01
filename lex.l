/* recognize tokens for the calculator and print them out */
%option noyywrap

%{
    #include <string>
    #include <queue>
    #include <iostream>
    #include <regex>
    using namespace std;

    enum yytokentype {
        NUMBER = 1,
        ID,

        SEMICOLON,
        COMMA,
        DOT,
        DTWODOTS,
        SOFORTH,

        ASSIGN,

        LET,
        INT,
        BOOL,
        FLOAT,
        CHAR,
        STR,
        STRUCT,
        UNION,
        LIST,
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

        OCURLYBRACKET,
        CCURLYBRACKET,
        OBRACKET,
        CBRACKET,
        OPAR,
        CPAR,

        QUOTE,
        DQUOTE,

        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        EXP,

        NOT,
        OR,
        AND,

        EQUALS,
        NEQUALS,
        GREATER,
        LESS,
        GEQ,
        LEQ,

        EOL
    };

    string tokens [] =
    {
        "NUMBER",
        "ID",
        "SEMICOLON",
        "COMMA",
        "DOT",
        "DTWODOTS",
        "SOFORTH",
        "ASSIGN",
        "LET",
        "INT",
        "BOOL",
        "FLOAT",
        "CHAR",
        "STR",
        "STRUCT",
        "UNION",
        "LIST",
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
        "OCURLYBRACKET",
        "CCURLYBRACKET",
        "OBRACKET",
        "CBRACKET",
        "OPAR",
        "CPAR",
        "QUOTE",
        "DQUOTE",
        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "MOD",
        "EXP",
        "NOT",
        "OR",
        "AND",
        "EQUALS",
        "NEQUALS",
        "GREATER",
        "LESS",
        "GEQ",
        "LEQ",
        "EOL"
    };

    regex extension("(.*)\\.eula");

    string yylval;
    int row = 1;
    int col = 1;
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
[ \t]                        { col++; /* ignorar espacios en blanco */ }
\/\/.*\n                     { row++; col = 0; /* ignorar comentarios */ }
\/\\*((.|\n)*?)\\*\/         { row = row + countLines(yytext); /* ignorar comentarios */ }

";"                          { return SEMICOLON; }
","                          { return COMMA; }
"."                          { return DOT; }
"::"                         { return DTWODOTS; }
"..."                        { return SOFORTH; }

"="                          { return ASSIGN; }

"let"                        { return LET; }
"int"                        { return INT; }
"bool"                       { return BOOL; }
"float"                      { return FLOAT; }
"str"                        { return STR; }
"struct"                     { return STRUCT; }
"union"                      { return UNION; }
"list"                       { return LIST; }
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
"foreach"                    { return FOREACH; }
"in"                         { return IN; }
"while"                      { return WHILE; }
"return"                     { return RETURN; }
"print"                      { return PRINT; }
"input"                      { return INPUT; }

"{"                          { return OCURLYBRACKET; }
"}"                          { return CCURLYBRACKET; }
"["                          { return OBRACKET; }
"]"                          { return CBRACKET; }
"("                          { return OPAR; }
")"                          { return CPAR; }

\'.\'                        { yylval = strdup(yytext); return QUOTE; }
\"(?:[^"\\\n]|\\.)*\"        { yylval = strdup(yytext); return DQUOTE; }

"+"                          { return ADD; }
"-"                          { return SUB; }
"*"                          { return MUL; }
"/"                          { return DIV; }
"%"                          { return MOD; }
"**"                         { return EXP; }

"!"                          { return NOT; }
"||"                         { return OR; }
"&&"                         { return AND; }

"=="                         { return EQUALS; }
"!="                         { return NEQUALS; }
">"                          { return GREATER; }
"<"                          { return LESS; }
">="                         { return GEQ; }
"<="                         { return LEQ; }

{number}                     { yylval = strdup(yytext); return NUMBER; }
{letter}({letter}|{number})* { yylval = strdup(yytext); return ID; }

\n                           { row++; col = 0; return EOL; }
.                            { temp = strdup(yytext); 
                                errors.push("Error: Unexpected character " + temp + " at line " + to_string(row) + ", column " + to_string(col) + "\n"); }
%%

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
        if(tok == NUMBER || tok == ID || tok == QUOTE || tok == DQUOTE) 
            detectedTokens.push(tokens[tok - 1] + " = " + yylval + "\n");
        else 
            detectedTokens.push(tokens[tok - 1] + "\n");
        col += strlen(yytext);
    }

    fclose(m_file);

    if(errors.empty())
        show_queue(detectedTokens);
    else
        show_queue(errors);
}

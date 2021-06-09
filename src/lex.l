%option noyywrap
%option yylineno

%{
    #include <string>
    #include <queue>
    #include <iostream>
    #include <regex>
    #include "parser.tab.h"
    using namespace std;

    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng; \
        yylval.str = strdup(yytext);

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
(\/\/)(.*?)([\n\r])          { yycolumn = 1; /* ignorar comentarios */ }
\/\*[^(\$\})]*\*\/           { /* ignorar comentarios */ }
[ \t]                        { /* ignorar espacios en blanco */ }

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
\"(?:[^"\\\n]|\\.)*\"        { return STRING; }

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
{letter}({letter}|_|\-|{number})* { return ID; }

\n                           { yycolumn = 1; /* ignorar */ }
.                            { temp = strdup(yytext); 
                                errors.push("Error: Unexpected character " + temp + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n"); }
%%
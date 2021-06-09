%{
    #include <string>
    #include <queue>
    #include <vector>
    #include <iostream>
    #include <regex>
    #include "token.h"
    using namespace std;

    extern int yylex(void);
    extern int yylineno;
    extern int yycolumn;
    extern char *yytext;

    // queues for tokens and errors
    extern queue<string> errors;
    vector<Token*> detectedTokens;
    
    void yyerror(const char *s);
    
    regex extension("(.*)\\.eula");
%}

%union 
{	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;
}

%define parse.lac full
%define parse.error verbose

%locations
%start Start

/* Declaraciones de BISON */
%token SEMICOLON 1
%token COMMA 2
%token DOT 3
%token DTWODOTS 4
%token SOFORTH 5
%token ASSIGN 6
/*  */
%token LET 7
%token TINT 8
%token TBOOL 9
%token TFLOAT 10
%token TCHAR 11
%token TSTR 12
%token TSTRUCT 13
%token TUNION 14
%token TLIST 15
%token TILDE 16
%token DEREF 17
%token ROOF 18
/*  */
%token FUNC 19
%token PROC 20
%token IF 21
%token ELIF 22
%token ELSE 23
/*  */
%token FOR 24
%token IN 25
%token WHILE 26
%token RETURN 27
/*  */
%token PRINT 28
%token INPUT 29
/*  */
%token NEW 30
%token VENGEANCE 31
/*  */
%token OCURLYBRACKET 32
%token CCURLYBRACKET 33
%token OBRACKET 34
%token CBRACKET 35
%token OPAR 36
%token CPAR 37
/*  */
%token ADD 38
%token SUB 39
%token MUL 40
%token DIV 41
%token MOD 42
%token POW 43
%token PLUSPLUS 44
%token MINUSMINUS 45
%token NOT 46
%token OR 47
%token AND 48
%token EQUALS 49
%token NEQUALS 50
%token GREATER 51
%token LESS 52
%token GEQ 53
%token LEQ 54

%token <integer>  NUMBER 55
%token <flot>     DECIMAL 56
%token <id>       ID 57
%token <chr>      CHAR 58
%token <str>      STRING 59
%token <boolean>  TRUE 60
%token <boolean>  FALSE 61

// Precedence

%left       EQUALS NEQUALS
%left       OR AND 
%nonassoc   LESS LEQ GREATER GEQ
%right      NOT
%nonassoc   ASSIGN SOFORTH
%left       ADD SUB
%left       MUL DIV MOD
%right      POW
%left       OBRACKET CBRACKET
%right      DEREF
%left       DOT
%nonassoc   ID
%left       OPAR

%expect 1
/* Gramatica del lenguaje */
%%

/* Estructura del programa */
Start:          Inst                  { ; }
                | /* lambda */        { ; }
;
Inst:           InstAux               { ; }
                | Inst InstAux        { ; }
;
InstAux:        Action                { ; }
	            | Definition          { ; }
;
Action:         VarInst SEMICOLON               { ; }
                | CallFunc SEMICOLON            { ; }
                | Selection                     { ; }
                | While                         { ; }
                | For                           { ; }
                | VENGEANCE LValue SEMICOLON    { ; }
                | PRINT OPAR Exp CPAR SEMICOLON { ; }
                | ID PLUSPLUS SEMICOLON         { ; }
                | ID MINUSMINUS SEMICOLON       { ; }
;
Definition:     DefUnion          { ; }
                | DefStruct       { ; }
                | DefProc         { ; }
                | DefFunc         { ; }
;

/* Tipos */
Type:           TypeAux                                 { ; }
                | TypeAux OBRACKET Exp CBRACKET         { ; }
                | TypeAux TILDE  	                    { ; }
;

TypeAux:        TypePrimitive                      { ; }
                | TypeComposite                    { ; }
;

TypePrimitive:  TBOOL                              { ; }
                | TCHAR                            { ; }
                | TINT                             { ; }
                | TFLOAT                           { ; }
;
                
TypeComposite:  TSTR                               { ; }
                | TLIST                            { ; }
;

/* Definiciones */
VarInst:        VarDef                    { ; }
	            | Assign                  { ; }
;
VarDef:         LET Type ID OptAssign     { ; }
;
OptAssign:      ASSIGN RValue             { ; }
	            | /* lambda */            { ; }
;
Assign:         LValue ASSIGN RValue      { ; }
;
RValue:         Exp                                             { ; }
                | Array                                         { ; }
                | NEW TypeAux                                   { ; }
                | INPUT OPAR OptExp CPAR DTWODOTS TypeAux       { ; }
;

OptExp:         Exp             { ; }
                | /* Lambda */  { ; }
;
/* Expresiones */
Exp:            NUMBER               { ; }
                | DECIMAL            { ; }
                | LValue             { ; }
                | TRUE               { ; }
                | FALSE              { ; }
                | CHAR               { ; }
                | STRING             { ; }
                | CallFunc           { ; }
                | Exp ADD Exp        { ; }
                | Exp SUB Exp        { ; }
                | Exp MUL Exp        { ; }
                | Exp DIV Exp        { ; }
                | Exp MOD Exp        { ; }
                | SUB Exp            { ; }
                | Exp POW Exp        { ; }
                | OPAR Exp CPAR      { ; }
                | Exp AND Exp        { ; }
                | Exp OR Exp         { ; }
                | Exp EQUALS Exp     { ; }
                | Exp NEQUALS Exp    { ; }
                | Exp GREATER Exp    { ; }
                | Exp LESS Exp       { ; }
                | Exp GEQ Exp        { ; }
                | Exp LEQ Exp        { ; }
                | NOT Exp            { ; }
                | Exp OBRACKET Exp SOFORTH Exp CBRACKET  { ; }
                | LValue DOT ID OPAR OptExp CPAR            { ; }
;

/* Left Values */
LValue:         ID                             { ; }
                | LValue OBRACKET Exp CBRACKET { ; }
                | LValue DOT ID                { ; }
                | DEREF LValue                 { ; }
;

/* Funciones */
DefFunc:        FUNC ID OPAR FuncPar CPAR DTWODOTS TypePrimitive OCURLYBRACKET FuncBody CCURLYBRACKET { ; }
;

FuncBody:       Start RETURN Exp SEMICOLON     { ; }
;

FuncPar:        ParList                 { ; }
                | /* lambda */          { ; }
;

ParList:        ParList COMMA Type OptRoof ID   { ; }
                | Type OptRoof ID               { ; }
;

OptRoof:        ROOF                    { ; }
                | /* Lambda */          { ; }
;

CallFunc:       ID OPAR ArgElems CPAR { ; }
;

ArgElems:   ArgList                             { ; }
	        | /* lambda */                      { ; }
;

ArgList:    RValue                              { ; }
            | ArgList COMMA RValue              { ; }
;

/* Procedimientos */
DefProc:        PROC ID OPAR FuncPar CPAR OCURLYBRACKET Inst CCURLYBRACKET { ; }
;

/* Arreglos */
Array:          OBRACKET ArrExp CBRACKET   { ; }
;

ArrExp:         ArrElems                { ; }
                | NUMBER SOFORTH NUMBER { ; }
                | NUMBER SOFORTH ID     { ; }
                | ID SOFORTH NUMBER     { ; }
                | ID SOFORTH ID         { ; }
;

ArrElems:       ArrElems COMMA RValue    { ; }
		        | RValue                 { ; }
;

/* Union */
DefUnion:       TUNION ID OCURLYBRACKET UnionBody CCURLYBRACKET   { ; }
;

UnionBody:      LET Type ID SEMICOLON           { ; }
		|       UnionBody LET Type ID SEMICOLON     { ; }
;

/* Struct */
DefStruct:      TSTRUCT ID OCURLYBRACKET StructBody CCURLYBRACKET { ; }
;

StructBody:     LET Type ID OptAssign SEMICOLON             { ; }
		|       StructBody LET Type ID OptAssign SEMICOLON  { ; }
;

/* Condicionales */
Selection:    IF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif OptElse { ; }
;
OptElif:        Elif OptElif            { ; }
		|       /* lambda */            { ; }
;
Elif:           ELIF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET     { ; }
;
OptElse:        ELSE OCURLYBRACKET Inst CCURLYBRACKET   { ; }
		|       /* lambda */                            { ; }
;

/* For Loop */
For:            FOR ID IN Range OCURLYBRACKET Inst CCURLYBRACKET    { ; }
;

Range:          Exp         { ; }
                | Array     { ; }
;

/* While Loop */
While:          WHILE OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET    { ; }
;
%%

void yyerror(const char *s)
{
  fprintf(stderr, "Error: %s at line %d, column %d\n", s, yylineno, yycolumn);
}

int main(int argc, char **argv)
{
    // Look for input line
    if(argc != 2) 
    {
        cout << "No input file" << endl;
        return -1;
    }

    if(!regex_match(argv[1], extension))
    {
        cout << "File extension doesn't match." << endl;
        return -1;
    }

    // open file to extract the tokens
    extern FILE *yyin;
    yyin = fopen(argv[1], "r");

    // check if file was succesfully opened.
    if (!yyin) 
    {
        cout << "There was an error opening the file" << endl;
        return -1;
    }

    // apply lexing
    int tok;
    while(tok = yylex())
    {
        switch(tok)
        {
            case ID:
                detectedTokens.push_back(new TIdentifier(yylval.str, tok, yylineno, yylloc.first_column));
                break;
            case NUMBER:
                detectedTokens.push_back(new TInteger(yylval.integer, tok, yylineno, yylloc.first_column));
                break;
            case DECIMAL:
                detectedTokens.push_back(new TFloat(yylval.flot, tok, yylineno, yylloc.first_column));
                break;
            case STRING:
                detectedTokens.push_back(new TIdentifier(yylval.str, tok, yylineno, yylloc.first_column));
                break;
            case CHAR:
                detectedTokens.push_back(new TChar(yylval.ch, tok, yylineno, yylloc.first_column));
                break;
            default:
                detectedTokens.push_back(new Token(tok, yylineno, yylloc.first_column));
                break;
        }
    };

    // Print tokens
    print_tokens(detectedTokens);

    fclose(yyin);
    yyin = fopen(argv[1], "r");

    // if there are no errors, apply parsing
    if (errors.empty()) {
        
        // reset lines and columns
        yylineno = 1;
        yycolumn = 1;

        // start parsing
        yyparse();
    } else {
        show_queue(errors);
    }
    return 0;
}
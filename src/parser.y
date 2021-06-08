%{
    #include <string>
    #include <queue>
    #include <iostream>
    using namespace std;

    extern int yylex(void);
    extern int yylineno;
    extern int yycolumn;
    extern char *yytext;

    // queues for tokens and errors
    extern queue<string> errors;
    extern queue<string> detectedTokens;
    
    void show_queue(queue<string> gq);
    void yyerror(char *s);

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

%locations
%start Start

/* Declaraciones de BISON */
%token SEMICOLON COMMA DOT DTWODOTS SOFORTH ASSIGN
%token LET TINT TBOOL TFLOAT TCHAR TSTR TSTRUCT TUNION TLIST TILDE DEREF ROOF
%token FUNC PROC
%token IF ELIF ELSE
%token FOR IN WHILE RETURN
%token PRINT INPUT
%token NEW VENGEANCE
%token OCURLYBRACKET CCURLYBRACKET OBRACKET CBRACKET OPAR CPAR
%token ADD SUB MUL DIV MOD POW
%token PLUSPLUS MINUSMINUS
%token NOT OR AND
%token EQUALS NEQUALS GREATER LESS GEQ LEQ

%token <integer>  NUMBER
%token <flot>     DECIMAL
%token <id>       ID
%token <chr>      CHAR
%token <str>      STRING
%token <boolean>  TRUE FALSE

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

void show_queue(queue<string> gq)
{
    queue<string> g = gq;
    while (!g.empty()) {
        cout << g.front();
        g.pop();
    }
}

void yyerror(char *s)
{
  fprintf(stderr, "error: %s (%d,%d)\n", s, yylineno, yycolumn);
}

int main(int argc, char **argv)
{
    // Look for input line
    if(argc != 2) 
    {
        cout << "No input file" << endl;
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
    while(tok = yylex()){};

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
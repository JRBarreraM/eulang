%{
    #include <string>
    #include <queue>
    #include <vector>
    #include <iostream>
    #include <regex>
    #include "token.hpp"
    #include "ast.hpp"
    #include "symbol_table.hpp"
    using namespace std;

    extern int yylex(void);
    extern int yylineno;
    extern int yycolumn;
    extern char *yytext;

    // queues for tokens and errors
    extern queue<string> errors;
    queue<string> st_errors;
    vector<Token*> detectedTokens;
    
    void yyerror(const char *s);
    void redeclared_variable_error(string id);
    void check_id_exists(string id);
    
    regex extension("(.*)\\.eula");

    NodeStart* root_ast;
    sym_table st;
%}

%union 
{	
  int   integer;
  float flot;
  bool  boolean;
  char* str;
  char  ch;
  node* ast;
  NodeStart* ns;
}

%define parse.lac full
%define parse.error simple

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
%token <str> TINT 8
%token <str> TBOOL 9
%token <str> TFLOAT 10
%token <str> TCHAR 11
%token <str> TSTR 12
%token TSTRUCT 13
%token TUNION 14
%token <str> TLIST 15
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
%token <str> ADD 38
%token <str> SUB 39
%token <str> MUL 40
%token <str> DIV 41
%token <str> MOD 42
%token <str> POW 43
%token PLUSPLUS 44
%token MINUSMINUS 45
%token <str> NOT 46
%token <str> OR 47
%token <str> AND 48
%token <str> EQUALS 49
%token <str> NEQUALS 50
%token <str> GREATER 51
%token <str> LESS 52
%token <str> GEQ 53
%token <str> LEQ 54
%token <str> BREAK 55
%token <str> CONTINUE 56

%token <integer>  NUMBER 57
%token <flot>     DECIMAL 58
%token <str>      ID 59
%token <ch>       CHAR 60
%token <str>      STRING 61
%token <boolean>  TRUE 62
%token <boolean>  FALSE 63

%type <ast>     Inst InstAux Action FuncBody 
%type <ast>     Definition Type TypeAux TypePrimitive TypeComposite
%type <ast>     VarInst VarDef OptAssign Assign RValue InputType OptExp Exp
%type <ast>     LValue DefFunc FuncPar ParList CallFunc ArgElems ArgList
%type <ast>     DefProc Array ArrExp ArrElems DefUnion UnionBody DefStruct StructBody
%type <ast>     Selection OptElif OptElse For Range While
%type <boolean> OptRoof
%type <ns>      Start
%type <str>     IdFor Func Proc

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
Start:          Inst                  { $$ = new NodeStart($1); root_ast = $$;}
                | /* lambda */        { $$ = NULL; }
;
Inst:           InstAux               { $$ = new NodeInst($1); }
                | Inst InstAux        { $$ = new NodeInst($2, $1); }
;
InstAux:        Action                { $$ = $1; }
	            | Definition          { $$ = $1; }
;
Action:         VarInst SEMICOLON               { $$ = $1; }
                | CallFunc SEMICOLON            { $$ = $1; }
                | Selection                     { $$ = $1; }
                | While                         { $$ = $1; }
                | For                           { $$ = $1; }
                | VENGEANCE LValue SEMICOLON    { $$ = new NodeVengeance($2); }
                | PRINT OPAR Exp CPAR SEMICOLON { $$ = new NodePrint($3); }
                | CONTINUE SEMICOLON            { $$ = new NodeContinue(); }
                | BREAK SEMICOLON               { $$ = new NodeBreak(); }
                | ID PLUSPLUS SEMICOLON         { check_id_exists($1);
                                                  $$ = new NodeAssign(new NodeIDLValue($1), new NodeBinaryOperator(new NodeIDLValue($1), "+", new NodeINT(1) )); }
                | ID MINUSMINUS SEMICOLON       { check_id_exists($1);
                                                   $$ = new NodeAssign(new NodeIDLValue($1), new NodeBinaryOperator(new NodeIDLValue($1), "-", new NodeINT(1) )); }
                | RETURN Exp SEMICOLON          { $$ = new NodeReturn($2); }
; 
FuncBody:       Inst                { $$ = $1; }
	            | /* lambda */      { $$ = NULL; }
;
Definition:     DefUnion          { $$ = $1; }
                | DefStruct       { $$ = $1; }
                | DefProc         { $$ = $1; }
                | DefFunc         { $$ = $1; }
;

/* Tipos */
Type:           TypeAux                                 { $$ = $1; }
                | TLIST OBRACKET Type CBRACKET          { $$ = new NodeTypeList($3); }
                | TypeAux OBRACKET Exp CBRACKET         { $$ = new NodeTypeArrayDef($1, $3); }
                | TypeAux TILDE  	                    { $$ = new NodeTypePointerDef($1); }
;

TypeAux:        TypePrimitive                      { $$ = $1; }
                | TypeComposite                    { $$ = $1; }
;

TypePrimitive:  TBOOL                              { $$ = new NodeTypePrimitiveDef($1); }
                | TCHAR                            { $$ = new NodeTypePrimitiveDef($1); }
                | TINT                             { $$ = new NodeTypePrimitiveDef($1); }
                | TFLOAT                           { $$ = new NodeTypePrimitiveDef($1); }
;
                
TypeComposite:  TSTR                               { $$ = new NodeTypePrimitiveDef($1); }
                | ID                               { $$ = new NodeTypePrimitiveDef($1); }
;

/* Definiciones */
VarInst:        VarDef                    { $$ = $1; }
	            | Assign                  { $$ = $1; }
;
VarDef:         LET Type ID OptAssign     { $$ = new NodeVarDef($2, $3, $4);
                                            if(!st.insert($3)) redeclared_variable_error($3);}
;
OptAssign:      ASSIGN RValue             { $$ = $2; }
	            | /* lambda */            { $$ = NULL; }
;
Assign:         LValue ASSIGN RValue      { $$ = new NodeAssign($1, $3); }
;
RValue:         Exp                                             { $$ = $1; }
                | Array                                         { $$ = $1; }
                | NEW Type                                      { $$ = new NodeNew($2); }
                | INPUT OPAR OptExp CPAR DTWODOTS InputType     { $$ = new NodeInput($6, $3); }
;
InputType:      TypePrimitive   { $$ = $1; }
                | TSTR          { $$ = new NodeTypePrimitiveDef($1); }
;
OptExp:         Exp                  { $$ = $1; }
                | /* Lambda */       { $$ = NULL; }
;
/* Expresiones */
Exp:            NUMBER               { $$ = new NodeINT($1); }
                | DECIMAL            { $$ = new NodeFLOAT($1); }
                | LValue             { $$ = $1; }
                | TRUE               { $$ = new NodeBOOL(true); }
                | FALSE              { $$ = new NodeBOOL(false); }
                | CHAR               { $$ = new NodeCHAR($1); }
                | STRING             { $$ = new NodeSTRING($1); }
                | CallFunc           { $$ = $1; }
                | Exp ADD Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
                | Exp SUB Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
                | Exp MUL Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
                | Exp DIV Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
                | Exp MOD Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
                | SUB Exp            { $$ = new NodeUnaryOperator($1, $2); }
                | Exp POW Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
                | OPAR Exp CPAR      { $$ = $2; }
                | Exp AND Exp        { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp OR Exp         { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp EQUALS Exp     { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp NEQUALS Exp    { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp GREATER Exp    { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp LESS Exp       { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp GEQ Exp        { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | Exp LEQ Exp        { $$ = new NodeBinaryOperator($1, $2, $3);; }
                | NOT Exp            { $$ = new NodeUnaryOperator($1, $2); }
                | Exp OBRACKET Exp SOFORTH Exp CBRACKET  { $$ = new NodeSubArray($1, $3, $5); }
;

/* Left Values */
LValue:         ID                             { check_id_exists($1);
                                                $$ = new NodeIDLValue($1); }
                | LValue OBRACKET Exp CBRACKET { $$ = new NodeArrayLValue($1, $3); }
                | LValue DOT ID                { check_id_exists($3);
                                                  $$ = new NodeLValueDot($1, $3); }
                | DEREF LValue                 { $$ = new NodePointerLValue($2); }
;

/* Funciones */
DefFunc:        Func OPAR FuncPar CPAR DTWODOTS TypePrimitive OCURLYBRACKET FuncBody CCURLYBRACKET { $$ = new NodeFuncDef($1, $3, $8, $6);
                                                                                                        st.exit_scope(); }
;
Func:           FUNC ID   { if(!st.insert($2)) redeclared_variable_error($2);
                            st.new_scope();
                            $$ = $2; }
;

FuncPar:        ParList                 { $$ = $1; }
                | /* lambda */          { $$ = NULL; }
;

ParList:        ParList COMMA Type OptRoof ID   { $$ = new NodeRoutineArgsDef($3, $4, $5, $1); 
                                                  if(!st.insert($5)) redeclared_variable_error($5);}
                | Type OptRoof ID               { $$ = new NodeRoutineArgsDef($1, $2, $3); 
                                                  if(!st.insert($3)) redeclared_variable_error($3);}
;

OptRoof:        ROOF                    { $$ = true; }
                | /* Lambda */          { $$ = false; }
;

CallFunc:       ID OPAR ArgElems CPAR { check_id_exists($1);
                                        $$ = new NodeCallFunction($1, $3); }
;

ArgElems:   ArgList                             { $$ = $1; }
	        | /* lambda */                      { $$ = NULL; }
;

ArgList:    RValue                              { $$ = new NodeCallFunctionArgs($1); }
            | ArgList COMMA RValue              { $$ = new NodeCallFunctionArgs($3, $1); }
;

/* Procedimientos */
DefProc:        Proc OPAR FuncPar CPAR OCURLYBRACKET FuncBody CCURLYBRACKET { $$ = new NodeProcDef($1, $3, $6);
                                                                                 st.exit_scope(); }
;
Proc:           PROC ID   { if(!st.insert($2)) redeclared_variable_error($2);
                            st.new_scope();
                            $$ = $2; }
;

/* Arreglos */
Array:          OBRACKET ArrExp CBRACKET   { $$ = new NodeArray($2); }
;

ArrExp:         ArrElems                { $$ = $1; }
                | Exp SOFORTH Exp       { $$ = new NodeArrayRange($1, $3); }
;

ArrElems:       ArrElems COMMA RValue    { $$ = new NodeArrayElems($3, $1); }
		        | RValue                 { $$ = new NodeArrayElems($1); }
;

/* Union */
DefUnion:       Union ID OCURLYBRACKET UnionBody CCURLYBRACKET   { $$ = new NodeUnionDef($2, $4);
                                                                    st.exit_scope();
                                                                    if(!st.insert($2)) redeclared_variable_error($2); }
;

Union:          TUNION      { st.new_scope(); }
;

UnionBody:      LET Type ID SEMICOLON                 { $$ = new NodeUnionFields($3, $2); 
                                                        if(!st.insert($3)) redeclared_variable_error($3); }
		        | UnionBody LET Type ID SEMICOLON     { $$ = new NodeUnionFields($4, $3, $1); 
                                                        if(!st.insert($4)) redeclared_variable_error($4); }
;

/* Struct */
DefStruct:      Struct ID OCURLYBRACKET StructBody CCURLYBRACKET { $$ = new NodeStructDef($2, $4); 
                                                                    st.exit_scope();
                                                                    if(!st.insert($2)) redeclared_variable_error($2); }
;
Struct:         TSTRUCT     { st.new_scope(); }
;

StructBody:     VarDef SEMICOLON                { $$ = new NodeStructFields($1); }
		        | StructBody VarDef SEMICOLON   { $$ = new NodeStructFields($2, $1); }
;

/* Condicionales */
Selection:      If OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif OptElse { $$ = new NodeConditional($3, $6, $8, $9); st.exit_scope(); }
;
If:             IF      { st.new_scope(); }
;

OptElif:        Elif OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif     { $$ = new NodeElif($3, $6, $8); st.exit_scope(); }
                | /* lambda */                                                  { $$ = NULL; }
;
Elif:           ELIF    { st.new_scope(); }
;

OptElse:        Else OCURLYBRACKET Inst CCURLYBRACKET   { $$ = new NodeElse($3); st.exit_scope(); }
		        |       /* lambda */                    { $$ = NULL; }
;
Else:           ELSE    { st.new_scope(); }
;

/* For Loop */
For:            LoopFor OPAR IdFor IN Range CPAR OCURLYBRACKET Inst CCURLYBRACKET    { $$ = new NodeFor($3, $5, $8); st.exit_scope(); }
;
LoopFor:        FOR     { st.new_scope(); }
;
IdFor:          ID      { $$ = $1; 
                          if(!st.insert($1)) redeclared_variable_error($1);}
;

Range:          Exp         { $$ = $1; }
                | Array     { $$ = $1; }
;

/* While Loop */
While:          LoopWhile OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET    { $$ = new NodeWhile($3, $6); st.exit_scope(); }
;
LoopWhile:      WHILE   { st.new_scope(); }
;
%%

void yyerror(const char *s)
{
    fprintf(stderr, "Error: %s, unexpected token %s at line %d, column %d\n", s, yytext,yylineno, yycolumn);
}

void redeclared_variable_error(string id)
{
    string e = "Error: redeclared variable " + id + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    st_errors.push(e);
}

void check_id_exists(string id)
{
    if(st.lookup(id) == NULL)
    {
        string e = "Error: " + id + " not declared. At line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
        st_errors.push(e);
    }
}

int main(int argc, char **argv)
{
    bool lex = false;
    bool ast = false;
    bool stp = false;
    int flags = 0;
    for(int i = 1; i < argc -1; ++i) {
        if(string(argv[i]) == "-lex") {
            lex = true;
            flags++;
        }

        else if(string(argv[i]) == "-ast") {
            ast = true;
            flags++;
        }
        else if(string(argv[i]) == "-st") {
            stp = true;
            flags++;
        }

        else{
            cout << "Unexpected argument: " << argv[i] <<endl;
            return 0;
        }
    }

    // Look for input line
    if(argc < 2 + flags)
    {
        cout << "No input file" << endl;
        return -1;
    }

    if(!regex_match(argv[argc-1], extension))
    {
        cout << "File extension doesn't match." << endl;
        return -1;
    }

    // open file to extract the tokens
    extern FILE *yyin;
    yyin = fopen(argv[argc-1], "r");

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

    fclose(yyin);
    yyin = fopen(argv[argc-1], "r");

    // If error on lexer, show them
    if(!errors.empty()){
        show_queue(errors);
    }

    // Print tokens
    if (lex){
        print_tokens(detectedTokens);
    }
    
    // reset lines and columns
    yylineno = 1;
    yycolumn = 1;

    // start parsing
    yyparse();

    if(ast) root_ast->print(0);
    if(stp) st.print();

    if(!st_errors.empty()) show_queue(st_errors);

    return 0;
}
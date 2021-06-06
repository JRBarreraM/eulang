/* Infix notation calculator--calc */

%{
#include <math.h>
%}

/* BISON Declarations */
%token NUMBER DECIMAL ID
%token SEMICOLON COMMA DOT DTWODOTS SOFORTH ASSIGN
%token LET TINT TBOOL TFLOAT TCHAR TSTR TSTRUCT TUNION TLIST TILDE DEREF ROOF
%token TRUE FALSE
%token FUNC PROC
%token IF ELIF ELSE
%token FOR FOREACH IN WHILE RETURN
%token PRINT INPUT
%token NEW VENGEANCE
%token OCURLYBRACKET CCURLYBRACKET OBRACKET CBRACKET OPAR CPAR
%token CHAR STRING
%token ADD SUB MUL DIV MOD POW
%token NOT OR AND
%token EQUALS NEQUALS GREATER LESS GEQ LEQ

%left AND OR
%right NOT
%nonassoc EQUALS NEQUALS GREATER LESS GEQ LEQ
%right PRINT INPUT
%right LET
%left SEMICOLON
%left COMMA
%nonassoc ASSIGN SOFORTH
%left ADD SUB
%left MUL DIV MOD
%left POW

/* Grammar follows */
%%

/* Program Structure */
Start:  Inst                  { ;  }
        | /* lambda */        { ; }
;
Inst:   InstAux               { ; }
        | Inst InstAux        { ; }
;
InstAux:Action                { ; }
		| Definition          { ; }
;
Action: VarAction SEMICOLON   { ; }
		| CallFunc SEMICOLON  { ; }
		| Conditional         { ; }
		| While               { ; }
		| For                 { ; }
;
Definition: DefUnion          { ; }
			| DefStruct       { ; }
			| DefProc         { ; }
;



/* Types */
Type:   Type OBRACKET ExpNullable CBRACKET { ; }
	    | Type TILDE  	                   { ; }
		| TBOOL                            { ; }
        | TCHAR                            { ; }
        | TINT                             { ; }
        | TFLOAT                           { ; }
        | TSTRING                          { ; }
        | TLIST                            { ; }
;

ExpNullable: /*lambda*/
        | Exp
;

/* Definitions */
VarInst:    VarDef                    { ; }
			| Assign                  { ; }
;
VarDef:     LET Type ID OptAssign     { ; }
;
OptAssign:  /* lambda */              { ; }
			| ASSIGN RValue           { ; }
;
Assign:     LValue ASSIGN RValue      { ; }
;
RValue:     Exp                       { ; }
            | Array                   { ; }
            | STRING                  { ; }
            | NEW Type                { ; }
            | VENGEANCE LValue        { ; }
;

/* Expressions */
Exp:      NUMBER             { ;           }
        | DECIMAL            { ;           }
        | LValue             { ;           }
        | TRUE               { ;           }
        | FALSE              { ;           }
        | CHAR               { ;           }
        | CallFunc           { ;           }
        | Exp ADD Exp        { ;           }
        | Exp SUB Exp        { ;           }
        | Exp MULT Exp       { ;           }
        | Exp DIV Exp        { ;           }
        | SUB Exp            { ;           }
        | Exp POW Exp        { ;           }
        | OPAR Exp CPAR      { ;           }
        | Exp AND Exp        { ;           }
        | Exp OR Exp         { ;           }
        | Exp EQUALS Exp     { ;           }
        | Exp NEQUALS Exp    { ;           }
        | Exp GREATER Exp    { ;           }
        | Exp LESS Exp       { ;           }
        | Exp GEQ Exp        { ;           }
        | Exp LEQ Exp        { ;           }
        | Exp LEQ Exp        { ;           }
        | NOT Exp            { ;           }
;

/* Left Values */
LValue:   LValue OBRACKET Exp CBRACKET { ;        }
        | ID                           { ;        }
        | LValue DOT ID                { ;        }
        | DEREF LValue                 { ;        }
;

/* Functions */
CallFunc: ID OPAR ArgE CPAR { ; }
;
ArgE:     /* lambda */      { ; } 
	    | ArrElems RValue   { ; }
;
ArrElems: /* lambda */                        { ; }
		| ArrElems RValue COMMA               { ; }
;

/* Arrays*/
Array:  OBRACKET ArrExp CBRACKET   { ; }
;
ArrExp: /* lambda */                        { ; }
		| ArrElems RValue                     { ; }
;
ArrElems: /* lambda */                        { ; }
		| ArrElems RValue COMMA               { ; }
;

/* Union */
UnionDef:   UNION ID OCURLYBRACKET UnionBody CCURLYBRACKET   { ; }
; 
UnionBody:  LET Type ID SEMICOLON         { ; }
			| UnionBody Type ID SEMICOLON { ; }
;

/* Struct */
StructDef:  TSTRUCT ID OCURLYBRACKET RegBody CCURLYBRACKET { ; }
;
StructBody: Type ID OptAssign SEMICOLON            { ; }
		    | RegBody Type ID OptAssign SEMICOLON  { ; }
;

/* Conditionals */
Conditional : IF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif OptElse { ; }
;
OptElif     : /* lambda */ { ; }
		    | Elif         { ; }
;
Elifs       : ELIF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET { ; }
			| Elifs ELIF OPAR Exp CPAR THEN Inst                  { ; }
;
OptElse     : /* lambda */                          { ; }
			| ELSE Inst                             { ; }
;
%%
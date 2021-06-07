%{
#include <math.h>
%}

/* Declaraciones de BISON */
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
Action:         VarAction SEMICOLON   { ; }
                | CallFunc SEMICOLON  { ; }
                | Conditional         { ; }
                | While               { ; }
                | For                 { ; }
;
Definition:     DefUnion          { ; }
                | DefStruct       { ; }
                | DefProc         { ; }
                | DefFunc         { ; }
;



/* Tipos */
Type:           Type OBRACKET ExpNullable CBRACKET { ; }
                | Type TILDE  	                   { ; }
                | TBOOL                            { ; }
                | TCHAR                            { ; }
                | TINT                             { ; }
                | TFLOAT                           { ; }
                | TSTRING                          { ; }
                | TLIST                            { ; }
;

ExpNullable:    Exp             { ; }
                | /*lambda*/    { ; }
;

/* Definiciones */
VarInst:        VarDef                    { ; }
	        | Assign                  { ; }
;
VarDef:         LET Type ID OptAssign     { ; }
;
OptAssign:      Assign RValue             { ; }
	        | /* lambda */            { ; }
;
Assign:         LValue Assign RValue      { ; }
;
RValue:         Exp                       { ; }
                | Array                   { ; }
                | STRING                  { ; }
                | NEW Type                { ; }
                | VENGEANCE LValue        { ; }
;

/* Expresiones */
Exp:            NUMBER               { ; }
                | DECIMAL            { ; }
                | LValue             { ; }
                | TRUE               { ; }
                | FALSE              { ; }
                | CHAR               { ; }
                | CallFunc           { ; }
                | Exp ADD Exp        { ; }
                | Exp SUB Exp        { ; }
                | Exp MULT Exp       { ; }
                | Exp DIV Exp        { ; }
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
                | Exp LEQ Exp        { ; }
                | NOT Exp            { ; }
;

/* Left Values */
LValue:         LValue OBRACKET Exp CBRACKET   { ; }
                | ID                           { ; }
                | LValue DOT ID                { ; }
                | DEREF LValue                 { ; }
;

/* Funciones */
DefFunc:        FUNC ID OPAR FuncPar CPAR DTWODOTS Type OCURLYBRACKET FuncBody CCURLYBRACKET { ; }
;
FuncPar:        ParList                 { ; }
                | /* lambda */          { ; }
;
ParList:        ParList COMMA ParList   { ; }
                | Type ID               { ; }
;

CallFunc:       ID OPAR ArgElems CPAR { ; }
;
ArgElems:       ArgElems RValue                 { ; } 
                ArgElems RValue COMMA           { ; }
	        | /* lambda */                  { ; }
;

/* Procedimientos */
DefProc:        PROC ID OPAR FuncPar CPAR OCURLYBRACKET FuncBody CCURLYBRACKET { ; }
;

/* Arreglos */
Array:          OBRACKET ArrExp CBRACKET   { ; }
;
ArrExp:         ArrElems RValue         { ; }
		| /* lambda */          { ; }
;
ArrElems:       ArrElems RValue COMMA   { ; }
		| /* lambda */          { ; }
;

/* Union */
DefUnion:       UNION ID OCURLYBRACKET UnionBody CCURLYBRACKET   { ; }
; 
UnionBody:      LET Type ID SEMICOLON         { ; }
		| UnionBody Type ID SEMICOLON { ; }
;

/* Struct */
DefStruct:      TSTRUCT ID OCURLYBRACKET StructBody CCURLYBRACKET { ; }
;
StructBody:     Type ID OptAssign SEMICOLON            { ; }
		| StructBody Type ID OptAssign SEMICOLON  { ; }
;

/* Condicionales */
Conditional:    IF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif OptElse { ; }
;
OptElif:        Elif                    { ; }
		| /* lambda */          { ; }
;
Elif:           ELIF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET     { ; }
;
OptElse:        ELSE OCURLYBRACKET Inst CCURLYBRACKET   { ; }
		| /* lambda */                          { ; }
;
%%
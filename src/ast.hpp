#include <string>
#include <iostream>

using namespace std;

class node {
  public:
    node() {};
    // Print a node representation.
    virtual void print(int ident) { };
};

/* */
class NodeBOOL : public node {
  protected:
    bool value;

  public:
    NodeBOOL(bool value)
      : value(value) {};

    void print(int ident);
};

class NodeCHAR : public node {
  protected:
    char value;

  public:
    NodeCHAR(char value)
      : value(value) {};

    void print(int ident);
};

class NodeINT : public node {
  protected:
    int value;

  public:
    NodeINT(int value)
      : value(value) {};

    void print(int ident);
};

class NodeFLOAT : public node {
  protected:
    float value;

  public:
    NodeFLOAT(float value)
    : value(value) {};

    void print(int ident);
};

class NodeSTRING : public node {
  protected:
    string value;

  public:
    NodeSTRING(string value)
    : value(value) {};

    void print(int ident);
};

/* EXPRESSIONS  */
/* Representation of: binary operators. */
class NodeBinaryOperator : public node {
  protected:
    node* left;
    string op;
    node* right;

  public:
    NodeBinaryOperator(node *left, string op, node *right)
    : left(left), op(op), right(right) {};

    void print(int ident);
};

/* Representation of: unary operations. */
class NodeUnaryOperator : public node {
  protected:
    string op;
    node *exp;

  public:
    NodeUnaryOperator(string op, node *exp)
    : op(op), exp(exp) {};

    void print(int ident);
};

/* HEAP NODES  */
/* Representation of: new Type. */
class NodeNew : public node {
  protected:
    node *type;

  public:
    NodeNew(node *type)
    : type(type) {};

    void print(int ident);
};

/* Representation of: vengeance Type. */
class NodeVengeance : public node {
  protected:
    node *lvalue;

  public:
    NodeVengeance(node *lvalue)
    : lvalue(lvalue) {};

    void print(int ident);
};

/* TYPEDEF NODES  */
/* Class for defined types. */
class NodeTypePrimitiveDef : public node {
  protected:
    string type;

  public:
    NodeTypePrimitiveDef(string type)
    : type(type) {};

    void print(int ident);
};

/* Representation of: Type ~. */
class NodeTypePointerDef : public node {
  protected:
    node *type;

  public:
    NodeTypePointerDef(node *type)
    : type(type) {};

    void print(int ident);
};

/* Representation of: Type [ Exp ]. */
class NodeTypeArrayDef : public node {
  protected:
    node *type;
    node *size;

  public:
    NodeTypeArrayDef(node *type, node *size)
    : type(type), size(size) {};

    void print(int ident);
};

/* Representation of: Type ID = RValue. */
class NodeVarDef : public node {
  protected:
    node *type;
    string id;
    node *rvalue;

  public:
    NodeVarDef(node *type, string id, node *rvalue = NULL)
    : type(type), id(id), rvalue(rvalue) {};

    void print(int ident);
};

/* LVALUE NODES  */
/* Class for defined id lvalues. */
class NodeIDLValue : public node {
  protected:
    string id;

  public:
    NodeIDLValue(string id)
    : id(id) {};

    void print(int ident);
};

/* Representation of: LValue . ID. */
class NodeLValueDot : public node {
  protected:
    node *lvalue;
    string id;

  public:
    NodeLValueDot(node *lvalue, string id)
    : lvalue(lvalue), id(id) {};

    void print(int ident);
};

/* Representation of: &LValue. */
class NodePointerLValue : public node {
  protected:
    node *lvalue;

  public:
    NodePointerLValue(node *lvalue)
    : lvalue(lvalue) {};

    void print(int ident);
};

/* Representation of: LValue [ Exp ]. */
class NodeArrayLValue : public node {
  protected:
    node *lvalue;
    node *index;

  public:
    NodeArrayLValue(node *lvalue, node *index)
    : lvalue(lvalue), index(index) {};

    void print(int ident);
};

/* Representation of: LValue [ Exp ... Exp ]. */
class NodeSubArray : public node {
  protected:
    node *lvalue;
    node *indexStart;
    node *indexEnd;

  public:
    NodeSubArray(node *lvalue, node *indexStart, node *indexEnd)
    : lvalue(lvalue), indexStart(indexStart), indexEnd(indexEnd) {};

    void print(int ident);
};

/* ARRAY NODES  */
/* Representation of arrays. */
class NodeArray : public node {
  protected:
    node *elems;

  public:
    NodeArray(node *elems)
    : elems(elems) {};

    void print(int ident);
};

/* Representation of: RValue , ArrElems. */
class NodeArrayElems : public node {
  protected:
    node *rvalue;
    node *head;

  public:
    NodeArrayElems(node *rvalue, node *head = NULL)
      : rvalue(rvalue), head(head) {};

    void print(int ident);
};

class NodeArrayRange : public node {
  protected:
    node* min;
    node* max;
  
  public:
    NodeArrayRange(node* min, node* max)
      : min(min), max(max) {}
    
    void print(int ident);
};

/* FUNCTION CALL NODES */
/* Representation of: function calls. */
class NodeCallFunction : public node {
  protected:
    string id;
    node *args;

  public:
    NodeCallFunction(string id, node *args)
    : id(id), args(args) {};

    void print(int ident);
};

/* Representation of: RValue , FuncArgs. */
class NodeCallFunctionArgs : public node {
  protected:
    node *head;
    node *rvalue;

  public:
    NodeCallFunctionArgs(node *rvalue, node *head = NULL)
    : rvalue(rvalue), head(head) {};

    void print(int ident);
};

/* UNION DEF NODES */
/* Representation of: union definition. */
class NodeUnionDef : public node {
  protected:
    string id;
    node *fields;

  public:
    NodeUnionDef(string id, node *fields)
    : id(id), fields(fields) {};

    void print(int ident);
};

/* Representation of: UnionBody LET Type ID SEMICOLON  */
class NodeUnionFields : public node {
  protected:
    node *head;
    string id;
    node *type;

  public:
    NodeUnionFields(string id, node *type, node *head=NULL)
    : id(id), type(type), head(head) {};

    void print(int ident);
};

/* STRUCT DEF NODES */
/* Representation of struct definition. */
class NodeStructDef : public node {
  protected:
    string id;
    node *fields;

  public:
    NodeStructDef(string id, node *fields)
    : id(id), fields(fields) {};

    void print(int ident);
};

/* Representation of: StructBody VarDef;  */
class NodeStructFields : public node {
  protected:
    node *head;
    node *fields;

  public:
    NodeStructFields(node *fields, node *head=NULL)
    : fields(fields), head(head) {};

    void print(int ident);
};

/* CONDITIONAL DEF NODES */
/* Representation of if-elif-else blocks. */
class NodeConditional : public node {
  protected:
    node *cond;
    node *body;
    node *elifs;
    node *else_def;

  public:
    NodeConditional(node *cond, node *body, node *elifs, node *else_def)
    : cond(cond), body(body), elifs(elifs), else_def(else_def) {};

    void print(int ident);
};

/* Representation of: ELIF OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET. */
class NodeElif : public node {
  protected:
    node *elifs;
    node *cond;
    node *body;

  public:
    NodeElif(node *cond, node *body, node *elifs = NULL)
    : cond(cond), body(body), elifs(elifs) {};

    void print(int ident);
};

/* Representation of: ELSE OCURLYBRACKET Inst CCURLYBRACKET. */
class NodeElse : public node {
  protected:
    node *body;

  public:
    NodeElse(node *body)
    : body(body) {};

    void print(int ident);
};

/* LOOP NODES  */
/* Representation of while blocks. */
class NodeWhile : public node {
  protected:
    node *cond;
    node *body;

  public:
    NodeWhile(node *cond, node *body)
    : cond(cond), body(body) {};

    void print(int ident);
};

/* Representation of for blocks. */
class NodeFor : public node {
  protected:
    string iter;
    node *range;
    node *body;

  public:
    NodeFor(string iter, node *range, node *body)
    : iter(iter), range(range), body(body) {};

    void print(int ident);
};

/* PROC and FUNC DEF NODES  */
/* Representation of proc and func definition. */
class NodeFuncDef : public node {
  protected:
    string id;
    node *args;
    node *body;
    node* type;

  public:
    NodeFuncDef(string id, node *args, node *body, node* type)
    : id(id), args(args), body(body), type(type) {};

    void print(int ident);
};

class NodeReturn : public node {
  protected:
    node* exp;
  
  public:
    NodeReturn(node* exp)
      : exp(exp) {};
    
    void print(int ident);
};

class NodeContinue : public node {    
    void print(int ident);
};

class NodeBreak : public node {    
    void print(int ident);
};

class NodeProcDef : public node {
  protected:
    string id;
    node *args;
    node *body;

  public:
    NodeProcDef(string id, node *args, node *body)
    : id(id), args(args), body(body) {};

    void print(int ident);
};

class NodeRoutineArgsDef : public node {
  protected:
    node *args;
    node *type;
    bool ref;
    string id;

  public:
    NodeRoutineArgsDef(node *type, bool ref, string id, node *args=NULL)
    : type(type), ref(ref), id(id), args(args) {};

    void print(int ident);
};

/* Representacion of: Inst InstAux */
class NodeInst : public node {
  protected:
    node *head;
    node *inst;

  public:
    NodeInst(node *inst, node *head=NULL)
    : inst(inst), head(head) {};

    void print(int ident);
};

/* INSTRUCTION NODES  */
class NodeAssign : public node {
  protected:
    node *lvalue;
    node *rvalue;

  public:
    NodeAssign(node *lvalue, node *rvalue)
    : lvalue(lvalue), rvalue(rvalue) {};

    void print(int ident);
};

/* Root node. */
class NodeStart {
  protected:
    node *inst;

  public:
    NodeStart(node *inst)
      : inst(inst) {};

    void print(int ident);
};

/* Nodes for I/0 */
class NodePrint : public node {
  protected:
    node* exp;
  
  public:
    NodePrint(node* exp)
    : exp(exp) {};

    void print(int ident);
};

class NodeInput : public node {
  protected:
    node* type;
    node* exp;
  
  public:
    NodeInput(node* type, node* exp=NULL)
    : exp(exp), type(type){};

    void print(int ident);
};
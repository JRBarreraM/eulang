#include "ast.hpp"
using namespace std;

void NodeBOOL::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

void NodeCHAR::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

void NodeINT::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

void NodeFLOAT::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

void NodeSTRING::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

void NodeBinaryOperator::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << op << endl;
    left->print(ident+1);
    right->print(ident+1);
}

void NodeUnaryOperator::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << op << endl;
    exp->print(ident+1);
}

void NodeNew::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "new" << endl;
    type->print(ident+1);
}

void NodeVengeance::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "vengeance" << endl;
    lvalue->print(ident+1);
}

void NodeTypePrimitiveDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << type << endl;
}

void NodeTypePointerDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "~" << endl;
    type->print(ident+1);
}

void NodeTypeArrayDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ARRAY" << endl;
    type->print(ident+1);
    size->print(ident+1);
}

void NodeVarDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "LET " << id << endl;
    type->print(ident+1);
    rvalue->print(ident+1);
}

void NodeIDLValue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << id << endl;
}

void NodeLValueDot::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "." << id << endl;
    lvalue->print(ident+1);
}

void NodePointerLValue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "&" << endl;
    lvalue->print(ident+1);
}

void NodeArrayLValue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "EVALARRAY" << endl;
    lvalue->print(ident+1);
    index->print(ident+1);
}

void NodeSubArray::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "SUBARRAY" << endl;
    lvalue->print(ident+1);
    indexStart->print(ident+1);
    indexEnd->print(ident+1);
}

void NodeArray::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ARRAYLITERAL" << endl;
    elems->print(ident+1);
}

void NodeArrayElems::print(int ident){
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    if(head)
        head->print(ident);
    rvalue->print(ident);
}

void NodeCallFunction::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << id << "()" << endl;
    args->print(ident+1);
}

void NodeCallFunctionArgs::print(int ident){
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    if(head)
        head->print(ident);
    rvalue->print(ident);
}

void NodeUnionDef::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "UNION " << id << endl;
    fields->print(ident+1);
}

void NodeUnionFields::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    if(head)
        head->print(ident);
    type->print(ident);
    cout << id << endl;
}

void NodeStructDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "STRUCT " << id << endl;
    fields->print(ident+1);
}

void NodeStructFields::print(int ident) {
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    if(head)
        head->print(ident);
    fields->print(ident+1);
}

void NodeConditional::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "IF" << endl;
    cond->print(ident+1);
    body->print(ident+1);
    if(elifs)
        elifs->print(ident+1);
    if(else_def)
        else_def->print(ident+1);
}

void NodeElif::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ELIF" << endl;
    cond->print(ident+1);
    body->print(ident+1);
    if(elifs)
        elifs->print(ident+1);
}

void NodeElse::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ELSE" << endl;
    body->print(ident+1);
}

void NodeWhile::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "WHILE" << endl;
    cond->print(ident+1);
    body->print(ident+1);
}

void NodeFor::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "FOR " << iter << endl;
    range->print(ident+1);
    body->print(ident+1);
}

void NodeFuncDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "FUNC " << id << endl;
    if(args)
        args->print(ident+1);
    type->print(ident+1);
    body->print(ident+1);
}

void NodeProcDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "PROC " << id << endl;
    if(args)
        args->print(ident+1);
    body->print(ident+1);
}

void NodeRoutineArgsDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    if(ref)
        cout << "^";
    cout << id << endl;
    type->print(ident+1);
    if(args)
        args->print(ident+1);
}

void NodeInst::print(int ident){
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    // cout << "INST" << endl;
    if(head)
        head->print(ident);
    inst->print(ident);
}

void NodeBreak::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "BREAK" << endl;
}

void NodeContinue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "CONTINUE" << endl;
}

void NodeAssign::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "=" << endl;
    lvalue->print(ident+1);
    rvalue->print(ident+1);
}

void NodeStart::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "START" << endl;
    inst->print(ident+1);
}

void NodePrint::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "PRINT" << endl;
    exp->print(ident+1);
}

void NodeInput::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "INPUT" << endl;
    type->print(ident+1);
    if(exp)
        exp->print(ident+1);
}

void NodeReturn::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "RETURN" << endl;
    exp->print(ident+1);
}

void NodeArrayRange::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "RANGE" << endl;
    min->print(ident+1);
    max->print(ident+1);
}
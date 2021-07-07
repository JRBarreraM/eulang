#include "ast.hpp"
#include "symbol_table.hpp"
using namespace std;

extern sym_table st;

void NodeBOOL::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

t_type* NodeBOOL::return_type() {
    return t_type_bool::instance();
}

void NodeCHAR::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

t_type* NodeCHAR::return_type() {
    return t_type_char::instance();
}

void NodeINT::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

t_type* NodeINT::return_type() {
    return t_type_int::instance();
}

void NodeFLOAT::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

t_type* NodeFLOAT::return_type() {
    return t_type_float::instance();
}

void NodeSTRING::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << value << endl;
}

t_type* NodeSTRING::return_type() {
    return t_type_str::instance();
}

void NodeBinaryOperator::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << op << endl;
    left->print(ident+1);
    right->print(ident+1);
}

t_type* NodeBinaryOperator::return_type() {
    return type;
}

void NodeUnaryOperator::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << op << endl;
    exp->print(ident+1);
}

t_type* NodeUnaryOperator::return_type() {
    return type;
}

void NodeNew::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "new" << endl;
    type->print(ident+1);
}

t_type* NodeNew::return_type() {
    return type->return_type();
}

void NodeVengeance::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "vengeance" << endl;
    lvalue->print(ident+1);
}

t_type* NodeVengeance::return_type() {
    return t_type_no_type::instance();
}

void NodeTypePrimitiveDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << type->name << endl;
}

t_type* NodeTypePrimitiveDef::return_type() {
    return type;
}

void NodeTypePointerDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "~" << endl;
    type->print(ident+1);
}

t_type* NodeTypePointerDef::return_type() {
    return type->return_type();
}

void NodeTypeArrayDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ARRAY" << endl;
    type->print(ident+1);
    size->print(ident+1);
}

t_type* NodeTypeArrayDef::return_type() {
    // return type->return_type();
    return t_type_array::instance();
}

void NodeTypeList::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "LIST" << endl;
    type->print(ident+1);
}

t_type* NodeTypeList::return_type() {
    return type->return_type();
}

void NodeVarDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "LET " << id << endl;
    type->print(ident+1);
    if(rvalue)
        rvalue->print(ident+1);
}

t_type* NodeVarDef::return_type() {
    return type->return_type();
}

void NodeIDLValue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << id << endl;
}

t_type* NodeIDLValue::return_type() {
    symbol* lookUp = st.lookup(id);
    return lookUp ? lookUp->type : t_type_no_type::instance();
}

void NodeLValueDot::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "." << id << endl;
    lvalue->print(ident+1);
}

t_type* NodeLValueDot::return_type() {
    return t_type_no_type::instance();
}

void NodePointerLValue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "&" << endl;
    lvalue->print(ident+1);
}

t_type* NodePointerLValue::return_type() {
    return lvalue->return_type();
}

void NodeArrayLValue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "EVALARRAY" << endl;
    lvalue->print(ident+1);
    index->print(ident+1);
}

t_type* NodeArrayLValue::return_type() {
    return lvalue->return_type();
}

void NodeSubArray::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "SUBARRAY" << endl;
    lvalue->print(ident+1);
    indexStart->print(ident+1);
    indexEnd->print(ident+1);
}

t_type* NodeSubArray::return_type() {
    return lvalue->return_type();
}

void NodeArray::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ARRAYLITERAL" << endl;
    elems->print(ident+1);
}

t_type* NodeArray::return_type() {
    return t_type_array::instance();
}

void NodeArrayElems::print(int ident){
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    if(head)
        head->print(ident);
    rvalue->print(ident);
}

t_type* NodeArrayElems::return_type() {
    return rvalue->return_type();
}

void NodeCallFunction::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << id << "()" << endl;
    args->print(ident+1);
}

t_type* NodeCallFunction::return_type() {
    return t_type_no_type::instance();
}

void NodeCallFunctionArgs::print(int ident){
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    if(head)
        head->print(ident);
    rvalue->print(ident);
}

t_type* NodeCallFunctionArgs::return_type() {
    return t_type_no_type::instance();
}

void NodeUnionDef::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "UNION " << id << endl;
    fields->print(ident+1);
}

t_type* NodeUnionDef::return_type() {
    return t_type_no_type::instance();
}

void NodeUnionFields::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    if(head)
        head->print(ident);
    type->print(ident);
    cout << id << endl;
}

t_type* NodeUnionFields::return_type() {
    return t_type_no_type::instance();
}

void NodeStructDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "STRUCT " << id << endl;
    fields->print(ident+1);
}

t_type* NodeStructDef::return_type() {
    return t_type_no_type::instance();
}

void NodeStructFields::print(int ident) {
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    if(head)
        head->print(ident);
    fields->print(ident+1);
}

t_type* NodeStructFields::return_type() {
    return t_type_no_type::instance();
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

t_type* NodeConditional::return_type() {
    return t_type_no_type::instance();
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

t_type* NodeElif::return_type() {
    return t_type_no_type::instance();
}

void NodeElse::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "ELSE" << endl;
    body->print(ident+1);
}

t_type* NodeElse::return_type() {
    return t_type_no_type::instance();
}

void NodeWhile::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "WHILE" << endl;
    cond->print(ident+1);
    body->print(ident+1);
}

t_type* NodeWhile::return_type() {
    return t_type_no_type::instance();
}

void NodeFor::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "FOR " << iter << endl;
    range->print(ident+1);
    body->print(ident+1);
}

t_type* NodeFor::return_type() {
    return t_type_no_type::instance();
}

void NodeFuncSignature::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "FUNC " << id << endl;
    if(args)
        args->print(ident+1);
    type->print(ident+1);
}

t_type* NodeFuncSignature::return_type() {
    return t_type_no_type::instance();
}

void NodeProcSignature::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "PROC " << id << endl;
    if(args)
        args->print(ident+1);
}

t_type* NodeProcSignature::return_type() {
    return t_type_no_type::instance();
}

void NodeFuncDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "FUNC " << id << endl;
    if(args)
        args->print(ident+1);
    body->print(ident+1);
}

t_type* NodeFuncDef::return_type() {
    return t_type_no_type::instance();
}

void NodeProcDef::print(int ident) {
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "PROC " << id << endl;
    if(args)
        args->print(ident+1);
    body->print(ident+1);
}

t_type* NodeProcDef::return_type() {
    return t_type_no_type::instance();
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

t_type* NodeRoutineArgsDef::return_type() {
    return t_type_no_type::instance();
}

void NodeInst::print(int ident){
    // for(int i = 0; i < ident; i++)
    //     cout << "  ";
    // cout << "INST" << endl;
    if(head)
        head->print(ident);
    inst->print(ident);
}

t_type* NodeInst::return_type() {
    return t_type_no_type::instance();
}

void NodeBreak::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "BREAK" << endl;
}

t_type* NodeBreak::return_type() {
    return t_type_no_type::instance();
}

void NodeContinue::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "CONTINUE" << endl;
}

t_type* NodeContinue::return_type() {
    return t_type_no_type::instance();
}

void NodeAssign::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "=" << endl;
    lvalue->print(ident+1);
    rvalue->print(ident+1);
}

t_type* NodeAssign::return_type() {
    return t_type_no_type::instance();
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

t_type* NodePrint::return_type() {
    return t_type_no_type::instance();
}

void NodeInput::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "INPUT" << endl;
    type->print(ident+1);
    if(exp)
        exp->print(ident+1);
}

t_type* NodeInput::return_type() {
    return t_type_no_type::instance();
}

void NodeReturn::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "RETURN" << endl;
    exp->print(ident+1);
}

t_type* NodeReturn::return_type() {
    return t_type_no_type::instance();
}

void NodeArrayRange::print(int ident){
    for(int i = 0; i < ident; i++)
        cout << "  ";
    cout << "RANGE" << endl;
    min->print(ident+1);
    max->print(ident+1);
}

t_type* NodeArrayRange::return_type() {
    return t_type_no_type::instance();
}
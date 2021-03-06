#include <iostream>
#include "types.hpp"
extern queue<string> type_errors;
extern queue<string> custom_errors;
extern int yylineno;
extern int yycolumn;

string t_type :: get_name() {
    return name;
}

string t_type_array :: get_name(){
    return name + "<" + type->get_name() + ">[" + to_string(len) + "]";
}

string t_type_pointer :: get_name(){
    return type->get_name() + "~";
}

string t_type_list :: get_name(){
    return name + "<" + type->get_name() + ">";
}

t_type* arithmeticBinOPType(string left, string right){

    if(left == "error" || right == "error") return t_type_error::instance();

    // cout << "arithmeticBin: ";
    else if (left == "float"){
        if (right == "int" || right == "float"){
            // cout << "float" << endl;
            return t_type_float::instance();
        }
        else{
            // cout << "error" << endl;
            return t_type_error::instance();
        }
    }
    else if(left == "int"){
        if (right == "float"){
            // cout << "float" << endl;
            return t_type_float::instance();
        }
        else if(right == "int"){
            // cout << "int" << endl;
            return t_type_int::instance();
        }
        else {
            // cout << "error" << endl;
            push_type_error("operate", left, right);
            return t_type_error::instance();
        }
    }
    else{
        // cout << "error" << endl;
        push_type_error("operate", left, right);
        return t_type_error::instance();
    }
}

t_type* addOPType(t_type* lvalue, t_type* rvalue){
    string left = lvalue->get_name(); 
    string right = rvalue->get_name();
    if(left == "error" || right == "error") return t_type_error::instance();

    if(lvalue->name == "array" && rvalue->name == "array"){
        if (dynamic_cast<t_type_array*>(lvalue)->type->get_name() != dynamic_cast<t_type_array*>(rvalue)->type->get_name()){
            push_type_error("operate", lvalue->get_name(), rvalue->get_name());
            return t_type_error::instance();
        }
        return new t_type_array(dynamic_cast<t_type_array*>(lvalue)->type, -1);
    }

    if(lvalue->name == "list" && rvalue->name == "list"){
        if (dynamic_cast<t_type_list*>(lvalue)->type->get_name() != dynamic_cast<t_type_list*>(rvalue)->type->get_name()){
            push_type_error("operate", lvalue->get_name(), rvalue->get_name());
            return t_type_error::instance();
        }
        return new t_type_list(dynamic_cast<t_type_list*>(lvalue)->type);
    }

    
    if(left == "str" && right == "str") return t_type_str::instance();


    // cout << "arithmeticBin: ";
    else if (left == "float"){
        if (right == "int" || right == "float"){
            // cout << "float" << endl;
            return t_type_float::instance();
        }
        else{
            // cout << "error" << endl;
            return t_type_error::instance();
        }
    }
    else if(left == "int"){
        if (right == "float"){
            // cout << "float" << endl;
            return t_type_float::instance();
        }
        else if(right == "int"){
            // cout << "int" << endl;
            return t_type_int::instance();
        }
        else {
            // cout << "error" << endl;
            push_type_error("operate", left, right);
            return t_type_error::instance();
        }
    }
    else{
        // cout << "error" << endl;
        push_type_error("operate", left, right);
        return t_type_error::instance();
    }
}

t_type* arithmeticUnOPType(string left){
    if(left == "error") return t_type_error::instance();
    else if (left == "float") return t_type_float::instance();
    else if(left == "int") return t_type_int::instance();
    else{
        push_type_error("operate", left);
        return t_type_error::instance();
    }
}

t_type* booleanBinOPType(string left, string right){
    if(left == "error" || right == "error") return t_type_error::instance();
    else if (left == "bool" && right == "bool") return t_type_bool::instance();
    else{
        push_type_error("operate", left, right);
        return t_type_error::instance();
    }
}

t_type* equalsType(string left, string right){
    if(left == "error" || right == "error") return t_type_error::instance();
    else if (left == right) return t_type_bool::instance();
    else{
        push_type_error("compare", left, right);
        return t_type_error::instance();
    }
}

t_type* comparisonBinOPType(string left, string right){
    if(left == "error" || right == "error") return t_type_error::instance();
    else if (left == right && (left == "int" || left == "float" || left == "bool")) return t_type_bool::instance();
    else{
        push_type_error("compare", left, right);
        return t_type_error::instance();
    }
}

t_type* booleanUnOPType(string left){
    if(left == "error") return t_type_error::instance();
    else if (left == "bool") return t_type_bool::instance();
    else{
        push_type_error("operate", left);
        return t_type_error::instance();
    }
}

bool checkExpectedType(string exp, string rec){
    if(exp == "error" || rec == "error") return false;
    if (exp != rec){
        push_type_error("expected", rec, exp);
        return false;
    }
    return true;
}

bool checkExpectedName(string exp, string rec){
    if (exp != rec){
        custom_errors.push("syntax error: expected parameter name '" + exp + "' received '" + rec + "' at line " + to_string(yylineno) + '\n');
        return false;
    }
    return true;
}

void checkAssignType(t_type* lvalue, t_type* rvalue){
    if (lvalue->name == "list" && rvalue->name == "array"){
        if (dynamic_cast<t_type_list*>(lvalue)->type->get_name() != dynamic_cast<t_type_array*>(rvalue)->type->get_name()){
            push_type_error("assign", lvalue->get_name(), rvalue->get_name());
        }
    }
    
    else if (lvalue->get_name() != "error" && rvalue->get_name() != "error" && lvalue->get_name() != rvalue->get_name()) push_type_error("assign", lvalue->get_name(), rvalue->get_name());
}

void checkSubscriptable(string node_type){
    if(node_type == "error") return;
    if (node_type != "array" && node_type != "str" && node_type != "list" ){custom_errors.push("syntax error: " + node_type + " is not subscriptable at line " + to_string(yylineno) + " column " + to_string(yycolumn) + " \n");}
}

void push_type_error(string action, string typeA, string typeB)
{
    string e;
    // expected
    if (action == "expected"){
        e = "Error: type error, expected " + typeB + " received " + typeA + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    }
    // compare,assign,operate
    else if (typeB != "")
        e = "Error: type error, cannot " + action + " " + typeB + (action == "assign" ? " to " : " with ") + typeA + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    else if (typeB == "")
        e = "Error: type error, cannot " + action + " " + typeA + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    type_errors.push(e);
}
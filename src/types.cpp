#include <iostream>
#include "types.hpp"
extern queue<string> type_errors;
extern int yylineno;
extern int yycolumn;

string t_type :: get_name() {
    return name;
}

t_type* arithmeticBinOPType(string left, string right){

    if(left == "error" || right == "error") return t_type_error::instance();

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
    if (exp != rec){
        push_type_error("expected", rec, exp);
        return false;
    }
    return true;
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
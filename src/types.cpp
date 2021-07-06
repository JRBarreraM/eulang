#include <iostream>
#include "types.hpp"
extern queue<string> type_errors;
extern int yylineno;
extern int yycolumn;

t_type* arithmeticBinOPType(string left, string right){

    if(left == "error" || right == "error") return new t_type_error();

    if(left == "str" && right == "str") return new t_type_str();

    // cout << "arithmeticBin: ";
    else if (left == "float"){
        if (right == "int" || right == "float"){
            // cout << "float" << endl;
            return new t_type_float();
        }
        else{
            // cout << "error" << endl;
            return new t_type_error();
        }
    }
    else if(left == "int"){
        if (right == "float"){
            // cout << "float" << endl;
            return new t_type_float();
        }
        else if(right == "int"){
            // cout << "int" << endl;
            return new t_type_int();
        }
        else {
            // cout << "error" << endl;
            push_type_error("operate", left, right);
            return new t_type_error();
        }
    }
    else{
        // cout << "error" << endl;
        push_type_error("operate", left, right);
        return new t_type_error();
    }
}

t_type* arithmeticUnOPType(string left){
    if(left == "error") return new t_type_error();
    else if (left == "float") return new t_type_float();
    else if(left == "int") return new t_type_int();
    else{
        push_type_error("operate", left);
        return new t_type_error();
    }
}

t_type* booleanBinOPType(string left, string right){
    if(left == "error" || right == "error") return new t_type_error();
    else if (left == "bool" && right == "bool") return new t_type_bool();
    else{
        push_type_error("operate", left, right);
        return new t_type_error();
    }
}

t_type* equalsType(string left, string right){
    if(left == "error" || right == "error") return new t_type_error();
    else if (left == right) return new t_type_bool();
    else{
        push_type_error("compare", left, right);
        return new t_type_error();
    }
}

t_type* comparisonBinOPType(string left, string right){
    if(left == "error" || right == "error") return new t_type_error();
    else if (left == right && (left == "int" || left == "float" || left == "bool")) return new t_type_bool();
    else{
        push_type_error("compare", left, right);
        return new t_type_error();
    }
}

t_type* booleanUnOPType(string left){
    if(left == "error") return new t_type_error();
    else if (left == "bool") return new t_type_bool();
    else{
        push_type_error("operate", left);
        return new t_type_error();
    }
}

void push_type_error(string action, string typeA, string typeB)
{
    // compare,assign,operate
    string e;
    if (typeB != "")
        e = "Error: type error cannot " + action + " " + typeA + (action == "assign" ? " to " : " with ") + typeB + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    else
        e = "Error: type error cannot " + action + " " + typeA + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    type_errors.push(e);
}
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include "parser.tab.h"
#include "symbol_table.hpp"
using namespace std;

extern bool error_sintactico;

/*  */
class table_element {
	public:
		string id;
		int scope;
		int child_scope;

		table_element(string i, int s): id(i), scope(s), child_scope(-1){};

		bool operator==(const table_element & rhs) const { return (this->scope == rhs.scope && this->id == rhs.id);}

		void set_scope(int s){
			scope = s;
		}

		void set_child_scope(int s){
			child_scope = s;
		}

		void print(){
			cout << "SCOPE: " << scope;
			if (child_scope != -1)
				cout << ", CHILD SCOPE: " << child_scope ; 
		}
};


/* Definicion de la tabla de simbolos */
class sym_table {
	private:
		map<string, deque<table_element> > tabla;
		vector<int> stack;
		int last_scope;
	public:
		sym_table() : last_scope(0) {stack.push_back(last_scope);}

		int new_scope(){
			last_scope++;
			stack.push_back(last_scope);
			return last_scope;
		}

		void open_scope(string x){
			table_element * scope = lookup(x, -1);
			if (scope == NULL){
				cout << x << " esta variable no esta definida." << endl;
				stack.push_back(-1);
			}
			else if (scope->child_scope == -1){
				cout << x << " no es de un tipo complejo." << endl;
				error_sintactico = 1;
				stack.push_back(scope->child_scope);
			} else {	
				stack.push_back(scope->child_scope);
			}
		}

		void exit_scope(){
			if (!stack.empty())
			stack.pop_back();
		}

		table_element * lookup(string x, int scope){

			if ( tabla.find(x) == tabla.end() ) {
				return NULL;
			} 

			for (deque<table_element>::iterator vit = tabla[x].begin() ; vit != tabla[x].end(); vit++){
				if ( scope == -1  && (find(stack.begin(), stack.end(), vit->scope) != stack.end() ) ){
					return &(*vit);
				} 
				if ( scope != -1 && vit->scope == scope ){
					return &(*vit);
				}
			}
			return NULL;
		}

		table_element * lookup_top(string x){

			if ( tabla.find(x) == tabla.end() ) {
				return NULL;
			} 

			for (deque<table_element>::iterator vit = tabla[x].begin() ; vit != tabla[x].end(); vit++){
				if (vit->scope == stack.back()){
					return &(*vit);
				}
			}
			return NULL;
		}

		bool insert(string identifier){
			if(tabla.find(identifier) == tabla.end()){
                tabla[identifier].push_front(table_element(identifier, stack.back()));
                return true;
			}
			if (lookup(identifier, stack.back()) != NULL){
				cout << "La variable " << identifier << " ya esta declarada en el scope: " << stack.back() << endl;
				return false;	
			}
		}

		void print(){		
			cout << endl << "Imprimiendo tabla de simbolos:" << endl; 
		    for(map<string, deque<table_element> >::iterator it = tabla.begin(); it != tabla.end(); ++it) {
		    	cout << "Variable: " << it->first << " [";
		    	for (deque<table_element>::iterator vit = it->second.begin() ; vit != it->second.end(); ++vit) {
					vit->print();
					if (vit+1 != it->second.end())
						cout << ", ";
		    	}
			    cout << "]" << endl;
		    }
		}
};
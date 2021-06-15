#ifndef TABLE_H
#define TABLE_H

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

		bool operator==(const table_element & rhs) const {}

		void set_scope(int s){}

		void set_child_scope(int s){}

		void print(){}
};

/* Definicion de la tabla de simbolos */
class sym_table {
	private:
		map<string, deque<table_element>> tabla;
		vector<int> stack;
		int last_scope;
	public:
		sym_table() : last_scope(0) {}

		int new_scope(){}

		void open_scope(string x){}

		void exit_scope(){}

		table_element * lookup(string x, int scope){}

		table_element * lookup_top(string x){}

		bool insert(string identifier){}

		void print(){}
};

#endif
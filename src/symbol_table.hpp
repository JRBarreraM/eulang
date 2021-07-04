#include <vector>
#include <deque>
#include <map>
#include <string>
#include <iostream>
#include "types.hpp"

using namespace std;

/*  */
class symbol {
	public:
		string id;
		string category;
		int scope;
		t_type* type;
		bool assigned;

		symbol(string i, string c, int s, t_type* t, bool a):
			id(i), category(c), scope(s), type(t), assigned(a) {};

		bool operator==(const symbol & rhs) const;
		void print();
};

/* Definicion de la tabla de simbolos */
class sym_table {
	private:
		int last_scope;
		map<string, deque<symbol*> > table;
		vector<int> scope_stack;
		symbol* check_redef(string id);

	public:
		symbol* lookup(string id);
		sym_table();
		int new_scope();
		void exit_scope();
		bool insert(string id, string category, t_type* t, bool assigned);

		void print();
};
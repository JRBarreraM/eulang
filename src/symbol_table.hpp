#include <vector>
#include <deque>
#include <map>
#include <string>
#include <iostream>
using namespace std;

/*  */
class symbol {
	public:
		string id;
		string category;
		int scope;
		// Type

		symbol(string i, string c, int s): 
			id(i), category(c), scope(s) {};

		bool operator==(const symbol & rhs) const;
		void print();
};

/* Definicion de la tabla de simbolos */
class sym_table {
	private:
		int last_scope;
		map<string, deque<symbol*> > table;
		vector<int> scope_stack;
		bool check_redef(string id);

	public:
		symbol* lookup(string id);
		sym_table();
		int new_scope();
		void exit_scope();
		bool insert(string id);

		void print();
};
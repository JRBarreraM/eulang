#include <vector>
#include <deque>
#include <map>
#include <iostream>
#include "types.hpp"

/*  */
class extra_info{
	public:
		extra_info(){};
		virtual ~extra_info() = default;
};

class extra_info_func : public extra_info {
	public :
		int child_scope;
		int numOfArgs;
		vector<pair<string, t_type*>> args_types;
		extra_info_func(int cs, int na):
			extra_info(), child_scope(cs), numOfArgs(na){};
		extra_info_func(int cs, int na, vector<pair<string, t_type*>> at):
			extra_info(), child_scope(cs), numOfArgs(na), args_types(at){};
};



class extra_info_struct : public extra_info {
	public :
		int child_scope;
		extra_info_struct(int cs):
			extra_info(), child_scope(cs){};
};

class symbol {
	public:
		string id;
		string category;
		int scope;
		t_type* type;
		bool assigned;
		extra_info* extra_inf;
		symbol(string i, string c, int s, t_type* t, bool a, extra_info* ei=NULL):
			id(i), category(c), scope(s), type(t), assigned(a), extra_inf(ei) {};

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
		symbol* lookup(string id, int scope);
		sym_table();
		int new_scope();
		void exit_scope();
		bool insert(string id, string category, t_type* t, bool assigned, extra_info* ef=NULL);
		int get_last_scope();
		int get_top_scope();
		void print();
};
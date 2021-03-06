#include "symbol_table.hpp"
using namespace std;

/* Symbol */
bool symbol::operator==(const symbol & rhs) const { return (this->scope == rhs.scope && this->id == rhs.id);}

void symbol::print(){
	cout << "SCOPE: " << scope << ", CATEGORY: " << category << ", TYPE: " << type->get_name();
}

/* Symbol Table */
sym_table::sym_table() {
	scope_stack.push_back(0);
	insert("itochar", "func", t_type_char::instance(), true, new extra_info_func(-1,1,{make_pair("i", t_type_int::instance())}));
	insert("ctoint", "func", t_type_int::instance(), true, new extra_info_func(-1,1,{make_pair("c", t_type_char::instance())}));
	insert("itostr", "func", t_type_str::instance(), true, new extra_info_func(-1,1,{make_pair("i", t_type_int::instance())}));
	insert("floor", "func", t_type_int::instance(), true, new extra_info_func(-1,1,{make_pair("f", t_type_float::instance())}));
	insert("ceil", "func", t_type_int::instance(), true, new extra_info_func(-1,1,{make_pair("f", t_type_float::instance())}));
	insert("decimal", "func", t_type_float::instance(), true, new extra_info_func(-1,1,{make_pair("f", t_type_float::instance())}));
	insert("round", "func", t_type_int::instance(), true, new extra_info_func(-1,1,{make_pair("f", t_type_float::instance())}));
	insert("ftostr", "func", t_type_str::instance(), true, new extra_info_func(-1,1,{make_pair("f", t_type_float::instance())}));
	insert("lena", "func", t_type_int::instance(), true);
	insert("lens", "func", t_type_int::instance(), true, new extra_info_func(-1,1,{make_pair("s", t_type_str::instance())}));
	insert("split", "func", t_type_no_type::instance(), true);
	insert("stoint", "func", t_type_int::instance(), true, new extra_info_func(-1,1,{make_pair("s", t_type_str::instance())}));
	insert("stofloat", "func", t_type_float::instance(), true, new extra_info_func(-1,1,{make_pair("s", t_type_str::instance())}));
	insert("lenl", "func", t_type_int::instance(), true);
	insert("pop", "func", t_type_no_type::instance(), true);
	insert("push", "proc", t_type_no_type::instance(), true);
	insert("insert", "proc", t_type_no_type::instance(), true);
	insert("find", "func", t_type_int::instance(), true);
	insert("reversed", "func", t_type_no_type::instance(), true);
	insert("remove", "proc", t_type_no_type::instance(), true);
	insert("ltostr", "func", t_type_str::instance(), true);
	last_scope = 1;
	scope_stack.push_back(last_scope);
}

int sym_table::new_scope() {
	last_scope++;
	scope_stack.push_back(last_scope);
	return last_scope;
}

void sym_table::exit_scope() {
	if(!scope_stack.empty())
		scope_stack.pop_back();
}

symbol* sym_table::check_redef(string id) {
	symbol *s = lookup(id);
	if(s && s->scope == scope_stack.back()) {
		return s;
	}
	return NULL;
}

bool sym_table::insert(string id, string category, t_type* t, bool assigned, extra_info* ef) {
	// First check if id is in last scope
	if(table.find(id) == table.end())
		table[id];

	// Check if variable is already defined in scope
	symbol* s = check_redef(id);
	if(s && s->assigned){
		return false;
	}
	else if(s && !(s->assigned) && assigned){
		s->assigned = true;
		return true;
	}
	table[id].push_front(new symbol(id, category, scope_stack.back(), t, assigned, ef));
	return true;
}

symbol* sym_table::lookup(string id) {
	symbol* pervasive = NULL;
	symbol* best = NULL;
	for(auto e : table[id]) {
		if(e->id == id) {
			if(e->scope == 0) pervasive = e;
			else {
				for(vector<int>::reverse_iterator s = scope_stack.rbegin(); s < scope_stack.rend(); s++) {
					if(*s == e->scope) {
						best = e;
						break;
					}
					else if(best && *s == best->scope) {
						break;
					}
				}
			}
		}
	}
	if(best) return best;
	return pervasive;
}

symbol* sym_table::lookup(string id, int scope) {
	for(auto e : table[id]) {
		if(e->id == id) {
			if(scope == e->scope) {
				return e;
			}
		}
	}
	symbol* best = NULL;
	return best;
}

void sym_table::print() {
	cout << "\n***Printing Symbol Table***" << endl;

	for (auto i : table) {
		cout << "Identifier: " << i.first << " \n => [";
		for (auto qi : i.second) {
			qi->print();
			if (qi != i.second.back()) 
				cout << " || ";
		}
		cout << "]" << endl;
	}
}
int sym_table::get_last_scope(){
	return last_scope;
}

int sym_table::get_top_scope(){
	return scope_stack.back();
}
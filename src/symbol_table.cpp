#include "symbol_table.hpp"
using namespace std;

/* Symbol */
bool symbol::operator==(const symbol & rhs) const { return (this->scope == rhs.scope && this->id == rhs.id);}

void symbol::print(){
	cout << "SCOPE: " << scope;
}

/* Symbol Table */
sym_table::sym_table() {
	scope_stack.push_back(0);
	insert("itochar", "func", new t_type_char(), true);
	insert("ctoint", "func", new t_type_int(), true);
	insert("itostr", "func", new t_type_str(), true);
	insert("floor", "func", new t_type_int(), true);
	insert("ceil", "func", new t_type_int(), true);
	insert("decimal", "func", new t_type_float(), true);
	insert("round", "func", new t_type_int(), true);
	insert("ftostr", "func", new t_type_str(), true);
	insert("lena", "func", new t_type_int(), true);
	insert("lens", "func", new t_type_int(), true);
	insert("split", "func", new t_type_array(), true);
	insert("stoint", "func", new t_type_int(), true);
	insert("stofloat", "func", new t_type_float(), true);
	insert("lenl", "func", new t_type_int(), true);
	insert("pop", "func", new t_type_no_type(), true);//TODO
	insert("push", "proc", new t_type_no_type(), true);
	insert("insert", "proc", new t_type_no_type(), true);
	insert("find", "func", new t_type_int(), true);
	insert("reversed", "func", new t_type_list(), true);
	insert("remove", "proc", new t_type_no_type(), true);
	insert("ltostr", "func", new t_type_str(), true);
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

bool sym_table::insert(string id, string category, t_type* t, bool assigned) {
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
	table[id].push_front(new symbol(id, category, scope_stack.back(), t, assigned));
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

void sym_table::print() {
	cout << "\n***Printing Symbol Table***" << endl;

	for (auto i : table) {
		cout << "Identifier: " << i.first << " \n => [";
		for (auto qi : i.second) {
			qi->print();
			if (qi != i.second.back()) 
				cout << ", ";
		}
		cout << "]" << endl;
	}
}
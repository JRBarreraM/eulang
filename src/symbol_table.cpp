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
	insert("itochar");
	insert("ctoint");
	insert("itostr");
	insert("floor");
	insert("ceil");
	insert("decimal");
	insert("round");
	insert("ftostr");
	insert("lena");
	insert("lens");
	insert("split");
	insert("stoint");
	insert("stofloat");
	insert("lenl");
	insert("pop");
	insert("push");
	insert("insert");
	insert("find");
	insert("reverse");
	insert("remove");
	insert("ltostr");
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

bool sym_table::check_redef(string id) {
	symbol *p = lookup(id);
	if(p && p->scope == scope_stack.back()) {
		return true;
	}
	return false;
}

bool sym_table::insert(string id) {
	// First check if id is in last scope
	if(table.find(id) == table.end())
		table[id];

	// Check if variable is already defined in scope
	if(check_redef(id))
		return false;
	
	
	table[id].push_front(new symbol(id, "Here goes category", scope_stack.back()));
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
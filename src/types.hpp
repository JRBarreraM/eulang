#include <string>
#include <queue>
#pragma once

using namespace std;

class t_type {
	public:
		string name;
		t_type(string name):
			name(name) {}
		virtual string get_name();
};

template<typename T>
class singleton_type : public t_type {
public:
    static T* instance() {
		static T* m_instance = new T();
    	return m_instance;
	}

    singleton_type(const singleton_type&) = delete;
    singleton_type& operator= (const singleton_type) = delete;

protected:
    singleton_type(string name) : t_type(name) {}
};

class t_type_no_type : public singleton_type<t_type_no_type>{
	friend class singleton_type<t_type_no_type>;
	t_type_no_type() : singleton_type("no_type") {}
};

class t_type_error : public singleton_type<t_type_error>{
	friend class singleton_type<t_type_error>;
	t_type_error() : singleton_type("error") {}
};

class t_type_int : public singleton_type<t_type_int>{
	friend class singleton_type<t_type_int>;
	t_type_int() : singleton_type("int") {}
};

class t_type_bool : public singleton_type<t_type_bool>{
	friend class singleton_type<t_type_bool>;
	t_type_bool() : singleton_type("bool") {}
};

class t_type_char : public singleton_type<t_type_char>{
	friend class singleton_type<t_type_char>;
	t_type_char() : singleton_type("char") {}
};

class t_type_float : public singleton_type<t_type_float>{
	friend class singleton_type<t_type_float>;
	t_type_float() : singleton_type("float") {}
};

class t_type_pointer : public t_type{
	public: 
		t_type* type;
		t_type_pointer(t_type* t) : t_type("pointer"), type(t) {}
		string get_name() override;
};

class t_type_array : public t_type{
	public: 
		int len;
		t_type* type;
		t_type_array(t_type* t, int l) : t_type("array"), type(t), len(l) {}
		string get_name() override;
};

class t_type_str : public singleton_type<t_type_str>{
	friend class singleton_type<t_type_str>;
	t_type_str() : singleton_type("str") {}
};

class t_type_list : public t_type{
	public: 
		int len = 0;
		t_type* type;
		t_type_list(t_type* t) : t_type("list"), type(t) {}
		string get_name() override;
};

class t_type_struct : public singleton_type<t_type_struct>{
	friend class singleton_type<t_type_struct>;
	t_type_struct() : singleton_type("struct"){}
};

class t_type_union : public singleton_type<t_type_union>{
	friend class singleton_type<t_type_union>;
	t_type_union() : singleton_type("union"){}
};

t_type* addOPType(t_type* lvalue, t_type* rvalue);
t_type* arithmeticBinOPType(string left, string right);
t_type* arithmeticUnOPType(string left);
t_type* booleanBinOPType(string left, string right);
t_type* booleanUnOPType(string left);
t_type* comparisonBinOPType(string left, string right);
t_type* equalsType(string left, string right);
void checkAssignType(t_type* left, t_type* right);
void checkSubscriptable(string node_type);
bool checkExpectedType(string exp, string rec);
void push_type_error(string action, string typeA, string typeB="");
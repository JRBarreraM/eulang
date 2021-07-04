#pragma once
class t_type {
	public:
		std::string name;
		t_type(std::string name):
			name(name) {}
};
class t_type_no_type : public t_type{
	public:
		t_type_no_type():t_type("no_type"){}
};

class t_type_error : public t_type{
	public:
		t_type_error():t_type("error"){}

};

class t_type_int : public t_type{
	public:
		t_type_int():t_type("int"){}
};

class t_type_bool : public t_type{
	public:
		t_type_bool():t_type("bool"){}
};

class t_type_char : public t_type{
	public:
		t_type_char():t_type("char"){}
};

class t_type_float : public t_type{
	public:
		t_type_float():t_type("float"){}
};

class t_type_pointer : public t_type{
	public:
		t_type pt_type;
		t_type_pointer(const t_type& pt_type):
			t_type("pointer"),
			pt_type(pt_type){};
};

class t_type_array : public t_type{
	public:
		t_type_array():t_type("array"){}
};

class t_type_str : public t_type{
	public:
		t_type_str():t_type("str"){}
};

class t_type_list : public t_type{
	public:
		t_type_list():t_type("list"){}
};


class t_type_struct : public t_type{
	public:
		t_type_struct():t_type("struct"){}
};

class t_type_union : public t_type{
	public:
		t_type_union():t_type("union"){}
};
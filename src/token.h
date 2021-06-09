#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "utilities.h"
#include <iostream>
using namespace std;

class Token
{
public:
    int m_id;
    int m_line;
    int m_column;
    
    Token(int id, int line, int column)
        : m_id(id), m_line(line), m_column(column) {}

    virtual string to_string();
};


class TIdentifier : public Token
{
public:
    string m_value;
    
    TIdentifier(const string& value, int id, int line, int column)
        : Token{id, line, column}, m_value(value) {}

    string to_string();
};


class TInteger : public Token
{
public:
    int m_value;
    
    TInteger(int value, int id, int line, int column)
        : Token{id, line, column}, m_value(value) {}

    string to_string();
};


class TFloat : public Token
{
public:
    float m_value;
    
    TFloat(float value, int id, int line, int column)
        : Token{id, line, column}, m_value(value) {}

    string to_string();
};


class TChar : public Token
{
public:
    char m_value;
    
    TChar(char value, int id, int line, int column)
        : Token{id, line, column}, m_value(value) {}

    string to_string();
};


void print_tokens(vector<Token*> tk);
#endif
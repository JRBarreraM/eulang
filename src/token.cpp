#include "token.h"

string Token::to_string()
{
    return "Token " + t_names[m_id-1];
}

string TIdentifier::to_string()
{
    return "Token " + t_names[m_id-1] + " = " + m_value;
}

string TInteger::to_string()
{
    return "Token " + t_names[m_id-1] + " = " + std::to_string(m_value);
}

string TFloat::to_string()
{
    return "Token " + t_names[m_id-1] + " = " + std::to_string(m_value);
}

string TChar::to_string()
{
    return "Token " + t_names[m_id-1] + " = " + m_value;
}

void print_tokens(vector<Token*> tk)
{
    for (auto token : tk) {
        cout << token->to_string() << endl;
    }
};

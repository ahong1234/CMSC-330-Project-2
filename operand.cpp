#include <cctype>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream& s)
{
    char paren;
    double value;
    string name;
    
    if (isdigit(s.peek()))
    {
        s >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (s.peek() == '(')
    {
        s >> paren;
        return SubExpression::parse(s);
    }
    else
        return new Variable(parseName(s));
    return 0;
}

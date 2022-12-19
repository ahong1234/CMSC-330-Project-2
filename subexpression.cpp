#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "factorial.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "and.h"
#include "or.h"
#include "equals.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

SubExpression::SubExpression(Expression* left)
{
    this->left = left;
}

Expression* SubExpression::parse(stringstream& s)
{
    Expression* left;
    Expression* right;
    char operation;
    left = Operand::parse(s);
    s >> operation;
    cout << "Operation: (" << operation << ")" << endl;
    right = Operand::parse(s);
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '>':
            return new GreaterThan(left, right);
        case '<':
            return new LessThan(left, right);
        case '&':
            return new And(left, right);
        case '|':
            return new Or(left, right);
        case '!':
            return new Factorial(left);
        case '=':
            return new Equals(left, right);
    }
    return 0;
}
        

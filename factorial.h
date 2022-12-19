class Factorial: public SubExpression
{
public:
    Factorial(Expression* left): SubExpression(left)
    {
    }
    int evaluate()
    {
       int result = 1;
        for (int i = 1; i < left->evaluate(); i++) {
            result *= i + 1;
        }
       return result;
    }
};

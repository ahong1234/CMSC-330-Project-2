class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left);
    static Expression* parse(stringstream &s);
protected: 
    Expression* left;
    Expression* right;
};    

#include <iostream>

using namespace std;

class AbstractExpression{
public:
    virtual void interpret()=0;
};

class Num: public AbstractExpression{
    int number;
public:
    Num(int num){
        this->number = num;
    }
     void interpret() override{
        cout<<number;
    }
};

class Var: public AbstractExpression{
    char var;
public:
    Var(char c){
        this->var = c;
    }

    void interpret() override{
        cout<<var;
    }
};

class BinaryExpression: public AbstractExpression{
protected:
    AbstractExpression* expression1;
    AbstractExpression* expression2;
public:
    BinaryExpression(AbstractExpression* exp1, AbstractExpression* exp2){
        this->expression1 = exp1;
        this->expression2 = exp2;
    }
};

class Plus: public BinaryExpression{
public:
    Plus(AbstractExpression* exp1, AbstractExpression* exp2): BinaryExpression(exp1, exp2){}

    void interpret() override{
        cout<<"(";
        this->expression1->interpret();
        cout<<" + ";
        this->expression2->interpret();
        cout<<")";
    }
};

class Minus: public BinaryExpression{
public:
    Minus(AbstractExpression* exp1, AbstractExpression* exp2): BinaryExpression(exp1, exp2){}

    void interpret() override{
        cout<<"(";
        this->expression1->interpret();
        cout<<" - ";
        this->expression2->interpret();
        cout<<")";
    }
};

int main() {
    AbstractExpression* expression = new Plus(new Minus(new Plus(new Var('x'), new Var('y')), new Num(5)), new Plus
    (new Var('z'), new Num(10)));
    expression->interpret();
}

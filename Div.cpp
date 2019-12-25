//
// Created by roei on 08/11/2019.
//

#include "Div.h"


Div::Div(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {

}
double Div::calculate() {
    //throwing an exception if we divide by zero.
    if (this->rightExpression->calculate() == 0) {
        throw "Division by zero is forbidden !";
    }

    return (this->leftExpression->calculate() / this->rightExpression->calculate());
}
Div::~Div() {
    delete this->leftExpression;
    delete this->rightExpression;

}


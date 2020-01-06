//
// Created by roei on 08/11/2019.
//

#include "Minus.h"


Minus::Minus(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {

}

double Minus::calculate() {
    return (this->leftExpression->calculate() - this->rightExpression->calculate());
}

Minus::~Minus() {
    delete this->leftExpression;
    delete this->rightExpression;

}
//
// Created by roei on 08/11/2019.
//

#include "Mul.h"

Mul::Mul(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {

}
double Mul::calculate() {
    return (this->leftExpression->calculate() * this->rightExpression->calculate());
}

Mul::~Mul() {
    delete this->leftExpression;
    delete this->rightExpression;

}
//
// Created by roei on 08/11/2019.
//

#include "Plus.h"

Plus::Plus(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {

}
double Plus::calculate() {
    return (this->leftExpression->calculate() + this->rightExpression->calculate());
}

Plus::~Plus() {
    delete this->leftExpression;
    delete this->rightExpression;

}
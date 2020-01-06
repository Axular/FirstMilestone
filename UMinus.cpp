//
// Created by roei on 08/11/2019.
//

#include "UMinus.h"


//returning the minus of the expression.
double UMinus::calculate() {
    if (this->expression->calculate() == 0) {
        return this->expression->calculate();
    }
    return -(this->expression->calculate());


}

UMinus::UMinus(Expression *exp) : UnaryOperator(exp) {}

UMinus::~UMinus() {
    delete this->expression;
}

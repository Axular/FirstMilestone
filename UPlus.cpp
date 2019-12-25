//
// Created by roei on 08/11/2019.
//

#include "UPlus.h"


//returning the same expression.
    double UPlus::calculate() {
        return this->expression->calculate();
}
UPlus::UPlus(Expression *exp) : UnaryOperator(exp) {}
UPlus::~UPlus() {
    delete this->expression;
}



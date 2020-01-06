//
// Created by roei on 08/11/2019.
//

#ifndef EX1__MUL_H_
#define EX1__MUL_H_

#include "BinaryOperator.h"

//this class making a multiple operation between two expressions.
class Mul : public BinaryOperator {

public:
    Mul(Expression *exp1, Expression *exp2);

    double calculate();

    virtual ~Mul();
};

#endif //EX1__MUL_H_

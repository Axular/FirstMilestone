//
// Created by roei on 08/11/2019.
//

#ifndef EX1__DIV_H_
#define EX1__DIV_H_

#include "Expression.h"
#include "BinaryOperator.h"

//this class making a division operation between two expressions.
class Div : public BinaryOperator {

public:
    Div(Expression *exp1, Expression *exp2);

    double calculate();

    virtual ~Div();
};

#endif //EX1__DIV_H_

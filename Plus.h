//
// Created by roei on 08/11/2019.
//

#ifndef EX1__PLUS_H_
#define EX1__PLUS_H_

#include "BinaryOperator.h"

//this class making a plus operation between two expressions.
class Plus : public BinaryOperator {

public:
    Plus(Expression *exp1, Expression *exp2);

    double calculate();

    virtual ~Plus();
};

#endif //EX1__PLUS_H_

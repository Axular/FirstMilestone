//
// Created by roei on 08/11/2019.
//

#ifndef EX1__MINUS_H_
#define EX1__MINUS_H_

#include "BinaryOperator.h"

//this class making a minus operation between two expressions.
class Minus : public BinaryOperator{

  public:
    Minus(Expression *exp1, Expression *exp2);
    double calculate();
    virtual ~Minus();
};



#endif //EX1__MINUS_H_

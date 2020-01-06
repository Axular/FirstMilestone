//
// Created by roei on 08/11/2019.
//

#ifndef EX1__BINARYOPERATOR_H_
#define EX1__BINARYOPERATOR_H_

#include "Expression.h"

class BinaryOperator : public Expression {

protected:
    Expression *leftExpression;
    Expression *rightExpression;

public:
    BinaryOperator(Expression *, Expression *);

    virtual double calculate() = 0;


};

#endif //EX1__BINARYOPERATOR_H_

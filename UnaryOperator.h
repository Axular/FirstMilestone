//
// Created by roei on 08/11/2019.
//

#ifndef EX1__UNARYOPERATOR_H_
#define EX1__UNARYOPERATOR_H_

#include "Expression.h"

class UnaryOperator : public Expression {

  private:

  protected:
    Expression* expression;

  public:
    virtual double calculate() = 0;
    UnaryOperator(Expression*);


};

#endif //EX1__UNARYOPERATOR_H_

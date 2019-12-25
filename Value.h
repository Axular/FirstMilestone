//
// Created by roei on 08/11/2019.
//

#ifndef EX1__VALUE_H_
#define EX1__VALUE_H_

#include "Expression.h"
class Value : public Expression {
  private:
    double val;

  public:
    Value(double value);
    double calculate();
};

#endif //EX1__VALUE_H_

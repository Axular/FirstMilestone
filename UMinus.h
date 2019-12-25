//
// Created by roei on 08/11/2019.
//

#ifndef EX1__UMINUS_H_
#define EX1__UMINUS_H_

#include "UnaryOperator.h"
class UMinus : public UnaryOperator {
  private:

  public:
    UMinus(Expression *exp);
    double calculate();
    virtual ~UMinus();

  protected:
};

#endif //EX1__UMINUS_H_

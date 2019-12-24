//
// Created by roei on 08/11/2019.
//

#ifndef EX1__UPLUS_H_
#define EX1__UPLUS_H_

#include "UnaryOperator.h"
class UPlus : public UnaryOperator {

  private:

  public:
    UPlus(Expression *exp);
    double calculate();
    virtual ~UPlus();

  protected:
};

#endif //EX1__UPLUS_H_

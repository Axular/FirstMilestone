//
// Created by roei on 07/11/2019.
//


#ifndef EX1__VARIABLE_H_
#define EX1__VARIABLE_H_

#include <string>
#include "Expression.h"

class Variable : public Expression {
public:
    Variable(string str, double val);

    virtual ~Variable();

    double getValue() const;

    string getName() const;

    void setValue(double value);

    virtual double calculate();


    Variable &operator++();

    Variable &operator++(int);

    Variable &operator--();

    Variable &operator--(int);

    Variable &operator+=(Variable);

    Variable &operator-=(Variable);


private:
    string name;
    double value;
};

#endif //EX1__VARIABLE_H_

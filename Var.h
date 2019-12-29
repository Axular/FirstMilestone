//
// Created by asaf on 16/12/2019.
//

#ifndef FIRSTMILESTONE_VAR_H
#define FIRSTMILESTONE_VAR_H

#include <iostream>
#include <limits>
#include "Expression.h"

using namespace std;

class Var : public Expression {

public:
    enum VarType {
        InputVar,   //pointed by another variable from the simulator
        OutputVar,  //points to variable of the simulator
        RegularVar  //only contains value (doesn't point to the simulator or pointed by the simulator)
    };

private:
    string name;
    VarType type;
    string sim;
  public:
    const string &getSim() const;
  private:
    //todo maybe change back to be NaN
    // numeric_limits<double>::quiet_NaN(); //initialized to Not A Number value
    double value = 0;


public:
    Var(const string &name, const VarType &type, string addr);

    Var(const string &name, const VarType &type, double value);

    Var() = default;

    double getValue() const;

    const string &getName() const;

    void update(double val);

    VarType getType() const;

    double calculate() override;
};


#endif //FIRSTMILESTONE_VAR_H

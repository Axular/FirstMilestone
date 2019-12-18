//
// Created by asaf on 16/12/2019.
//

#ifndef FIRSTMILESTONE_VAR_H
#define FIRSTMILESTONE_VAR_H

#include <iostream>
using namespace std;

class Var {
public:
    enum VarType {
        InputVar,   //pointed by another variable from the simulator
        OutputVar,  //points to variable of the simulator
        RegularVar  //only contains value (doesn't point to the simulator or pointed by the simulator)
    };

private:
    string name;
    VarType type;
    string address;
    double value;  //NOTE: value must be double because expression.calculate() returns double


public:
    Var(const string &name, const VarType &type, double value, string addr);
    Var() = default;
    double getValue() const;

     const string &getName() const  ;

    void update(double val);
};


#endif //FIRSTMILESTONE_VAR_H

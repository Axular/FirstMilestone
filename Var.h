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

    enum UpdateFlag {
        IsUpdated, //that means out var already sent value to the server.
        NotUpdated, //means we have to send our value to the server.
        NoNeedToBeUpdated //this mark variables that dont send values to the server.
    };

private:
    string name;
    VarType type;
    string sim;
    UpdateFlag updateCondition;

public:
    const string &getSim() const;

private:
    double value;


public:
    Var(const string &theName, const VarType &theType, string theSim, const UpdateFlag &theUpdateCondition);

    Var(const string &theName, const VarType &theType, double theValue);

    Var();

    double getValue() const;

    const string &getName() const;

    void update(double val);

    VarType getType() const;

    double calculate() override;

    UpdateFlag getUpdateCondition() const;

    void setUpdateCondition(UpdateFlag update_condition);

};


#endif //FIRSTMILESTONE_VAR_H

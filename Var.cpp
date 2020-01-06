//
// Created by asaf on 16/12/2019.
//

#include "Var.h"

/*Constructor*/
Var::Var(const string &theName, const VarType &theType, string theSim, const UpdateFlag &theUpdateCondition) {
    this->name = theName;
    this->type = theType;
    this->sim = theSim;
    this->updateCondition = theUpdateCondition;
    //defaultive and must be here
    this->value = 0;
}

Var::Var(const string &theName, const VarType &theType, double theValue) {
    this->name = theName;
    this->type = theType;
    this->value = theValue;
}

/*Getters*/
const string &Var::getName() const {
    return name;
}

double Var::getValue() const {
    return value;
}


/*
 * updates the value of the var
 * (other parameters like name and type are not changeable for now)*/
void Var::update(double val) {
    this->value = val;
}

Var::VarType Var::getType() const {
    return type;
}

const string &Var::getSim() const {
    return sim;
}

double Var::calculate() {
    return this->getValue();
}

Var::UpdateFlag Var::getUpdateCondition() const {
    return updateCondition;
}

void Var::setUpdateCondition(Var::UpdateFlag update_condition) {
    updateCondition = update_condition;
}

Var::Var() {
    //defaultive and must be here
    this->value = 0;
}




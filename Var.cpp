//
// Created by asaf on 16/12/2019.
//

#include "Var.h"

/*Constructor*/
Var::Var(const string &name, const VarType &type, string s, const UpdateFlag &updateCondition) {
    this->name = name;
    this->type = type;
    this->sim = s;
    this->updateCondition = updateCondition;
}

Var::Var(const string &name, const VarType &type, double value) {
    this->name = name;
    this->type = type;
    this->value = value;
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




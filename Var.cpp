//
// Created by asaf on 16/12/2019.
//

#include "Var.h"
/*Constructor*/
Var::Var(const string &name, const VarType &type, double value, string addr){
    this->name = name;
    this->type = type;
    this->value = value;
    this->address = addr;
}

/*Getters*/
const string &Var::getName() const   {
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



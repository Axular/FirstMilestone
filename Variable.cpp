//
// Created by roei on 07/11/2019.
//

#include "Variable.h"
#include "VariablesSymbolTable.h"

Variable::Variable(string str, double val) : name(str), value(val) {}

double Variable::getValue() const {
    return value;
}

void Variable::setValue(double val) {
    Variable::value = val;
}

string Variable::getName() const {
    return this->name;
}

double Variable::calculate() {
    //IMPORTANT: this code was changed as a patch to sync variables old class with the new
    //variables symbol table class (made with some more changes in methods like "getVarValue" and
    //"isVariable"
    return VariablesSymbolTable::getInstance().getVariable(this->name)->getValue();
    // return this->value;
}

Variable::~Variable() {

}

Variable &Variable::operator++() {
    double temp;
    temp = this->value + 1;
    this->value = temp;
    return *this;
}

Variable &Variable::operator++(int) {
    this->value++;
    return *this;
}

Variable &Variable::operator--() {
    double temp;
    temp = this->value - 1;
    this->value = temp;
    return *this;
}

Variable &Variable::operator--(int) {
    this->value--;
    return *this;
}

//calculating plus between 2 variables
Variable &Variable::operator+=(Variable newVar) {
    this->setValue(this->value + newVar.getValue());
    return *this;
}

//calculating minus between 2 variables
Variable &Variable::operator-=(Variable newVar) {
    this->setValue(this->value - newVar.getValue());
    return *this;
}


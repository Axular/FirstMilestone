//
// Created by asaf on 16/12/2019.
//

#include "VariablesSymbolTable.h"
#include <mutex>

std::mutex mutex_lock;

VariablesSymbolTable &VariablesSymbolTable::getInstance() {
    static VariablesSymbolTable instance;
    return instance;
}

//todo: create mutex for getter and setter
/*input: var name
 * output: Var object (if exist), otherwise: prints an error*/
Var VariablesSymbolTable::getVariable(string varName) {
    mutex_lock.lock();
    auto iterator = this->variablesMap.find(varName);
    if (iterator == this->variablesMap.end()) {
        //todo: what should we do if we search a var that not exist?
        std::cout << "ERROR: not found";
    } else {
        return iterator->second;
    }
    mutex_lock.unlock();
}

/*
 * Inserts vars to symbol table
 * If var already exist - updates it's value
 * */
void VariablesSymbolTable::insertVariable(Var var) {
    mutex_lock.lock();
    auto iterator = this->variablesMap.find(var.getName());
    if (iterator == this->variablesMap.end()) {
        this->variablesMap.insert(pair<string, Var>(var.getName(), var));
    } else {
        iterator->second.update(var.getValue());
    }
    mutex_lock.unlock();
}


/*
 * This method updates variable's value
 * currently supports regular variables only (value is type of double)
 * */
void VariablesSymbolTable::updateVarValue(string name, double value) {
    mutex_lock.lock();
    auto iterator = this->variablesMap.find(name);
    if (iterator != this->variablesMap.end()) {
        iterator->second.update(value);//todo: add value.calculate() (shunting yard)
    } else {
        throw "ERROR: tries to update variable value of var which not exist!";
    }
    mutex_lock.unlock();
}

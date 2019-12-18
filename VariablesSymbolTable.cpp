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
        std::cout << "not found";
    } else {
        return iterator->second;
    }
    mutex_lock.unlock();
}

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

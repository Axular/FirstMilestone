//
// Created by asaf on 16/12/2019.
//

#ifndef FIRSTMILESTONE_VARIABLESSYMBOLTABLE_H
#define FIRSTMILESTONE_VARIABLESSYMBOLTABLE_H

# include "unordered_map"
#include "Var.h"
#include "Command.h"

using namespace std;

/*
class to contain all variablesMap of the program
 NOTE: this class implements the singleton design pattern which you can read about here:
 https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 this implementation Guaranteed to be thread safe and without memory leaks.
*/
class VariablesSymbolTable {
private:

    VariablesSymbolTable() = default;

    //todo: here only for testing - move back to be private
    unordered_map<string, Var> variablesMap;

public:

    unordered_map<string,Var> getVariablesMap();
    static VariablesSymbolTable &getInstance();

    //by doing "=delete" we make sure we won't get copies of our symbol table accidentally.
    VariablesSymbolTable(VariablesSymbolTable const &) = delete;

    void operator=(VariablesSymbolTable const &) = delete;

    Var getVariable(string varName);

    void insertVariable(Var var);

     void updateVarValue(string name, double value);

};


#endif //FIRSTMILESTONE_VARIABLESSYMBOLTABLE_H

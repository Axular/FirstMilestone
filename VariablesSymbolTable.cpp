//
// Created by asaf on 16/12/2019.
//

#include "VariablesSymbolTable.h"
#include "Command.h"
#include <mutex>

std::mutex mutex_lock;

unordered_map<string,Var*> VariablesSymbolTable::SimVarMap;

VariablesSymbolTable &VariablesSymbolTable::getInstance() {
    if(SimVarMap.empty()) {
        VariablesSymbolTable::SimVarMap = SimVarMapInitial();
    }
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
 * currently supports variables with double value (and not support updating sim value)
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

unordered_map<string,Var> VariablesSymbolTable::getVariablesMap() {
    return variablesMap;
}
unordered_map<string, Var*> VariablesSymbolTable::SimVarMapInitial() {
    //if(SimVarMap.empty()) {
//
    //}
    unordered_map<string, Var*> myMap;
    //1
    myMap["/instrumentation/airspeed-indicator/indicated-speed-kt"] = nullptr;
    //2
    myMap["/sim/time/warp"] = nullptr;
    //3
    myMap["/controls/switches/magnetos"] = nullptr;
    //4
    myMap["/instrumentation/heading-indicator/offset-deg"] = nullptr;
    //5
    myMap["/instrumentation/altimeter/indicated-altitude-ft"] = nullptr;
    //6
    myMap["/instrumentation/altimeter/pressure-alt-ft"] = nullptr;
    //7
    myMap["/instrumentation/attitude-indicator/indicated-pitch-deg"] = nullptr;
    //8
    myMap["/instrumentation/attitude-indicator/indicated-roll-deg"] = nullptr;
    //9
    myMap["/instrumentation/attitude-indicator/internal-pitch-deg"] = nullptr;
    //10
    myMap["/instrumentation/attitude-indicator/internal-roll-deg"] = nullptr;
    //11
    myMap["/instrumentation/encoder/indicated-altitude-ft"] = nullptr;
    //12
    myMap["/instrumentation/encoder/pressure-alt-ft"] = nullptr;
    //13
    myMap["/instrumentation/gps/indicated-altitude-ft"] = nullptr;
    //14
    myMap["/instrumentation/gps/indicated-ground-speed-kt"] = nullptr;
    //15
    myMap["/instrumentation/gps/indicated-vertical-speed"] = nullptr;
    //16
    myMap["/instrumentation/heading-indicator/indicated-heading-deg"] = nullptr;
    //17
    myMap["/instrumentation/magnetic-compass/indicated-heading-deg"] = nullptr;
    //18
    myMap["/instrumentation/slip-skid-ball/indicated-slip-skid"] = nullptr;
    //19
    myMap["/instrumentation/turn-indicator/indicated-turn-rate"] = nullptr;
    //20
    myMap["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = nullptr;
    //21
    myMap["/controls/flight/aileron"] = nullptr;
    //22
    myMap["/controls/flight/elevator"] = nullptr;
    //23
    myMap["/controls/flight/rudder"] = nullptr;
    //24
    myMap["/controls/flight/flaps"] = nullptr;
    //25
    myMap["controls/engines/engine/throttle"] = nullptr;
    //26
    myMap["/controls/engines/current-engine/throttle"] = nullptr;
    //27
    myMap["/controls/switches/master-avionics"] = nullptr;
    //28
    myMap["/controls/switches/starter"] = nullptr;
    //29
    myMap["/engines/active-engine/auto-start"] = nullptr;
    //30
    myMap["/controls/flight/speedbrake"] = nullptr;
    //31
    myMap["/sim/model/c172p/brake-parking"] = nullptr;
    //32
    myMap["/controls/engines/engine/primer"] = nullptr;
    //33
    myMap["/controls/engines/current-engine/mixture"] = nullptr;
    //34
    myMap["/controls/switches/master-bat"] = nullptr;
    //35
    myMap["/controls/switches/master-alt"] = nullptr;
    //36
    myMap["/engines/engine/rpm"] = nullptr;


    return myMap;
}

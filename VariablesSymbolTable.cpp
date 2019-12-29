//
// Created by asaf on 16/12/2019.
//

#include "VariablesSymbolTable.h"
#include "Command.h"
#include <mutex>

std::mutex mutex_lock;

unordered_map<string,Var*> VariablesSymbolTable::simVarMap;
unordered_map<int, string> VariablesSymbolTable::indexSimMap;

VariablesSymbolTable &VariablesSymbolTable::getInstance() {
    if(simVarMap.empty()) {
        VariablesSymbolTable::simVarMap = simVarMapInitial();
    }
    if(indexSimMap.empty()) {
        VariablesSymbolTable::indexSimMap = indexSimMapInitial();
    }
    static VariablesSymbolTable instance;
    return instance;
}

//todo: create mutex for getter and setter
/*input: var name
 * output: Var object (if exist), otherwise: prints an error*/
Var* VariablesSymbolTable::getVariable(string varName) {
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
void VariablesSymbolTable::insertVariable(Var* var) {
    mutex_lock.lock();
    auto iterator = this->variablesMap.find(var->getName());
    if (iterator == this->variablesMap.end()) {
        this->variablesMap.insert(pair<string, Var*>(var->getName(), var));
    } else {
        iterator->second->update(var->getValue());
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
        iterator->second->update(value);//todo: add value.calculate() (shunting yard)
    } else {
        throw "ERROR: tries to update variable value of var which not exist!";
    }
    mutex_lock.unlock();
}

unordered_map<string,Var*> VariablesSymbolTable::getVariablesMap() {
    return variablesMap;
}
//this method used to initial map between sims and Vars .
unordered_map<string, Var*> VariablesSymbolTable::simVarMapInitial() {
    unordered_map<string, Var*> myMap;
    //1
    myMap["instrumentation/airspeed-indicator/indicated-speed-kt"] = nullptr;
    //2
    myMap["sim/time/warp"] = nullptr;
    //3
    myMap["controls/switches/magnetos"] = nullptr;
    //4
    myMap["instrumentation/heading-indicator/offset-deg"] = nullptr;
    //5
    myMap["instrumentation/altimeter/indicated-altitude-ft"] = nullptr;
    //6
    myMap["instrumentation/altimeter/pressure-alt-ft"] = nullptr;
    //7
    myMap["instrumentation/attitude-indicator/indicated-pitch-deg"] = nullptr;
    //8
    myMap["instrumentation/attitude-indicator/indicated-roll-deg"] = nullptr;
    //9
    myMap["instrumentation/attitude-indicator/internal-pitch-deg"] = nullptr;
    //10
    myMap["instrumentation/attitude-indicator/internal-roll-deg"] = nullptr;
    //11
    myMap["instrumentation/encoder/indicated-altitude-ft"] = nullptr;
    //12
    myMap["instrumentation/encoder/pressure-alt-ft"] = nullptr;
    //13
    myMap["instrumentation/gps/indicated-altitude-ft"] = nullptr;
    //14
    myMap["instrumentation/gps/indicated-ground-speed-kt"] = nullptr;
    //15
    myMap["instrumentation/gps/indicated-vertical-speed"] = nullptr;
    //16
    myMap["instrumentation/heading-indicator/indicated-heading-deg"] = nullptr;
    //17
    myMap["instrumentation/magnetic-compass/indicated-heading-deg"] = nullptr;
    //18
    myMap["instrumentation/slip-skid-ball/indicated-slip-skid"] = nullptr;
    //19
    myMap["instrumentation/turn-indicator/indicated-turn-rate"] = nullptr;
    //20
    myMap["instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = nullptr;
    //21
    myMap["controls/flight/aileron"] = nullptr;
    //22
    myMap["controls/flight/elevator"] = nullptr;
    //23
    myMap["controls/flight/rudder"] = nullptr;
    //24
    myMap["controls/flight/flaps"] = nullptr;
    //25
    myMap["controls/engines/engine/throttle"] = nullptr;
    //26
    myMap["controls/engines/current-engine/throttle"] = nullptr;
    //27
    myMap["controls/switches/master-avionics"] = nullptr;
    //28
    myMap["controls/switches/starter"] = nullptr;
    //29
    myMap["engines/active-engine/auto-start"] = nullptr;
    //30
    myMap["controls/flight/speedbrake"] = nullptr;
    //31
    myMap["sim/model/c172p/brake-parking"] = nullptr;
    //32
    myMap["controls/engines/engine/primer"] = nullptr;
    //33
    myMap["controls/engines/current-engine/mixture"] = nullptr;
    //34
    myMap["controls/switches/master-bat"] = nullptr;
    //35
    myMap["controls/switches/master-alt"] = nullptr;
    //36
    myMap["engines/engine/rpm"] = nullptr;

    return myMap;
}
//this method used to initial map between index and sims , by XML order.
unordered_map<int, string> VariablesSymbolTable::indexSimMapInitial() {
    unordered_map<int, string> myMap;
    //1
    myMap[0] = "instrumentation/airspeed-indicator/indicated-speed-kt";
    //2
    myMap[1] = "sim/time/warp";
    //3
    myMap[2] = "controls/switches/magnetos";
    //4
    myMap[3] = "instrumentation/heading-indicator/offset-deg";
    //5
    myMap[4] = "instrumentation/altimeter/indicated-altitude-ft";
    //6
    myMap[5] = "instrumentation/altimeter/pressure-alt-ft";
    //7
    myMap[6] = "instrumentation/attitude-indicator/indicated-pitch-deg";
    //8
    myMap[7] = "instrumentation/attitude-indicator/indicated-roll-deg";
    //9
    myMap[8] = "instrumentation/attitude-indicator/internal-pitch-deg";
    //10
    myMap[9] = "instrumentation/attitude-indicator/internal-roll-deg";
    //11
    myMap[10] = "instrumentation/encoder/indicated-altitude-ft";
    //12
    myMap[11] = "instrumentation/encoder/pressure-alt-ft";
    //13
    myMap[12] = "instrumentation/gps/indicated-altitude-ft";
    //14
    myMap[13] = "instrumentation/gps/indicated-ground-speed-kt";
    //15
    myMap[14] = "instrumentation/gps/indicated-vertical-speed";
    //16
    myMap[15] = "instrumentation/heading-indicator/indicated-heading-deg";
    //17
    myMap[16] = "instrumentation/magnetic-compass/indicated-heading-deg";
    //18
    myMap[17] = "instrumentation/slip-skid-ball/indicated-slip-skid";
    //19
    myMap[18] = "instrumentation/turn-indicator/indicated-turn-rate";
    //20
    myMap[19] = "instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    //21
    myMap[20] = "controls/flight/aileron";
    //22
    myMap[21] = "controls/flight/elevator";
    //23
    myMap[22] = "controls/flight/rudder";
    //24
    myMap[23] = "controls/flight/flaps";
    //25
    myMap[24] = "controls/engines/engine/throttle";
    //26
    myMap[25] = "controls/engines/current-engine/throttle";
    //27
    myMap[26] = "controls/switches/master-avionics";
    //28
    myMap[27] = "controls/switches/starter";
    //29
    myMap[28] = "engines/active-engine/auto-start";
    //30
    myMap[29] = "controls/flight/speedbrake";
    //31
    myMap[30] = "sim/model/c172p/brake-parking";
    //32
    myMap[31] = "controls/engines/engine/primer";
    //33
    myMap[32] = "controls/engines/current-engine/mixture";
    //34
    myMap[33] = "controls/switches/master-bat";
    //35
    myMap[34] = "controls/switches/master-alt";
    //36
    myMap[35] = "engines/engine/rpm";

    return myMap;
}

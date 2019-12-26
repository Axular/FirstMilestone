//
// Created by asaf on 24/12/2019.
//

#include "CommandsTable.h"

CommandsTable* CommandsTable::instance = nullptr;

#include "unordered_map"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileLoopCommand.h"
#include "UpdateVarCommand.h"

#include <mutex>

using namespace std;

CommandsTable *instance;
//std::mutex mutex_lock2;


//CommandsTable *CommandsTable::getInstance() {
//
//
//}

CommandsTable *CommandsTable::getInstance() {
    if (!instance) {
        instance = new CommandsTable();
        instance->fillCommandsTable();
    }
    return instance;
}


CommandsTable::CommandsTable() {}

Command *CommandsTable::getCommand(string commandName) {
    // mutex_lock2.lock(); //todo: may cause a bug? (not sure if mutex is needed here)
    auto iterator = this->commandsMap.find(commandName);
    if (iterator == this->commandsMap.end()) {
        cout << "ERROR: command not found in commands map!";
    } else {
        return iterator->second;
    }
    //  mutex_lock2.unlock();
}

void CommandsTable::fillCommandsTable() {
//    Note: this function is called if and only if an instance was instantiated, therefore I
//    can use the instance and the commands map.

    instance->commandsMap["openDataServer"] = new OpenServerCommand();
    instance->commandsMap["connectControlClient"] = new ConnectCommand();
    instance->commandsMap["var"] = new DefineVarCommand();
    instance->commandsMap["Print"] = new PrintCommand();
    instance->commandsMap["Sleep"] = new SleepCommand();
    instance->commandsMap["while"] = new WhileLoopCommand();
    instance->commandsMap["updateVarCommand"] = new UpdateVarCommand();


}

unordered_map<string, Command *> CommandsTable::getCommandsMap() {
    return commandsMap;
};

//}







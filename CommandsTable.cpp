//
// Created by asaf on 24/12/2019.
//

#include "CommandsTable.h"
#include <mutex>

std::mutex mutex_lock;

CommandsTable &CommandsTable::getInstance() {
    static CommandsTable instance;
    return instance;
}

Command CommandsTable::getCommand(string commandName) {
    mutex_lock.lock(); //todo: may cause a bug? (not sure if mutex is needed here)
    auto iterator = this->commandsMap.find(commandName);
    if (iterator == this->commandsMap.end()) {
        throw "ERROR: command not found in commands map!";
    } else {
        return iterator->second;
    }
    mutex_lock.unlock();
}

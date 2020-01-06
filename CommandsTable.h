//
// Created by asaf on 24/12/2019.
//

#ifndef FIRSTMILESTONE_COMMANDSTABLE_H
#define FIRSTMILESTONE_COMMANDSTABLE_H

#include "unordered_map"
#include "Command.h"

using namespace std;

class CommandsTable {


private:
    static CommandsTable *instance;

    CommandsTable();

    void fillCommandsTable();

    unordered_map<string, Command *> commandsMap;

public:

    Command *getCommand(string commandName);

    static CommandsTable *getInstance();

    unordered_map<string, Command *> getCommandsMap();
};


#endif //FIRSTMILESTONE_COMMANDSTABLE_H

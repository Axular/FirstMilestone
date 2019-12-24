//
// Created by asaf on 24/12/2019.
//

#ifndef FIRSTMILESTONE_COMMANDSTABLE_H
#define FIRSTMILESTONE_COMMANDSTABLE_H

# include "unordered_map"
#include "Command.h"

using namespace std;
#include <mutex>

class CommandsTable {

private:
    CommandsTable() = default;
    unordered_map<string, Command> commandsMap;

public:
    static CommandsTable &getInstance();
    int x;

    //by doing "=delete" we make sure we won't get copies of our commands table accidentally.
    CommandsTable(CommandsTable const &) = delete;
    void operator=(CommandsTable const &) = delete;

    Command getCommand(string commandName);

};


#endif //FIRSTMILESTONE_COMMANDSTABLE_H

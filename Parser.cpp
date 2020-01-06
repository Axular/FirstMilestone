//
// Created by asaf on 24/12/2019.
//

#include "Parser.h"

void Parser::parse(vector<string> fileStrings, string EOL_Sign) {
    CommandType type = Nothing;

    for (size_t i = 0; i < fileStrings.size(); i++) {

        vector<string> pieceOfCodeToExecute;
        string firstWord = fileStrings[i];
        type = determineType(firstWord);

        //parser detected a command and calls to its execute method
        if (type == Command) {
            //increment i to look from next word
            i++;
            while (fileStrings[i] != EOL_Sign) {
                pieceOfCodeToExecute.push_back(fileStrings[i]);
                i++;
            }
            //call Command.execute()
            CommandsTable::getInstance()->getCommandsMap()[firstWord]->execute(pieceOfCodeToExecute);

        } else if (type == Variable) {
            type = CommandType::Variable;
            //(without incrementing of i cause we need all vector in this case)
            while (fileStrings[i] != EOL_Sign) {
                pieceOfCodeToExecute.push_back(fileStrings[i]);
                i++;
            }
            //call DefineVarCommand
            CommandsTable::getInstance()->getCommandsMap()["updateVarCommand"]->execute(pieceOfCodeToExecute);
        } else {
            throw "Parser failed";
        };
    }
}

CommandType Parser::determineType(string firstWord) {
//    get first word to determine the command:
    auto commandsIter = CommandsTable::getInstance()->getCommandsMap().find(firstWord);
    if (commandsIter != CommandsTable::getInstance()->getCommandsMap().end()) {
        return CommandType::Command;
    } else if (VariablesSymbolTable::getInstance().contains(firstWord)) {
        return CommandType::Variable;
    } else {
        return CommandType::Nothing;
    }
}


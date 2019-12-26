//
// Created by asaf on 24/12/2019.
//

#include "Parser.h"

void Parser::parse(vector<string> fileStrings) {
    CommandType type = Nothing;

    for (int i = 0; i < fileStrings.size(); i++) {

        vector<string> pieceOfCodeToExecute;
        string firstWord = fileStrings[i];
        type = determineType(firstWord);

        //parser detected a command and calls to its execute method
        if (type == Command) {
            //increment i to look from next word
            i++;
            while (fileStrings[i] != "EOL") {
                pieceOfCodeToExecute.push_back(fileStrings[i]);
                i++;
            }
            //call Command.execute()
            CommandsTable::getInstance()->getCommandsMap()[firstWord]->execute(pieceOfCodeToExecute);

        } else if (type == Variable) {
            type = CommandType::Variable;
            //(without incrementing of i cause we need all vector in this case)
            while (fileStrings[i] != "EOL") {
                pieceOfCodeToExecute.push_back(fileStrings[i]);
                i++;
            }
            //call DefineVarCommand
            CommandsTable::getInstance()->getCommandsMap()["DefineVarCommand"]->execute(pieceOfCodeToExecute);
        }else {
            throw "Parser failed";
        };
    }
}



CommandType Parser::determineType(string firstWord){
//    get first word to determine the command:
    auto varsIter = VariablesSymbolTable::getInstance().getVariablesMap().find(firstWord);
    auto commandsIter = CommandsTable::getInstance()->getCommandsMap().find(firstWord);
    if (commandsIter != CommandsTable::getInstance()->getCommandsMap().end()) {
        return CommandType::Command;
    } else if (varsIter != VariablesSymbolTable::getInstance().getVariablesMap().end()) {
        return CommandType::Variable;
    } else {
        return CommandType::Nothing;
    }
}


/*this function return a vector with needed string till EOL sign.
vector<string> Parser::getToEOL(vector<string> fileStrings, int i) {
    vector<string> temp;
    // iterate vector from i index to EOL sign.
    for(int j = i ; !fileStrings[i].compare("EOL") ; j++) {
        temp.push_back(fileStrings[j]);
    }

    return temp;
}
#include "VariablesSymbolTable.h"*/
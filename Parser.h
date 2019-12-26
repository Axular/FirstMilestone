//
// Created by asaf on 24/12/2019.
//

#ifndef FIRSTMILESTONE_PARSER_H
#define FIRSTMILESTONE_PARSER_H

#include <iostream>
#include <vector>
#include "VariablesSymbolTable.h"
#include "CommandsTable.h"


using namespace std;

enum CommandType {
    Nothing,
    Command,
    Variable,
};

class Parser {
  public:
    Parser() = default;
    void parse(vector<string> fileStrings);

  private:
    //vector<string> getToEOL(vector<string>, int i);
    CommandType determineType(string firstWord);
};


#endif //FIRSTMILESTONE_PARSER_H

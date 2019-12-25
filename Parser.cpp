//
// Created by asaf on 24/12/2019.
//

#include "Parser.h"
#include "VariablesSymbolTable.h"
void Parser::parsing(vector<string> fileStrings) {
   // for(int i = 0 ; i < fileStrings.size() ; i++) {
   //     //if exist get iterator to in map place.
   //     auto iter =VariablesSymbolTable::getInstance().variablesMap.find(fileStrings[i]);
   //     //if we get here the key is in the map.
   //     if (iter != VariablesSymbolTable::getInstance().variablesMap.end() )
   //     {
   //         //todo make an update to existing variable
   //     } else {
//
   //     }
   // }
}
//this function return a vector with needed string till EOL sign.
vector<string> Parser::getToEOL(vector<string> fileStrings, int i) {
    vector<string> temp;
    // iterate vector from i index to EOL sign.
    for(int j = i ; !fileStrings[i].compare("EOL") ; j++) {
        temp.push_back(fileStrings[j]);
    }

    return temp;
}
#include "VariablesSymbolTable.h"

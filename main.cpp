#include <iostream>
#include "Lexer.h"
#include "VariablesSymbolTable.h"
#include "DefineVarCommand.h"


int main(int argc, char *argv[]) {


    Lexer* L = new Lexer(argv[0]);

    vector<string> test = {"name", "=", "0", "address123"};
    DefineVarCommand defineVarCommand = DefineVarCommand();
    defineVarCommand.execute(test);

    unordered_map<string,Var> m =  VariablesSymbolTable::getInstance().variablesMap;

    cout <<"testing";
}
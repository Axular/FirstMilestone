#include <iostream>
#include "Lexer.h"
#include "VariablesSymbolTable.h"
#include "DefineVarCommand.h"

#include "OpenServerCommand.h"

int main(int argc, char *argv[]) {

    Lexer *l = new Lexer(argv[argc-1]);
    //l->Lexing();
   OpenServerCommand c = OpenServerCommand();
    vector<string> v;
    string s = "5400";
    v.push_back(s);
   c.execute(v);

    Lexer* L = new Lexer(argv[0]);

    vector<string> test = {"name", "=", "0", "address123"};
    DefineVarCommand defineVarCommand = DefineVarCommand();
    defineVarCommand.execute(test);

    unordered_map<string,Var> m =  VariablesSymbolTable::getInstance().variablesMap;

    cout <<"testing";
}
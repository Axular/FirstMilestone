#include <iostream>
#include "Lexer.h"
#include "VariablesSymbolTable.h"
#include "DefineVarCommand.h"

#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"

int main(int argc, char *argv[]) {

    Lexer *l = new Lexer(argv[argc-1]);
    l->Lexing();
   //OpenServerCommand c = OpenServerCommand();
    //vector<string> v;
    //string s = "5400";
    //v.push_back(s);
    //c.execute(v);
//
    //Lexer* L = new Lexer(argv[0]);
//
    //vector<string> test = {"name", "=", "0", "address123"};
    //DefineVarCommand defineVarCommand = DefineVarCommand();
    //defineVarCommand.execute(test);
//
    //unordered_map<string,Var> m =  VariablesSymbolTable::getInstance().variablesMap;
//
    //cout <<"testing";
   ////c.execute(v);
    //
    //vector<string> t;
    //s = "127.0.0.1";
    //t.push_back(s);
    //s="5402";
    //t.push_back(s);
//
    //ConnectCommand connect = ConnectCommand();
    //connect.execute(t);

    //SleepCommand sleeper = SleepCommand();
    //vector<string> v;
    //v.push_back("5000");
    //sleeper.execute(v);

    vector<string> v;
    v.push_back("5000");
    v.push_back("5000");
    PrintCommand printer = PrintCommand();
    printer.execute(v);

    //VariablesSymbolTable::getInstance().variablesMap;
}
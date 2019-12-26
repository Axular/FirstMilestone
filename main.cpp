#include <iostream>
#include "Lexer.h"
#include "VariablesSymbolTable.h"
#include "DefineVarCommand.h"

#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "ex1.h"
#include "globals.h"
#include "test.h"
#include "WhileLoopCommand.h"
#include "CommandsTable.h"
#include "Parser.h"


int main(int argc, char *argv[]) {

    Lexer *l = new Lexer(argv[argc-1]);
    Parser *p = new Parser();
    p->parse(l->Lexing());

    //Lexer *l = new Lexer(argv[argc-1]);
    //l->Lexing();
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

   // vector<string> v;
   // v.push_back("5000");
   // v.push_back("5000");
   // PrintCommand printer = PrintCommand();
   // printer.execute(v);
    //Expression* e = nullptr;
//
    Expression* e7 = nullptr;
    try {
        // 7
        globalInterpreter->setVariables("x=1.5;y=8.5");
        //delete globalInterpreter;
    } catch (const char* e) {
        if (e7 != nullptr) {
            delete e7;
        }
        if (globalInterpreter != nullptr) {
            delete globalInterpreter;
        }
        std::cout << e << std::endl;
    }
    test* t = new test;
    t->test1();

    vector<string> loopVec;
    loopVec.push_back("x");
    loopVec.push_back(">");
    loopVec.push_back("y");
    loopVec.push_back("{");
    loopVec.push_back("do nothing.");
    loopVec.push_back("}");
    WhileLoopCommand().execute(loopVec);


    //VariablesSymbolTable::getInstance().variablesMap;
}


//todo: VALGRIND
//todo: CommandsTable destructor

//======GENERAL=========
//todo: read the exercise again and make sure we didn't forget anything.
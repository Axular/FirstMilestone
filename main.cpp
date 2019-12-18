#include <iostream>
#include "Lexer.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"

int main(int argc, char *argv[]) {

    Lexer *l = new Lexer(argv[argc-1]);
    //l->Lexing();
   //OpenServerCommand c = OpenServerCommand();
    vector<string> v;
    string s = "5400";
    v.push_back(s);
   //c.execute(v);

    vector<string> t;
    s = "127.0.0.1";
    t.push_back(s);
    s="5402";
    t.push_back(s);

    ConnectCommand connect = ConnectCommand();
    connect.execute(t);
}
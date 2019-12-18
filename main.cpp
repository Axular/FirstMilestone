#include <iostream>
#include "Lexer.h"
#include "OpenServerCommand.h"

int main(int argc, char *argv[]) {

    Lexer *l = new Lexer(argv[argc-1]);
    //l->Lexing();
   OpenServerCommand c = OpenServerCommand();
    vector<string> v;
    string s = "5400";
    v.push_back(s);
   c.execute(v);
}
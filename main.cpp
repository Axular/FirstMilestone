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
#include "WhileLoopCommand.h"
#include "CommandsTable.h"
#include "Parser.h"


int main(int argc, char *argv[]) {

    //Lexing our data.
    Lexer *l = new Lexer(argv[argc-1]);
    //creating new parser.
    Parser *p = new Parser();
    //parsing the data we have from the file.
    p->parse(l->Lexing(), "EOL");
    //this for shut down the threads before exiting.
    keepRun = false;
}


//======VALGRING========
//todo: VALGRIND
//todo: CommandsTable destructor

//======GENERAL=========
//todo: read the exercise again and make sure we didn't forget anything.
//todo: if some bugs occur check the commands maybe '/' at the beginning is not needed
//remove spaces from sim = " /blabla"
//====To Check==========
//why ->calculate of double is not accurate (i.e 0.2 becomes 0.2000000000000001)
// if command
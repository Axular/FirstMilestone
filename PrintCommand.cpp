//
// Created by roei on 24/12/2019.
//

#include <iostream>
#include "PrintCommand.h"
#include "SleepCommand.h"
void PrintCommand::execute(vector<string> executionCode) {
    //todo: remove me
    cout << "parser testing";

    //validation check: print msg if we have more the 2 string in vector
    if (executionCode.size() > 1) {
        cout << "more than one arguments in PrintCommand class - check this!"<< endl;
        SleepCommand sleeper = SleepCommand();
        //make sleep for 1 second , so we can see the msg on console.
        sleeper.goToSleep("1000");
    }


    //printing all vector string - suppose to be one string usually.
    for(string s : executionCode) {
        cout << s << endl;
    }
}


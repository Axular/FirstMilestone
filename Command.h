//
// Created by roei on 16/12/2019.
//

#ifndef FIRSTMILESTONE__COMMAND_H_
#define FIRSTMILESTONE__COMMAND_H_

#include <iostream>
#include <vector>

using namespace std;

class Command {
protected:
    //execute gets as an input a vector which contains the execution code as separated words
   virtual int execute(vector<string> executionCode) = 0;
};

#endif //FIRSTMILESTONE__COMMAND_H_

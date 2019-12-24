//
// Created by roei on 24/12/2019.
//

#ifndef FIRSTMILESTONE__SLEEPCOMMAND_H_
#define FIRSTMILESTONE__SLEEPCOMMAND_H_
#include <string>
#include <vector>
#include <thread>
#include "Command.h"

using namespace std;
class SleepCommand : public Command{
  public :
    int execute(vector<string>);
    void goToSleep(string);
};

#endif //FIRSTMILESTONE__SLEEPCOMMAND_H_

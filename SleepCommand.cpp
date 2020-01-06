//
// Created by roei on 24/12/2019.
//

#include "SleepCommand.h"

void SleepCommand::execute(vector<string> executionCode) {
    //convert string to int
    int time = stoi(executionCode[0]);

    //make program sleep for time value in millisecond.
    std::this_thread::sleep_for((std::chrono::milliseconds) time);
}

void SleepCommand::goToSleep(string s) {
    vector<string> v;
    v.push_back(s);
    this->execute(v);
}

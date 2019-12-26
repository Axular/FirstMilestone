//
// Created by roei on 24/12/2019.
//

#include "SleepCommand.h"
void SleepCommand::execute(vector<string> executionCode) {
    //convert string to int
    int time = stoi(executionCode[0]);
    //get current time before sleep/
    auto start = std::chrono::system_clock::now();

    //make program sleep for time value in millisecond.
    std::this_thread::sleep_for((std::chrono::milliseconds)time);

    //get current time at the end of the sleep
    auto end = std::chrono::system_clock::now();

    //calculate time difference
    std::chrono::duration<double> elapsed_seconds = end-start;

    //print time difference
    cout << elapsed_seconds.count()<< endl;
}
void SleepCommand::goToSleep(string s) {
    vector<string> v;
    v.push_back(s);
    this->execute(v);
}

//
// Created by roei on 24/12/2019.
//

#ifndef FIRSTMILESTONE__PRINTCOMMAND_H_
#define FIRSTMILESTONE__PRINTCOMMAND_H_
#include <string>
#include <vector>
#include "Command.h"

using namespace std;
class PrintCommand : public Command{
  public:
    int execute(vector<string>);

};

#endif //FIRSTMILESTONE__PRINTCOMMAND_H_

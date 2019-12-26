//
// Created by roei on 24/12/2019.
//

#ifndef FIRSTMILESTONE__WHILELOOPCOMMAND_H_
#define FIRSTMILESTONE__WHILELOOPCOMMAND_H_

#include <vector>
#include <string>
#include "ConditionParser.h"
#include "ex1.h"

using namespace std;

class WhileLoopCommand : public ConditionParser{
  public:
    void execute(vector<string>);

};

#endif //FIRSTMILESTONE__WHILELOOPCOMMAND_H_

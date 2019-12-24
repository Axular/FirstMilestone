//
// Created by roei on 24/12/2019.
//

#ifndef FIRSTMILESTONE__LOOPCOMMAND_H_
#define FIRSTMILESTONE__LOOPCOMMAND_H_

#include <vector>
#include <string>
#include "ConditionParser.h"
using namespace std;

class LoopCommand : public ConditionParser{
  public:
    int execute(vector<string>);

  private:
    bool condition(vector<string>) override;
};

#endif //FIRSTMILESTONE__LOOPCOMMAND_H_

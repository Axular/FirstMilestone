//
// Created by roei on 25/12/2019.
//

#ifndef FIRSTMILESTONE__IFCOMMAND_H_
#define FIRSTMILESTONE__IFCOMMAND_H_

#include "ConditionParser.h"
class IfCommand : public ConditionParser{
  public:
    int execute(vector<string>);
};

#endif //FIRSTMILESTONE__IFCOMMAND_H_

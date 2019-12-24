//
// Created by roei on 24/12/2019.
//

#ifndef FIRSTMILESTONE__CONDITIONPARSER_H_
#define FIRSTMILESTONE__CONDITIONPARSER_H_

#include "Command.h"
class ConditionParser : public Command {
  protected:
    virtual bool condition(vector<string>);
    virtual int execute(vector<string>);
};

#endif //FIRSTMILESTONE__CONDITIONPARSER_H_

//
// Created by roei on 16/12/2019.
//

#ifndef FIRSTMILESTONE__DEFINEVARCOMMAND_H_
#define FIRSTMILESTONE__DEFINEVARCOMMAND_H_

#include "Command.h"

class DefineVarCommand : public Command {
public:
    void execute(vector<string> executionCode) override;
};

#endif //FIRSTMILESTONE__DEFINEVARCOMMAND_H_

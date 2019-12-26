//
// Created by asaf on 24/12/2019.
//

#ifndef FIRSTMILESTONE_UPDATEVARCOMMAND_H
#define FIRSTMILESTONE_UPDATEVARCOMMAND_H


#include "Command.h"

class UpdateVarCommand : public  Command{

protected:
    void execute(vector<string> executionCode) override;

public:
    void updateVarValue(string name, double value);

};


#endif //FIRSTMILESTONE_UPDATEVARCOMMAND_H

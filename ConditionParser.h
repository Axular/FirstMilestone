//
// Created by roei on 24/12/2019.
//

#ifndef FIRSTMILESTONE__CONDITIONPARSER_H_
#define FIRSTMILESTONE__CONDITIONPARSER_H_

#include "Command.h"

/*
 * a condition parser class is responsible for condition classes.
 */
enum ScopeFlag {
    ScopeDidntStarted, // our flag mean we didnt started to execute the scope yet.
    ScopeStarted, //our flag means we are executing the scope now.
    ScopeEnded // our flag means we finish the current scope.
};

class ConditionParser : public Command {
protected:
    bool conditionCheck(vector<string>);
    //int execute(vector<string>);
};

#endif //FIRSTMILESTONE__CONDITIONPARSER_H_

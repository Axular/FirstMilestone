//
// Created by roei on 25/12/2019.
//

#include "IfCommand.h"
int IfCommand::execute(vector<string> ifConditionInfo) {
    vector<string> conditionInfo;
    vector<string> scopeInfo;
    int flag = ScopeDidntStarted;
//getting in scope strings operations.
    for(string s : ifConditionInfo) {
        if (!s.compare("{")) {
            flag = ScopeStarted;
            continue;
        }
        if (!s.compare("}")) {
            flag = ScopeEnded;
            break;
        }
        if (flag == ScopeStarted) {
            scopeInfo.push_back(s);
        }
        if (flag == ScopeDidntStarted) {
            conditionInfo.push_back(s);
        }
    }

    if(conditionCheck(conditionInfo)) {
        //do parse on scope info/
    }
}

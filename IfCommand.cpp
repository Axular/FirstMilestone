//
// Created by roei on 25/12/2019.
//

#include "IfCommand.h"
#include "Parser.h"

/*
 * the execute function is seperating the incoming vector from condition part and scope part
 * and run the scope if the condition is true.
 */
void IfCommand::execute(vector<string> ifConditionInfo) {
    vector<string> conditionInfo;
    vector<string> scopeInfo;
    int flag = ScopeDidntStarted;
    Parser *p = new Parser();
    //getting in scope strings operations.
    for (string s : ifConditionInfo) {
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
    //parsing the if scope
    if (conditionCheck(conditionInfo)) {
        p->parse(scopeInfo, "SEOL");
    }
    //delete allocation
    delete p;
}
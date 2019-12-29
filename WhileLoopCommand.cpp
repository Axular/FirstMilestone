//
// Created by roei on 24/12/2019.
//

#include "WhileLoopCommand.h"
#include "globals.h"
#include "Parser.h"

void WhileLoopCommand::execute(vector<string> loopCondition) {
    //todo: remove me
    //cout << "parser testing";
    vector<string> conditionInfo;
    vector<string> scopeInfo;
    int flag = ScopeDidntStarted;
    Parser *p = new Parser();

    //find first { index - should me in 4th place
    //and condition string put in new vec
    // todo delete this if other loop works fine
    //for( int i = 0 ; !loopCondition[i].compare("{") ; i++) {
    //    conditionInfo.push_back(loopCondition[i]);
    //}
    //getting in scope strings operations.
    for (string s : loopCondition) {
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
    //running the loop
    while (conditionCheck(conditionInfo)) {
        p->parse(scopeInfo, "SEOL");
    }
}
/*bool WhileLoopCommand::conditionCheck(vector<string> conditionInfo) {
    Expression* e1 = nullptr;
    Expression* e2 = nullptr;
    double leftValue;
    double rightValue;


    try {
        e1 = globalInterpreter->interpret(conditionInfo[0]);
        leftValue = e1->calculate();
        e2 = globalInterpreter->interpret(conditionInfo[2]);
        rightValue = e2->calculate();
    } catch (const char* e) {
        if (e1 != nullptr) {
            delete e1;
        }
        if (e2 != nullptr) {
            delete e2;
        }
        std::cout << e << std::endl;
        throw "Error with while loop";
    }

    if(!conditionInfo[1].compare("<")){
        if(leftValue < rightValue) {
            return true;
        } else {
            return false;
        }
    }else if(!conditionInfo[1].compare(">")){
        if(leftValue > rightValue) {
            return true;
        } else {
            return false;
        }
    }else if(!conditionInfo[1].compare(">=")){
        if(leftValue >= rightValue) {
            return true;
        } else {
            return false;
        }
    }else if(!conditionInfo[1].compare("<=")){
        if(leftValue <= rightValue) {
            return true;
        } else {
            return false;
        }
    }else if(!conditionInfo[1].compare("!=")){
        if(leftValue != rightValue) {
            return true;
        } else {
            return false;
        }
    }else if(!conditionInfo[1].compare("==")){
        if(leftValue != rightValue) {
            return true;
        } else {
            return false;
        }
    } else {
        throw "Wrong operator";
    }
}*/

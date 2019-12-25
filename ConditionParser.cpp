//
// Created by roei on 24/12/2019.
//

#include "ConditionParser.h"
#include "globals.h"
bool ConditionParser::conditionCheck(vector<string> conditionInfo) {
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
    }}

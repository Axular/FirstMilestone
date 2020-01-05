//
// Created by roei on 24/12/2019.
//

#include "ConditionParser.h"
#include "globals.h"
/*
 * This function check if the condition is false or true bases on the values
 * we get and return the answer.
 */
bool ConditionParser::conditionCheck(vector<string> conditionInfo) {
    Expression* e1 = nullptr;
    Expression* e2 = nullptr;
    double leftValue;
    double rightValue;


    try {
        //added as patch cause interpret call below
        //doesn't work with conditionInfo[0]
        string tempCaster0 = conditionInfo[0];
        string tempCaster2 = conditionInfo[2];
        //evaluate each side of condition expression
        e1 = globalInterpreter->interpret(tempCaster0);
        leftValue = e1->calculate();
        e2 = globalInterpreter->interpret(tempCaster2);
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
    //check for each possible condition
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
        if(leftValue == rightValue) {
            return true;
        } else {
            return false;
        }
    } else {
        throw "Wrong operator";
    }}

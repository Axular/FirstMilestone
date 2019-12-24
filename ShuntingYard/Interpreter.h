//
// Created by roei on 09/11/2019.
//

#ifndef EX1__INTERPRETER_H_
#define EX1__INTERPRETER_H_

#include <queue>
#include <stack>
#include <sstream>
#include <deque>
#include <string>
#include <iostream>
#include "Variable.h"
#include <map>
#include <deque>


using namespace std;



class Interpreter {

  private:
    map<string,double> variables;

    void variablesValidation(string);
    void checkValueValidation(string);
    void checkVarValidation(string);
    void expressionValidation(string);

    double getVarValue(string);

    queue<pair<string, int> > inToPost(string);
    vector<pair<string, int> > toToken(string);
    Expression* postToExpression(queue<pair<string, int> >);

  public:
    Expression* interpret(string);

    bool isVariable(string);
    void setVariables(string);



};

#endif //EX1__INTERPRETER_H_

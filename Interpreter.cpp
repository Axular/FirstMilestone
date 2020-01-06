//
// Created by roei on 09/11/2019.
//

#include <cstring>
#include <regex>
#include <mutex>
#include "Interpreter.h"
#include "UMinus.h"
#include "Value.h"
#include "Minus.h"
#include "Plus.h"
#include "Mul.h"
#include "Div.h"
#include "Variable.h"
#include "UPlus.h"
#include "VariablesSymbolTable.h"

void Interpreter::setVariables(string str) {
    //check string validation
    variablesValidation(str);
    //local variables.
    string buffer;
    string varName;
    string varValue;
    string tmp = str;

    size_t i;
    size_t j;
    //loop go till we clear the string of variables.
    while (tmp.length() > 0) {
        i = tmp.find(";");
        if (i != string::npos) {
            buffer = tmp.substr(0, i);
            tmp.erase(0, i + 1);
        } else {
            buffer = tmp;
            tmp.erase(0, tmp.length() + 1);
        }
        //get = index
        j = buffer.find("=");
        varName = buffer.substr(0, j);
        //check variable name validation.
        checkVarValidation(varName);
        buffer.erase(0, j + 1);
        varValue = buffer;
        //check variable val validation.
        checkValueValidation(varValue);
        //if this variable already initialized.
        if (isVariable(varName)) {
            //update the existing variable
            this->variables[varName] = stod(varValue);
        } else {
            //add new var to our variables vector.
            this->variables.insert(pair<string, double>(varName, std::stod(varValue)));
        }
    }
    return;
}

void Interpreter::variablesValidation(string str) {
    int counter1 = 0;
    int counter2 = 0;
    for (char c : str) {
        if (c == '=') {
            counter1++;
        } else if (c == ';') {
            counter2++;
        }
        //mean string is not in the right form
        if ((counter1 - counter2) > 1) {
            throw "Variables string is not valid";
        } else if ((counter2 - counter1) > 1) {
            throw "Variables string is not valid";
        }
    }
    //wrong input
    if (str[0] == ';' || str[0] == '=') {
        throw "Variables string is not valid";
    }
    //wrong input
    if (str[str.length() - 1] == ';' || str[str.length() - 1] == '=') {
        throw "Variables string is not valid";
    }
    regex reg("([.][.])");
    smatch matchs;

    if (regex_search(str, matchs, reg)) {
        throw "Two dots straight is not allowed";
    }
    return;
}

//this function check variable name validation.
void Interpreter::checkVarValidation(const string str) {
    if (str.empty()) {
        throw "Invalid variables string";
    }
    if (!(str.compare("-"))) {
        throw "Invalid variable name";
    }
    //check if variable name first char validation
    if ((str[0] < 97 || str[0] > 122) && str[0] != '_') {
        throw "Invalid variable name1";
    }
    //check if all name string chars are valid.
    for (char c: str) {
        if (c != 95 && !(c > 64 && c < 91) && !(c > 96 && c < 123) && !(c > 47 && c < 58)) {
            throw "Invalid variable name2";
        }
    }
    return;
}

//this function check variable val validation.
void Interpreter::checkValueValidation(string str) {
    if (str.empty() || str[0] == '.' || str[str.length() - 1] == '.') {
        throw "Invalid variables string";
    }
    string s = str;
    //check if variable val first digit is not 0.
    if (s.size() > 1 && s[0] == '0') {
        throw "invalid val input1";
    }
    regex reg("([^1-9.])");
    smatch matchs;
    //if there is other characters that is not part of a double.
    if (regex_search(str, matchs, reg)) {
        throw "This is a number , other characters are not allowed!";
    }
    return;
}

//this function check if variable is in our variables list.
std::mutex mutexA;

bool Interpreter::isVariable(string str) {
    //NOTE: this code was changed to support the new VariablesSymbolTable
    if (VariablesSymbolTable::getInstance().isEmpty()) {
        return false;
    }
    //auto iterator = VariablesSymbolTable::getInstance().getVariablesMap().find(str);
    if (VariablesSymbolTable::getInstance().contains(str)) {
        return true;
    } else {
        return false;
    }

    //older version:
    //    if (this->variables.empty()) {
//        return false;
//    }
//    map<string, double>::iterator it;
//    for (it = this->variables.begin(); it != this->variables.end() ; it++) {
//        if(!(str.compare(it->first))) {
//            return true;
//        }
//    }
//    return false;
    mutexA.unlock();
}

Expression *Interpreter::interpret(string str) {
    //validation check fo the expression
    expressionValidation(str);
    //get a queue with substirng and int as marker.
    queue<pair<string, int >> q = inToPost(str);
    //get an expression object according to the given expression string
    Expression *e = postToExpression(q);

    return e;

}

queue<pair<string, int >> Interpreter::inToPost(string str) {
    //data structs for the algorithm.
    queue<pair<string, int >> queue;
    stack<pair<string, int >> stack;
    //string seperate to substrings.
    vector<pair<string, int >> v = toToken(str);

    for (pair<string, int> p : v) {
        switch (p.second) {
            //this is a var or num
            case 0: {
                queue.push(p);
                break;
            }
            case 1: {
                //go to case 3
            }
            case 2: {
                //go to case 3
            }
                // this is a  operator
            case 3: {
                if (stack.empty()) {
                    stack.push(p);
                } else {
                    //if the precedence of the operator - if exist- at the stop of the stack is bigger then current operator
                    while ((stack.top().second >= p.second) && (stack.top().second < 4)
                           && (stack.top().second > 0)) {
                        //push the operator in the stack into the queue
                        queue.push(stack.top());
                        //pop our stack
                        stack.pop();
                        //no need to go over next item because there is none.
                        if (stack.empty() || stack.top().second) {
                            break;
                        }
                    }
                    stack.push(p);
                }
                break;
            }
                //this is a open brace
            case 4: {
                stack.push(p);
                break;
            }
                //this is a close brace
            case 5: {
                while (stack.top().second != 4) {
                    queue.push(stack.top());
                    stack.pop();
                }
                stack.pop();
                break;
                default: {
                    throw " Error occure";
                }
            }
        }
    }
    //move all the stack into the queue

    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }
    return queue;
}

vector<pair<string, int >> Interpreter::toToken(string str) {

    string tmp;
    vector<pair<string, int >> v;
    int openBraceCounter = 0;
    int closeBraceCounter = 0;

    for (int i = 0; i < (int) str.length(); i++) {
        tmp = "";

        //as long we get operators.
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            tmp += str[i];
            if (i == 0 || (str[i - 1] == '(')) {
                //if next is open brace this operator is unary.
                v.push_back(pair<string, int>(tmp, 3));

            } else {
                //if next is not open brace this operator is binary.
                if (str[i] == '*' || str[i] == '/') {
                    v.push_back(pair<string, int>(tmp, 2));
                } else {
                    v.push_back(pair<string, int>(tmp, 1));
                }
            }
            //Tokens.push_back(type_);
        } else if (str[i] == '(') {
            tmp += str[i];
            v.push_back(pair<string, int>(tmp, 4));
            openBraceCounter++;
            // Tokens.push_back(type_);
        } else if (str[i] == ')') {
            tmp += str[i];
            v.push_back(pair<string, int>(tmp, 5));
            closeBraceCounter++;
            // Tokens.push_back(type_);
        } else {
            //if this is not an operator - for example 3.5 we copy all the chars.
            while (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'
                   && str[i] != '(' && str[i] != ')' && i < (int) str.length()) {
                tmp += str[i];
                i++;
            }
            //go back to the correct iterator.
            i--;
            //check if the substing is a variable.
            if (isVariable(tmp)) {
                // else this is a number
            } else {
                //means we have a variable the is not initialed at start.
                for (int j = 0; j < (int) tmp.length(); j++) {
                    //means we have a variable the is not initialed at start.
                    if ((tmp[j] < 48 || tmp[j] > 57) && tmp[j] != '.') {
                        throw "Uninitialized variable in the expression";
                    }
                }
            }
            //push the token to the vector.
            v.push_back(pair<string, int>(tmp, 0));
        }
    }
    //means that dont have same number of braces.
    if (openBraceCounter != closeBraceCounter) {
        throw "Invalid expression - a brace is missing";
    }
    return v;
}

Expression *Interpreter::postToExpression(queue<pair<string, int >> q) {
    Expression *tmp1;
    Expression *tmp2;
    stack<Expression *> expressionStack;

    while (!(q.empty())) {
        switch (q.front().second) {
            //val / variables case
            case 0: {
                if (isVariable(q.front().first)) {
                    tmp1 = new Variable(q.front().first, getVarValue(q.front().first));
                    expressionStack.push(tmp1);
                } else {
                    tmp1 = new Value(stod(q.front().first));
                    expressionStack.push(tmp1);
                }
                break;
            }
                //binary operator case
            case 1: {
                //go to case 2 implemantation
            }
            case 2: {
                tmp1 = expressionStack.top();
                expressionStack.pop();
                tmp2 = expressionStack.top();
                expressionStack.pop();

                if (!(q.front().first.compare("-"))) {
                    expressionStack.push(new Minus(tmp2, tmp1));
                } else if (!(q.front().first.compare("+"))) {
                    expressionStack.push(new Plus(tmp2, tmp1));
                } else if (!(q.front().first.compare("*"))) {
                    expressionStack.push(new Mul(tmp2, tmp1));
                } else if (!(q.front().first.compare("/"))) {
                    expressionStack.push(new Div(tmp2, tmp1));
                }
                break;
            }
                //unary operator case
            case 3: {
                tmp1 = expressionStack.top();
                expressionStack.pop();
                if (!(q.front().first.compare("-"))) {
                    expressionStack.push(new UMinus(tmp1));
                } else if (!(q.front().first.compare("+"))) {
                    expressionStack.push(new UPlus(tmp1));
                }
                break;
            }
        }
        q.pop();
    }
    if (expressionStack.size() != 1) {
        throw "Error occur";
    }
    return expressionStack.top();
}

double Interpreter::getVarValue(string str) {
    //NOTE: this code was changed to support the new VariablesSymbolTable
    if (VariablesSymbolTable::getInstance().isEmpty()) {
        throw "ERROR: failed to value an expression, variables map is empty";
    }
    if (!VariablesSymbolTable::getInstance().contains(str)) {
        throw "ERROR: failed to value an expression, some variable from expression was not found";
    } else {
        return VariablesSymbolTable::getInstance().getVariable(str)->getValue();
    }

    //OLD CODE OF EX1
    /*    if (this->variables.empty()) {
        throw "Error - no variables";
    }
    map<string, double>::iterator it;
    for (it = this->variables.begin(); it != this->variables.end() ; it++) {
        if(!(str.compare(it->first))) {
            return it->second;
        }
    }
    //if w get here we didnt find the variable in the list
    throw "Variable not found";*/
}

void Interpreter::expressionValidation(string str) {
    int openBraceCounter = 0;
    int closeBraceCounter = 0;
    for (int i = 0; i < (int) str.length(); i++) {
        if (str[i] == '(') {
            openBraceCounter++;
        } else if (str[i] == ')') {
            closeBraceCounter++;
        }
        if (closeBraceCounter > openBraceCounter) {
            throw "Error with braces";
        }
    }
    //means that dont have same number of braces.
    if (openBraceCounter != closeBraceCounter) {
        throw "Invalid expression - a brace is missing1";
    }

    if (str[0] == '*' || str[0] == '/') {
        throw "Invalid expression - first character is a binary operator";
    }

    //old version:
    // regex reg("(^[-+][_a-zA-Z])");
    regex reg("");
    smatch matchs;

    //old version
//    if(regex_search(str, matchs, reg)) {
//        throw "Variable need a braces before unary operator";
//    }

    reg = ("([(][+\\-*\\/]*[)])");
    if (regex_search(str, matchs, reg)) {
        throw "Invalid expression";
    }

    reg = ("([(][-+][_a-zA-Z])");
    if (regex_search(str, matchs, reg)) {
        throw "Variable need a braces before unary operator";
    }

    reg = ("[ ]");
    if (regex_search(str, matchs, reg)) {
        throw "Spaces are not allowed in the expression.";
    }
    //check if there is 2 operators one by one
    reg = ("([+\\-*\\/][+\\-*\\/]+)");

    if (regex_search(str, matchs, reg)) {
        throw "Invalid expression - more then 1 operator in straight.";
    }

    reg = ("([^a-zA-Z0-9()][+*\\/\\-][a-zA-Z0-9_])");
    if (regex_search(str, matchs, reg)) {
        throw "Invalid expression";
    }
    return;
}
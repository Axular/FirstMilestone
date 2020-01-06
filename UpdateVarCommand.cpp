//
// Created by asaf on 24/12/2019.
//

#include "UpdateVarCommand.h"
#include "VariablesSymbolTable.h"
#include "Expression.h"
#include "globals.h"

void UpdateVarCommand::execute(vector<string> executionCode) {

    /*this function made for cases where var was already defined but now the program wants to update it's
     * value to be something else. value can be double but also can be another variable, examples:
     * heading = 3; //value is double
     * h0 = heading; //value is another variable
     *
     * as seen in examples above, our executionCode contains 3 parts of information: name, operator, value
     * */

    string name = executionCode[0];
    string assignmentOperator = executionCode[1];
    string value = executionCode[2];

    //Note: if this current command was called I assume that the first word is a name of
    // variable and second word is the assignment operator "=".
    //(we weren't asked to cover any other cases)

    if (assignmentOperator == "=") {
        Expression *exp = nullptr;
        double valueAsDouble;
        try {
            exp = globalInterpreter->interpret(value);
            valueAsDouble = exp->calculate();
            delete exp;
            //delete globalInterpreter;
        } catch (const char *e) {
            if (exp != nullptr) {
                delete exp;
            }
        }
        VariablesSymbolTable::getInstance().updateVarValue(name, valueAsDouble);
        VariablesSymbolTable::getInstance().getVariable(name)->setUpdateCondition(Var::UpdateFlag::NotUpdated);

    } else {
        throw "Undefined case, tried to update variable and no '=' operator was detected";
    }

}

//todo check if need to be deleted
//void UpdateVarCommand::updateVarValue(string name, double value){
//    VariablesSymbolTable::getInstance().updateVarValue(name,value);
//}
//
// Created by asaf on 24/12/2019.
//

#include "UpdateVarCommand.h"
#include "VariablesSymbolTable.h"

int UpdateVarCommand::execute(vector<string> executionCode) {

    /*this function made for cases where var was already defined but now the program wants to update it's
     * value to be something else. value can be double but also can be another variable, examples:
     * heading = 3; //value is double
     * h0 = heading; //value is another variable
     *
     * as seen in examples above, our executionCode contains 3 parts of information: name, operator, value
     * */

    string name = executionCode[0];
    string assignmentOperator = executionCode[1];
    string value = executionCode[3];

    //Note: if this current command was called I assume that the first word is a name of
    // variable and second word is the assignment operator "=".
    //(we weren't asked to cover any other cases)

    if(assignmentOperator == "=") {
        updateVarValue(name, stoi(value)); //todo: remove stoi which is not correct!! change to
                                                //todo: value.calculate() (shunting yard)
    } else {
        throw "Undefined case, tried to update variable and no '=' operator was detected";
    }

}

void UpdateVarCommand::updateVarValue(string name, double value){
    VariablesSymbolTable::getInstance().updateVarValue(name,value);
}
//
// Created by roei on 16/12/2019.
//

#include <limits>
#include "DefineVarCommand.h"
#include "Var.h"
#include "VariablesSymbolTable.h"
#include "Expression.h"
#include "globals.h"


/*this function creates new var*/
void DefineVarCommand::execute(vector<string> executionCode) {
    //todo: remove me
    //cout << "parser testing";
/*    when we define a var we know the locations are in this order: (0)name, (1)type, (2) value
 *    examples:
 *    var starter -> sim("/controls/switches/starter")
 *    var heading <- sim("/instrumentation/heading-indicator/offset-deg")
 *    var h0 = heading*/

    //saving the data from the vector with names
    string name = executionCode[0];
    string type = executionCode[1];
    string valueStr = executionCode[2];
    string sim = executionCode[2];


    //this variable is a double which is Not A Number (good for signing a double as an uninitialized double)
    Var* newVariable;

    //create new var:
    if (type == "->") {
        newVariable = new Var(name, Var::VarType::OutputVar, sim);
        //updating sim to var map:
        VariablesSymbolTable::getInstance().simVarMap[sim] = newVariable;
    } else if (type == "<-") {
        newVariable = new Var(name, Var::VarType::InputVar, sim);
        //updating sim to var map:
        VariablesSymbolTable::getInstance().simVarMap[sim] = newVariable;
    } else if (type == "=") {
        Expression* exp = nullptr;
        double value;
        try {
            exp = globalInterpreter->interpret(valueStr);
            value = exp->calculate();
            delete exp;
            //delete globalInterpreter;
        } catch (const char* e) {
            if (exp != nullptr) {
                delete exp;
            }
        }
        newVariable = new Var(name, Var::VarType::RegularVar, value);
    } else {
        cout << "Unexpected type of var: none of these were detected: =, ->, <-";
    }

    //add var to symbol table(NOTE: if var already exist, symbolTable will update it's value):
    VariablesSymbolTable::getInstance().insertVariable(newVariable);



}

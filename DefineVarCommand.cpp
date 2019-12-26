//
// Created by roei on 16/12/2019.
//

#include <limits>
#include "DefineVarCommand.h"
#include "Var.h"
#include "VariablesSymbolTable.h"


/*this function creates new var*/
void DefineVarCommand::execute(vector<string> executionCode) {

/*    when we define a var we know the locations are in this order: (0)name, (1)type, (2) value
 *    examples:
 *    var starter -> sim("/controls/switches/starter")
 *    var heading <- sim("/instrumentation/heading-indicator/offset-deg")
 *    var h0 = heading*/

    //saving the data from the vector with names
    string name = executionCode[0];
    string type = executionCode[1];
    string value = executionCode[3];
    string sim = executionCode[3];

    //this variable is a double which is Not A Number (good for signing a double as an uninitialized double)
    double NaN = numeric_limits<double>::quiet_NaN();
    Var newVariable;

    //create new var:
    if (type == "->") {
        newVariable = Var(name, Var::VarType::OutputVar, NaN, sim);
    } else if (type == "<-") {
        newVariable = Var(name, Var::VarType::InputVar, NaN, sim);
    } else if (type == "=") {
        newVariable = Var(name, Var::VarType::RegularVar, NaN, value);//todo: value.calculate()
    } else {
        cout << "Unexpected type of var: none of these were detected: =, ->, <-";
    }

    //add var to symbol table(NOTE: if var already exist, symbolTable will update it's value):
    VariablesSymbolTable::getInstance().insertVariable(newVariable);
}

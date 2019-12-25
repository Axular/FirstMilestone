//
// Created by roei on 25/12/2019.
//

#include "test.h"
#include "globals.h"
void test::test1() {
    Expression *e7 = nullptr;
    try {
        // 7
        e7 = globalInterpreter->interpret("-(-(-((x+0.5)*(y+(-3.5)))))");
        std::cout << "7: " << e7->calculate() << std::endl;
        delete e7;
        //delete globalInterpreter;
    } catch (const char* e) {
        if (e7 != nullptr) {
            delete e7;
        }
        if (globalInterpreter != nullptr) {
            delete globalInterpreter;
        }
        std::cout << e << std::endl;
    }
}

#include <iostream>
#include "Lexer.h"

int main(int argc, char *argv[]) {

    Lexer *l = new Lexer(argv[argc-1]);
    l->Lexing();
    for (string v : l->myVec) {
        if (!v.compare("EOL")) {
            cout << endl;
            continue;
        }
        cout << v << " ";

    }
}
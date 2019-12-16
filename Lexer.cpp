//
// Created by roei on 16/12/2019.
//

#include "Lexer.h"
Lexer::Lexer(string fileName) : fileName(fileName) {

}
vector<string> Lexer::Lexing() {
    string str;

    ifstream reader(this->fileName);
    if(!reader || !reader.is_open()) {
        throw "Error in file reading";
    }

    while (std::getline(reader, str)) {
        std::cout << str << "\n";
    }




    return vector<string>();
}

//
// Created by roei on 16/12/2019.
//

#ifndef FIRSTMILESTONE__LEXER_H_
#define FIRSTMILESTONE__LEXER_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <list>
#include <fstream>
#include <functional>

using namespace std;

class Lexer {
  public:
    explicit Lexer(string);
    vector<string> Lexing();

  private:
    string fileName;
    int x;
};

#endif //FIRSTMILESTONE__LEXER_H_

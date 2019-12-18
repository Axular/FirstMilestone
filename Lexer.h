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
    Lexer(const string &file_name);
    vector<string> Lexing();
    vector<string> myVec;


  private:
    string fileName;
    void addToVec(string, ifstream&);
    void varSplit(string);
    void spaceSplit(string);
    void loopSplit(string, ifstream&);
    void parametersSplit(string);
};

#endif //FIRSTMILESTONE__LEXER_H_

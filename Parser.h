//
// Created by asaf on 24/12/2019.
//

#ifndef FIRSTMILESTONE_PARSER_H
#define FIRSTMILESTONE_PARSER_H

#include <string>
#include <vector>
using namespace std;

class Parser {
public:
    Parser();
    void parsing(vector<string>);

private:
    vector<string> getToEOL(vector<string>, int i);
};


#endif //FIRSTMILESTONE_PARSER_H
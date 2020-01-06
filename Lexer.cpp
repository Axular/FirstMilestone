//
// Created by roei on 16/12/2019.
//

#include "Lexer.h"


/*
 * Lexing function is iterating over file lines
 */
vector<string> Lexer::Lexing() {
    string str;
    //open a file reader pointerloopSplit
    ifstream reader(this->fileName);
    if (!reader || !reader.is_open()) {
        throw "Error in file reading";
    }
    //reading ling by line from file
    while (std::getline(reader, str)) {
        //secondary function to handle each line
        addToVec(str, reader);
    }
    return myVec;
}

/*
 * lexer constructor
 * the function also insert EOL flag that marks us the end of the line we reader
 * from  the file.
 */
Lexer::Lexer(const string &file_name) : fileName(file_name) {}

/*
 * this function adding the data into the data struct.
 */
void Lexer::addToVec(string line, ifstream &reader) {
    //regex to find the symbols we need.
    regex reg;
    smatch matchs;
    if (regex_search(line, matchs, reg = ("var"))) {
        varSplit(line);
    } else if (regex_search(line, matchs, reg = ("while")) ||
               regex_search(line, matchs, reg = ("if"))) {
        conditionSplit(line, reader);
    } else if (regex_search(line, matchs, reg = ("="))) {
        equalSplit(line);
    } else {
        parametersSplit(line);
    }
    //end of line flag
    myVec.push_back("EOL");
}

/*
 * split a line contain var
 */
void Lexer::varSplit(string line) {
    regex reg;
    smatch matchs;
    string tok;
    //check if we have '=' in string
    reg = ("=");
    if (regex_search(line, matchs, reg)) {
        //first we insert var as this start of string .
        myVec.push_back("var");
        //delete "var " from string and handle the rest.
        std::regex target("var ");
        std::string replacement = "";
        //we already inserted var so no need it any more
        std::string s2 = std::regex_replace(line, target, replacement);
        //split the string left usually from the form x=y
        equalSplit(s2);
        //if we get here we can go back.
        return;;
    }
    //splitting string by spaces
    spaceSplit(line);
    //check last token if it sim, to get inner token
    reg = ("sim");
    tok = myVec.back();
    if (regex_search(tok, matchs, reg)) {
        //getting " places in string
        int first = tok.find_first_of('"');
        int last = tok.find_last_of('"');
        //getting substring between 2 "
        tok = tok.substr(first + 2, last - first - 2);
        //pop prev token
        myVec.pop_back();
        //push new token , inner string
        myVec.push_back(tok);
    }
}

/*
 * this function split string by space delimeter.
 */
void Lexer::spaceSplit(string line) {
    string tok;
    stringstream ss(line);
    //splitting string by spaces
    while (getline(ss, tok, ' ')) {
        myVec.push_back(tok);
    }
}

/*
 * function to handle loop string part
 */
void Lexer::conditionSplit(string line, ifstream &reader) {
    string str;
    //first we insert  the condition line.
    spaceSplit(line);
    //regex needed locals
    regex reg;
    smatch matchs;
    string tok;
    //we keep going on loop line
    while (std::getline(reader, str)) {
        //if this the end of the scope we will add to vector and stop going over the loop
        if (!str.compare("}")) {
            myVec.push_back(str);
            break;
        } else {
            //delete the tab in the start
            int first = str.find('\t');
            str = str.substr(first + 1);
            stringstream ss(str);
            //check how to split the string , -1 means there is no '=' in the string
            int equal = str.find('=');
            if (regex_search(str, matchs, reg = ("var"))) {
                varSplit(str);
            } else if (equal != -1) {
                equalSplit(str);
            } else {
                parametersSplit(str);
            }
            myVec.push_back("SEOL");
        }
    }
}

/*
 * function to handle function with parameters command
 * like Print Sleep OpenDataServe...
 */
void Lexer::parametersSplit(string str) {
    //getting first part before braces
    int firstBrace = str.find_first_of('(');
    string tok = str.substr(0, firstBrace);
    myVec.push_back(tok);
    //handling in braces token
    tok = str.substr(firstBrace + 1, str.find(')') - firstBrace - 1);
    stringstream ss(tok);
    string buffer;
    //split by ',' if there is none just push one string
    while (getline(ss, buffer, ',')) {
        if (buffer.find('\"') != -1) {
            //getting " places in string
            int first = buffer.find_first_of('"');
            int last = buffer.find_last_of('"');
            //getting substring between 2 "
            buffer = buffer.substr(first + 1, last - first - 1);
        }
        myVec.push_back(buffer);
    }
}

/*
 * this function take care when we have '=' in out line
 * and separate it.
 */
void Lexer::equalSplit(string line) {
    stringstream ss(line);
    string buffer;
    //split by '='
    getline(ss, buffer, '=');
    //remove whitespaces from string.
    buffer.erase(std::remove(buffer.begin(), buffer.end(), ' '), buffer.end());
    myVec.push_back(buffer);
    myVec.push_back("=");
    getline(ss, buffer, '=');
    buffer.erase(std::remove(buffer.begin(), buffer.end(), ' '), buffer.end());
    myVec.push_back(buffer);
}
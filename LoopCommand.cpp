//
// Created by roei on 24/12/2019.
//

#include "LoopCommand.h"
int LoopCommand::execute(vector<string> loopInfo) {
    vector<string> conditionInfo;
    //find first { index - should me in 4th place
    //and condition string put in new vec
    for( int i = 0 ; !loopInfo[i].compare("}") ; i++) {
        conditionInfo.push_back(loopInfo[i]);
    }
}
bool LoopCommand::condition(vector<string>) {

}

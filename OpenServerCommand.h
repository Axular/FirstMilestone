//
// Created by roei on 16/12/2019.
//

#ifndef FIRSTMILESTONE__OPENSERVERCOMMAND_H_
#define FIRSTMILESTONE__OPENSERVERCOMMAND_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <list>
#include <fstream>
#include <functional>
#include "Command.h"

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;


class OpenServerCommand :public  Command {
  public:
    int execute(vector<string>);
};

#endif //FIRSTMILESTONE__OPENSERVERCOMMAND_H_

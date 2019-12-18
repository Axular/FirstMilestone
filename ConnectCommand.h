//
// Created by roei on 18/12/2019.
//

#ifndef FIRSTMILESTONE__CONNECTCOMMAND_H_
#define FIRSTMILESTONE__CONNECTCOMMAND_H_

#include "Command.h"
#include <vector>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;

class ConnectCommand : public Command {

  public:
    int execute(vector<string>);
};

#endif //FIRSTMILESTONE__CONNECTCOMMAND_H_

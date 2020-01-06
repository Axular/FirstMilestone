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

/*
 * This class is making a connection to the server as client.
 *
 * */
class ConnectCommand : public Command {

public:
    void execute(vector<string>);

private:
    static void sendData(int clientSocket);
};

#endif //FIRSTMILESTONE__CONNECTCOMMAND_H_

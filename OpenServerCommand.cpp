//
// Created by roei on 16/12/2019.
//

#include <cstring>
#include "OpenServerCommand.h"
#include "Expression.h"
#include "globals.h"
#include "VariablesSymbolTable.h"
#include <thread>
#include <iostream>
/*
 * The openServerCommand execute function make a listening server and wait to
 * client connection.
 */
void OpenServerCommand::execute(vector<string> params) {
    //calculating port
    Expression* portExpression = nullptr;
    int port;

    try {
        portExpression = globalInterpreter->interpret(params.front());
        port = portExpression->calculate();
        delete portExpression;
        //delete globalInterpreter;
    } catch (const char* e) {
        if (portExpression != nullptr) {
            delete portExpression;
        }
        if (globalInterpreter != nullptr) {
            delete globalInterpreter;
        }
        std::cout << e << std::endl;
    }
    // the port parameter have to be const.
    const int PORT = port;
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        //return -1;
        throw "-1";
    }
    //bind socket to IP sim
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    //we need to convert our number
    // to a number that the network understands.
    address.sin_port = htons(PORT);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        //return -2;
        throw "-2";
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        //return -3;
        throw "-3";
    } else{
        //std::cout<<"Server is now listening ..."<<std::endl;
    }
    int addrlen = sizeof(address);

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&addrlen);

    //cout << "server is now Connected" << endl;

    if (client_socket == -1) {
        std::cerr<<"Error accepting client"<<std::endl;
        //return -4;
        throw "-4";
    }

    close(socketfd); //closing the listening socket
    //creating a thread
    thread threadServer(receiveData, client_socket);
    threadServer.detach();


}

/*
 * receive data function run a background thread that gets a data from
 * the client while keepRun global is true.
 */
void OpenServerCommand::receiveData(int client_socket) {
    //initial local variables.
    char dataFromServer[1024] = {0};
    int valread;
    int index = 0;
    char* token;
    Var* tempVar = nullptr;

    while(keepRun) {
        index = 0;
        //get data from client.
        valread = read(client_socket , dataFromServer, 1024);
        token = strtok(dataFromServer , ",");

        while(token!=NULL) {
            //get current var need to update.
            tempVar = VariablesSymbolTable::getInstance().simVarMap
            [VariablesSymbolTable::getInstance().indexSimMap[index]];
            if(tempVar != nullptr) {
                //check if this input var that should be updated.
                if(tempVar->getType() == Var::VarType::InputVar) {
                    //update tempVar value.
                    tempVar->update(stod(token));
                }
            }
            token = strtok(NULL , ",");
            index += 1;
        }
        //sleep for a bit to make other threads run
        sleep(0.01);
    }
}
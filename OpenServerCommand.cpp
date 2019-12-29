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

void OpenServerCommand::execute(vector<string> params) {
   cout << "parser testing";
    Expression* portExpression = nullptr;
    int port;

    try {
        portExpression = globalInterpreter->interpret(params.front());
        //std::cout << "Connect port as client: " << portExpression->calculate() << std::endl;
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
    const int PORT = port;
    std::cout << PORT << std::endl;
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        //return -1;
        throw "-1";
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(PORT);
    //we need to convert our number
    // to a number that the network understands.
    //close(socketfd); //closing the listening socket
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
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    int addrlen = sizeof(address);

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&addrlen);

    cout << "server is now Connected" << endl;

    if (client_socket == -1) {
        std::cerr<<"Error accepting client"<<std::endl;
        //return -4;
        throw "-4";
    }

    close(socketfd); //closing the listening socket

    thread threadServer(receiveData, client_socket);
    threadServer.detach();

    //todo check if no needed and delete
    //char buffer[1024] = {0};
    //int valread = read( client_socket , buffer, 1024);
    //std::cout<<buffer<<std::endl;
    ////writing back to client
    //char *hello = "Hello, I can hear you! \n";
    //send(client_socket , hello , strlen(hello) , 0 );
    //std::cout<<"Hello message sent\n"<<std::endl;
//
}

void OpenServerCommand::receiveData(int client_socket) {
    //initial local variables.
    char buffer[1024] = {0};
    int valread;
    int index = 0;
    char* token;
    Var* tempVar = nullptr;
    while(keepRun) {
        index = 0;
        //get data from client.
        valread = read( client_socket , buffer, 1024);
        //std::cout<<buffer<<std::endl;
        token = strtok(buffer , ",");
        while(token!=NULL) {
            //cout << token << endl;
            //check if the Var we get is not nullptr.
            tempVar = VariablesSymbolTable::getInstance().simVarMap
            [VariablesSymbolTable::getInstance().indexSimMap[index]];
            if(tempVar != nullptr) {
                //check if this input var that should be updated.
                if(tempVar->getType() == Var::VarType::InputVar) {
                    //update tempVar value.
                    tempVar->update(stod(token));
                    cout << index << " : " << tempVar->getValue() << endl;
                }
            }
            token = strtok(NULL , ",");
            index += 1;
        }
        //todo check if need this
        sleep(0.5);
    }
}



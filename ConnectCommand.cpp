//
// Created by roei on 18/12/2019.
//

#include "ConnectCommand.h"
#include "Expression.h"
#include "globals.h"
#include "Var.h"
#include "VariablesSymbolTable.h"

void ConnectCommand::execute(vector<string> v) {
    Expression* portExpression = nullptr;
    int port;

    try {
        portExpression = globalInterpreter->interpret(v[1]);
        std::cout << "Connect port as client: " << portExpression->calculate() << std::endl;
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
    //todo delete this
    std::cout << port << std::endl;
    //create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        throw "-1";
        //return -1;
    }
    //convert string to char*
    int length = v[0].length();
    char ip[length+1];
    strcpy(ip, v[0].c_str());
    //fix port to the right type

    //we create sockaddr obj to hold sim of server
    sockaddr_in address; //means IP4
    address.sin_family = AF_INET;// IP4
    address.sin_addr.s_addr = inet_addr(ip); // the IP address we get as argument
    address.sin_port = htons(port);


    //requesting a connection with the server on local
    int is_connect = connect(clientSocket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        cerr << "Could not connect to host server" << endl;
        throw "-2";
        //return  -2;
    } else {
        cout << "Client is now connected to server" << endl;
    }

    thread clientServer(sendData, clientSocket);
    clientServer.detach();

    //if we get here we made a connection
    sleep(1);

    //char buffer[1024] = {0};
    //int valread = read (clientSocket,buffer,1024);
    //cout << buffer << endl;

    //close(clientSocket);
    //todo: remove me
    //char h[] = "set controls/flight/rudder -1\r\n";
//
    //int is_sent = send(clientSocket, h , strlen(h), 0);
    //if (is_sent == -1) {
    //    cout << "Error sending msg" << endl;
    //} else {
    //    cout<< "Hello msg sent to server" <<endl;
    //}
    //throw "0";
    //return 0;
}
void ConnectCommand::sendData(int clientSocket) {
    char buffer[1024] = {0};
    string sim;
    //todo
    while(keepRun) {
        for(auto pair : VariablesSymbolTable::getInstance().getVariablesMap()) {
            //check if this var already is not initial
            if(pair.second->getType() == Var::VarType::OutputVar
            && !isnan(pair.second->getValue())) {
                //preparing the string for sending
                sim = "set ";
                sim.append(pair.second->getSim());
                sim.append(" ");

                sim.append(to_string(pair.second->getValue()));
                sim.append("\r\n");
                char h[sim.length()+1];
                strcpy(h,sim.c_str());
                //convert string to char array.
                //strcpy(buffer, sim.c_str());
                //cout << buffer << endl;
                //sending the command to the server.
                int is_sent = send(clientSocket, h , strlen(h), 0);
                if (is_sent == -1) {
                    cout << "Error sending msg" << endl;
                } else {
                    cout<< pair.first << pair.second->getValue() <<endl;
                }
            }
        }
        //cout << "we are in thread"<< endl;
        //todo check if need this
        sleep(1);
    }
    close(clientSocket);
}

//
// Created by roei on 18/12/2019.
//

#include "ConnectCommand.h"
int ConnectCommand::execute(vector<string> v) {

    //create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        return -1;
    }
    //convert string to char*
    int length = v[0].length();
    char c[length+1];
    strcpy(c, v[0].c_str());
    //fix port to the right type
    int a = stoi(v[1]);
    //we create sockaddr oj to hold address of server
    sockaddr_in address; //means IP4
    address.sin_family = AF_INET;// IP4
    address.sin_addr.s_addr = inet_addr(c); // the IP address we get as argument
    address.sin_port = htons(a);


    //requesting a connection with the server on local
    //todo make it a thread with join after.
    int is_connect = connect(clientSocket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        cerr << "Could not connect to host server" << endl;
        return  -2;
    } else {
        cout << "Client is now connected to server" << endl;
    }

    //if we get here we made a connection
    sleep(1);
    const char h[] = "set controls/flight/rudder -1\r\n";

    int is_sent = send(clientSocket, h , strlen(h), 0);
    if (is_sent == -1) {
        cout << "Error sending msg" << endl;
    } else {
        cout<< "Hello msg sent to server" <<endl;
    }
    char buffer[1024] = {0};
    int valread = read (clientSocket,buffer,1024);
    cout << buffer << endl;

    close(clientSocket);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <iostream>
#include "OpenServerCommand.h"
#include "Utils.h"
#include "ThreadData.h"

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

static void* OpenServer(void *threadarg){
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[20000];
    ThreadData* data = (ThreadData*)threadarg;

    cout<<"port: "<<data->getIntArg1()<<", rate: "<<data->getIntArg2()<<endl;

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(data->getIntArg1());

    //Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        //print the error message
        perror("bind failed. Error");
    }
    puts("bind done");

    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c);
    if (client_sock < 0) {
        perror("accept failed");
    }
    puts("Connection accepted");


    int numMsg = 1;
    //Receive a message from client
    while ((read_size = recv(client_sock, client_message, 20000, 0)) > 0) {
        usleep(data->getIntArg2());
        //Send the message back to client
        //write(client_sock , client_message , strlen(client_message));
        //cout << numMsg++ << ": " << client_message << endl;
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    delete data;
    pthread_exit(NULL);
}


void OpenServerCommand::doCommand() {
    auto * thread = new pthread_t;
    auto * data = new ThreadData();
    data->setIntArg1(this->port);
    data->setIntArg2(this->rate);

    pthread_create(thread, NULL, OpenServer, data);

    this->threads->addThread(thread);
}

OpenServerCommand::OpenServerCommand(vector<string> &code, map<string, VarData *> *symTbl, Threads *threads) {
    Utils utils;
    list<string> portList;
    list<string> rateList;

    int index = 1;
    portList.push_back(code[index]);
    index++;
    while (code[index]=="+"||code[index]=="-"||code[index]=="*"||code[index]=="/"){//TODO is op
        portList.push_back(code[index]);
        index++;
        portList.push_back(code[index]);
        index++;
    }

    rateList.push_back(code[index]);
    index++;
    while (index<code.size() &&code[index]!=";"){
        rateList.push_back(code[index]);
        index++;
        rateList.push_back(code[index]);
        index++;
    }

    this->port= utils.evaluate(portList, symTbl)->calculate();
    this->rate= utils.evaluate(rateList, symTbl)->calculate();
    this->symTbl=symTbl;
    this->threads=threads;
}
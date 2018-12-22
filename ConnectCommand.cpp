
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <iostream>
#include <thread>

#include "ConnectCommand.h"
#include "Utils.h"

void Connect(int port, char* ip){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

//    if (argc < 3) {
//        fprintf(stderr,"usage %s hostname port\n", argv[0]);
//        exit(0);
//    }
//
//    portno = atoi(argv[2]);

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    //TODO replace 127.0.0.1 with arg
    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */
    cout<<"Connected successfully...\nPlease enter the message: "<<endl;
    bzero(buffer,256);
    //fgets(buffer,255,stdin);
    strcpy(buffer,"get /instrumentation/altimeter/indicated-altitude-ft");

    /* Send message to the server */
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);

    cout<<n<<endl;

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
}

void ConnectCommand::doCommand() {
    this->threads->addThread(new thread(Connect, this->port, this->ip));
}

ConnectCommand::ConnectCommand(vector <string> &code, map<string, VarData *> *symTbl, Threads* threads) {
    Utils utils;
    list<string> portList;

    int index = 1;

    // need to delete
//    this->ip = new char[code[index].size() + 1];
//    memcpy(this->ip, code[index].c_str(), code[index].size() + 1);

    index++;
    portList.push_back(code[index]);
    index++;
    while (index<code.size() &&code[index]!=";"){//TODO is op
        portList.push_back(code[index]);
        index++;
        portList.push_back(code[index]);
        index++;
    }

    this->port=utils.evaluate(portList, symTbl)->calculate();
    this->threads=threads;
}

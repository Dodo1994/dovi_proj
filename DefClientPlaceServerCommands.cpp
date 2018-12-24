

#include "DefClientPlaceServerCommands.h"

bool isClientSend = false;
string clientPath;
int clientValue;

void Connect(int port, char* ip){
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // display ip and port to connect
    cout<<"try to connect to: "<<ip<<", "<<port<<""<<endl;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(ip);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    cout<<"Connected successfully..."<<endl;

    while (true) {
        if(isClientSend) {
            //TODO
            cout<<"ALIVE!!!"<<endl;
            bzero(buffer, 256);
            string msg;
            // syntax: "set /instrumentation/attitude-indicator/internal-pitch-deg 10000\r\n"
            msg = "set " + clientPath + " " + to_string(clientValue) + "\r\n";
            for (int i = 0; i < msg.size(); i++) {
                buffer[i] = msg[i];
            }
            n = write(sockfd, buffer, msg.size());

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            memset(buffer, 0, 256);

            isClientSend = false;
        }
    }
}

void ConnectCommand::doCommand() {
    this->threads->addThread(new thread(Connect, this->port, this->ip));
}

ConnectCommand::ConnectCommand(vector <string> &code, map<string, VarData *> *symTbl, Threads* threads) {
    Utils utils;
    int index = 1;

    // ip
    memset(this->ip, 0, 39);
    for(int i=0;i<code[index].size();i++){
        this->ip[i]=code[index][i];
    }

    // port expression
    list<string> portList;
    index++;
    portList.push_back(code[index]);
    index++;
    while (index < code.size() && code[index]!=";") {
        portList.push_back(code[index]);
        index++;
    }
    this->port=utils.evaluate(portList, symTbl);

    // threads collection
    this->threads=threads;
}

void updateVars(string path, double val, map<string, VarData*> *symTbl){
    for(auto &var: *symTbl){
        if(var.second->getPath()==path) {
            var.second->setValue(val);
        }
    }
}

void OpenServer(map<string, VarData*> *symTbl, int port, int rate) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[20000];
    vector<string> names = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                            "/instrumentation/altimeter/indicated-altitude-ft",
                            "/instrumentation/altimeter/pressure-alt-ft",
                            "/instrumentation/attitude-indicator/indicated-pitch-deg",
                            "/instrumentation/attitude-indicator/indicated-roll-deg",
                            "/instrumentation/attitude-indicator/internal-pitch-deg",
                            "/instrumentation/attitude-indicator/internal-roll-deg",
                            "/instrumentation/encoder/indicated-altitude-ft",
                            "/instrumentation/encoder/pressure-alt-ft",
                            "/instrumentation/gps/indicated-altitude-ft",
                            "/instrumentation/gps/indicated-ground-speed-kt",
                            "/instrumentation/gps/indicated-vertical-speed",
                            "/instrumentation/heading-indicator/indicated-heading-deg",
                            "/instrumentation/magnetic-compass/indicated-heading-deg",
                            "/instrumentation/slip-skid-ball/indicated-slip-skid",
                            "/instrumentation/turn-indicator/indicated-turn-rate",
                            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                            "/controls/flight/aileron",
                            "/controls/flight/elevator",
                            "/controls/flight/rudder",
                            "/controls/flight/flaps",
                            "/controls/engines/engine/throttle",
                            "/engines/engine/rpm"};

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    //Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        //print the error message
        perror("bind failed. Error");
    }
    puts("bind done");

    //Listen
    listen(socket_desc, rate);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c);
    if (client_sock < 0) {
        perror("accept failed");
    }
    puts("Connection accepted");

    //Receive a message from client
    while ((read_size = recv(client_sock, client_message, 20000, 0)) > 0) {
        string segment;
        vector<string> seglist;
        for (char c:client_message) {
            if ((c != ',') && (c != '\n')) {
                segment += c;
            } else {
                seglist.push_back(segment);
                segment = "";
            }
        }
        for (int i = 0; i < names.size(); ++i) {
            cout<<seglist[i]<<endl;//TODO
            updateVars(names[i], stod(seglist[i]), symTbl);
        }
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }
}

void OpenServerCommand::doCommand() {
    this->threads->addThread(new thread(OpenServer, this->symTbl, this->port, this->rate));
}

OpenServerCommand::OpenServerCommand(vector<string> &code, map<string, VarData *> *symTbl, Threads* threads) {
    int index = 1;
    Utils utils;
    list<string> portList;
    list<string> rateList;
    bool isLastOp = true;;

    // port expression until 2 numbers
    while (isLastOp || utils.isOperator(code[index]) || code[index] == "(" || code[index] == ")") {
        portList.push_back(code[index]);
        isLastOp = (utils.isOperator(code[index]) || code[index] == "(" || code[index] == ")");
        index++;
    }

    // rate expression until end
    while (index < code.size() && code[index] != ";") {
        rateList.push_back(code[index]);
        index++;
    }

    this->port = static_cast<int>(utils.evaluate(portList, symTbl));
    this->rate = static_cast<int>(utils.evaluate(rateList, symTbl));
    this->symTbl = symTbl;
    this->threads = threads;
}

void DefineVarCommand::doCommand() {}

DefineVarCommand::DefineVarCommand(vector<string> &code, map<string, VarData *> *symTbl) {
    Utils utils;
    string path;
    double value;
    // name is second word
    string name = code[1];

    if (code[3] == "bind") {
        // case var x = bind "/bla/bla"
        if (code[4][0] == '"') {
            path = utils.removeApostrophes(code[4]);
            value = 0;
            // case var x = bind y
        } else {
            path = symTbl->at(code[4])->getPath();
            value = symTbl->at(code[4])->getValue();
        }
    } else {
        // '/' because not bind
        path = "/";
        // case var x = y
        if (symTbl->count(code[3])) {
            value = symTbl->at(code[3])->getValue();
            // case var x = 5
        } else {
            list<string> expList;
            // expression is after =
            expList.push_back(code[3]);
            int index = 4;
            while (index < code.size() && code[index] != ";") {
                expList.push_back(code[index]);
                index++;
            }
            value = utils.evaluate(expList, symTbl);
        }
    }
    // insert to symTbl the name, value and path
    symTbl->insert(pair<string, VarData *>(name, new VarData(value, path)));

    // client details
    clientPath = path;
    clientValue = static_cast<int>(value);
    isClientSend = true;
}

void PlacementCommand::doCommand() {
    Utils utils;
    double value = utils.evaluate(this->right,this->symTbl);
    this->symTbl->at(this->left)->setValue(value);

    // client details
    clientPath = this->symTbl->at(this->left)->getPath();
    clientValue = static_cast<int>(value);
    isClientSend = true;
}

PlacementCommand::PlacementCommand(vector<string> &code, map<string, VarData *> *symTbl) {
    int index = 1;

    // left is before =
    this->left = code[index - 1];

    // right expression is after =
    ++index;
    while (index < code.size()) {
        this->right.push_back(code[index]);
        ++index;
    }

    // init symTbl
    this->symTbl = symTbl;
}



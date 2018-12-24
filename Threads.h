//
// Created by ori on 12/20/18.
//

#ifndef ORI_LEXER_THREADS_H
#define ORI_LEXER_THREADS_H

using namespace std;

#include <thread>
#include <sys/types.h>
#include <vector>

class Threads {
    vector<thread*> threads;

public:
    void addThread(thread* t);
    ~Threads();


};


#endif //ORI_LEXER_THREADS_H

#ifndef ORI_LEXER_THREADS_H
#define ORI_LEXER_THREADS_H


#include <thread>
#include <sys/types.h>
#include <vector>

using namespace std;

class Threads {
    vector<thread*> threads;

public:
    void addThread(thread* t);
    ~Threads();
};

#endif
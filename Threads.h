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

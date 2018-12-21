using namespace std;

#include <vector>
#include <string>

class Command {
public:
    // the return value, according eli, is the index jump for this command
    // for example, for: var ori = "student" index+=4
    virtual void doCommand()=0;
};
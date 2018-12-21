using namespace std;

#include <string>
#include <list>
#include <vector>

class ReadCode {

public:
    void readFromFile(string fileName);
    void readFromConsole();
private:
    void displayLexerResult(vector<string> l);
};

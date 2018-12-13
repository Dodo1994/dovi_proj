
#include "interpreter.h"

list <string> interpreter::lexer(string input) {
    int i = 0;
    string word;
    bool isFirstSpace = true;
    list<string> words;

    // pass over input
    while (i < input.size()) {
        // pass over spaces
        while (is_space(input[i]) && i < input.size()) {
            // if first space after word
            if(isFirstSpace) {
                isFirstSpace = false;
                // add word and init word
                words.push_back(word);
                word = "";
            }
            ++i;
        }
        // add char to word
        word+=input[i];
        // init first space
        isFirstSpace = true;
        ++i;
    }
    // add last word
    words.push_back(word);

    return words;
}

void interpreter::parser() {

}

bool interpreter::is_space(char c) {
    return (c == ' ' || c == '\t'); //‫‪ c == '\n' not space, to mark new line
}


#include "Lexer.h"

bool Lexer::is_space(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

list <string> Lexer::string_to_list(string input) {
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
                word="";
            }
            ++i;
        }
        // add char to word
        word+=input[i];
        // init first space
        isFirstSpace = true;
        ++i;
    }

    return words;
}


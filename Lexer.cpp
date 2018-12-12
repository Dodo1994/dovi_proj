//
// Created by ori on 12/12/18.
//

#include <iostream>
#include "Lexer.h"

bool is_space(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

list <string> Lexer::string_to_list(string input) {
    list<string> words;

    int i = 0;
    string word;
    bool isFirstSpace = true;

    while (i < input.size()) {
        // pass over spaces
        while (is_space(input[i]) && i < input.size()) {

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

        isFirstSpace= true;

        ++i;
    }

    return words;
}


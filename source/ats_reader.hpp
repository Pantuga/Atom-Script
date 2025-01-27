#pragma once

#include "iostream"
#include "string"
#include "vector"
#include "array"
#include "ctype.h" // isspace() function
#include "ats_interpreter.hpp"

using namespace std;

int atomicNum(string input) {
    for (int i = 0; i < elements.size(); i++) {
        if (input == elements[i]) return i;
    }
    cout << "Syntax Error: " << input << " is not an element from the periodic table. Please check your spelling\n";
    return -1;
}

const string nums = "0123456789";
bool isnum(char ch) {
    if (nums.find(ch) != string::npos) return true;
    else return false;
}
int chartonum(char ch) {
    for (int i = 0; i < nums.size(); i++) {
        if (ch == nums[i]) return i;
    }
    cout << "Unexpected Error: May cause weird behavior";
    return 0;
}
vector<int> read(string input) { // This entire function was made by chat gpt, and yet it does not work as I first inteded. As they say in portuguese, quem não tem cão caça com gato.
    vector<int> output;       // Holds the atomic numbers of elements
    string buffer;            // Holds the current element symbol
    bool isComment = false;   // Tracks if the current line is a comment
    int tokenMult = 1;        // Default multiplier for elements is 1

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '#') { // Start of a comment
            isComment = true;
        }

        if (!isComment) {
            if (isnum(input[i])) { // Detect a number prefix
                if (tokenMult == 1) tokenMult = 0; // Reset multiplier when starting a new number
                tokenMult = tokenMult * 10 + chartonum(input[i]); // Build the multiplier
            } else if (isupper(input[i])) { // Start of an element symbol
                // Process the previous element, applying the multiplier
                if (!buffer.empty()) {
                    int elementNum = atomicNum(buffer);
                    if (elementNum != -1) {
                        for (int j = 0; j < tokenMult; j++) {
                            output.push_back(elementNum);
                        }
                    }
                    tokenMult = 1; // Reset multiplier after applying
                }
                buffer = input[i]; // Start a new element symbol
            } else if (islower(input[i])) { // Continue building the element symbol
                buffer += input[i];
            }
        }

        if (input[i] == '\n') { // End of a comment
            isComment = false;
        }
    }

    // Process the last element in the buffer
    if (!buffer.empty()) {
        int elementNum = atomicNum(buffer);
        if (elementNum != -1) {
            for (int j = 0; j < tokenMult; j++) {
                output.push_back(elementNum);
            }
        }
    }

    return output;
}

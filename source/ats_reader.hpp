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

vector<int> read(string input) {
    vector<int> output;
    string buffer;
    bool isComment = false;
    int tokenMult = 1;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '#') isComment = true;

        if (!isComment) {
            if (isupper(input[i]) && buffer != "") {
                for (int i = 0; i < tokenMult; i++) {
                    output.push_back(atomicNum(buffer));
                }
                tokenMult = 1;
                buffer = "";
                buffer += input[i];
            } else if (!isspace(input[i])) {
                if (isnum(input[i]) && buffer != "") {
                    for (int i = 0; i < tokenMult; i++) {
                        output.push_back(atomicNum(buffer));
                    }
                    buffer = "";
                    if (tokenMult != 1) {
                        tokenMult *= 10;
                        tokenMult += chartonum(input[i]);
                    } else {
                        tokenMult = chartonum(input[i]);
                    }
                } else buffer += input[i];
            }
        } else if (isComment && input[i] == '\n') isComment = false;
    }
    for (int i = 0; i < tokenMult; i++) {
        output.push_back(atomicNum(buffer));
    }
    for (int i; i < output.size(); i++) if (output[i] == -1) return {-1};
    return output;
}
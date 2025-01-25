#pragma once

#include "iostream"
#include "vector"
#include "array"
#include "elements.hpp"
using namespace std;

int execute(vector<int> program) {
    // where variables are stored
    vector<int> numMemory = {0};
    vector<bool> boolMemory = {false};
    vector<string> strMemory = {""};
    // position of the vectors to be read
    int pointer = 0;
    int intPrivateMemory;
    string strPrivateMemory;
    

    const int READ_DEFAULT = -1;
    int readMode = READ_DEFAULT; // -1 is default
    for (int i = 0; i < program.size(); i++) {
        switch (readMode) {
        case READ_DEFAULT:
            switch (program[i]) { // Other syntax errors are handeled by the reader

            case H: // adds numMemory to strMemory as a character
                strMemory[pointer] += (char)numMemory[pointer];
                break;

            case He: //() sets numMemory to the value inside
                numMemory[pointer] = 0;
                readMode = He;
                break;
            
            case Ne: //() "He [...] He H" withput altering numMemory
                intPrivateMemory = numMemory[pointer];
                readMode = Ne;
                break;

            case Li: // increments pointer by 1
                pointer += 1;
                break;

            case Be: // decrements pointer by 1
                pointer -= 1;
                break;

            case Na: //() sets pointer to the value inside
                pointer = 0;
                readMode = Na;
                break;

            case Mg: // sets pointer to 0
                pointer = 0;
                break;

            case K: //() increments pointer by value inside
                intPrivateMemory = pointer;
                readMode = K;
                break;

            case Ca: //() decrements pointer by value inside
                intPrivateMemory = pointer;
                readMode = Ca;
                break;

            case C: // prints strMemory
                cout << strMemory[pointer];
                break;
            
            case F: // v0.0.3 resets the strMemory
                strMemory[pointer] = "";
                break;

            case B: // v0.0.3 asks for bool input
                cin >> strPrivateMemory;

                if (strPrivateMemory[0] == 'n' || strPrivateMemory == "false" || strPrivateMemory == "0") {
                    boolMemory[pointer] = false;
                } else boolMemory[pointer] = true;
                break;

            case N: // v0.0.3 asks for int input (DANGEROUS!!!)
                cin >> numMemory[pointer];
                break;

            case O: // asks for string input (works weird)
                cin >> strMemory[pointer];
                break;

            default:
                cout << "\n Syntax Error: The element " << program[i] << " is unused";
                return -2;
                break;
            }
            break;

        case He:
            if (program[i] != He) {
                numMemory[pointer] += program[i];
            } else if (numMemory[pointer] != 0) {
                readMode = READ_DEFAULT;
            }
            break;

        case Ne:
            if (program[i] != Ne) {
                numMemory[pointer] = program[i];
            }
            if (numMemory[pointer] != intPrivateMemory) {
                strMemory[pointer] += (char)numMemory[pointer];
                numMemory[pointer] = intPrivateMemory;
                readMode = READ_DEFAULT;
            }
            break;

        case Na:
            if (program[i] != Na) {
                pointer = program[i];
            }
            if (pointer != 0) {
                readMode = READ_DEFAULT;
            }
            break;

        case K:
            if (program[i] != K) {
                pointer += program[i];
            } else if (pointer != intPrivateMemory) {
                readMode = READ_DEFAULT;
            }
            break;

        case Ca:
            if (program[i] != Ca) {
                pointer -= program[i];
            } else if (pointer != intPrivateMemory) {
                readMode = READ_DEFAULT;
            }
            break;
        default:
            cout << "Code Error: " << readMode << endl << "Please report to github";
        }
        if (pointer > numMemory.size() - 1) {
            for (int i = numMemory.size() - 1; i <= pointer; i++)
                numMemory.push_back(0);
                boolMemory.push_back(false);
                strMemory.push_back("");
        }
    }
    return 0;
}
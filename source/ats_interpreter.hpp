#pragma once

#include "iostream"
#include "vector"
#include "elements.hpp" // enum with all the elements
using namespace std;

int execute(vector<int> program) {
    // where variables are stored
    vector<int> numMemory = {0};
    vector<bool> boolMemory = {false};
    vector<string> strMemory = {""};
    vector<vector<int>> funcMemory = {{}};
    // position of the vectors to be read
    int pointer = 0;
    int intPrivateMemory;
    string strPrivateMemory;

    const int READ_DEFAULT = -1;
    int readMode = READ_DEFAULT; // -1 is default
    for (int i = 0; i < program.size(); i++) {
        switch (readMode) {
        case READ_DEFAULT:
            switch (program[i]) { // "//()" means the commands works by enclosing other elements (eg.: He [...] He)

            case H: // adds numMemory to strMemory as a character
                strMemory[pointer] += (char)numMemory[pointer];
                break;

            case He: //() sets numMemory to the value inside
                numMemory[pointer] = 0;
                readMode = He;
                break;
            
            case Ne: // "He [...] He H" withput altering numMemory, uses next value (eg.: "He Bk He H" = "Ne Bk")
                intPrivateMemory = numMemory[pointer];
                readMode = Ne;
                break;

            case Li: // increments pointer by 1
                pointer += 1;
                break;

            case Be: // decrements pointer by 1
                pointer -= 1;
                break;

            case Na: // sets pointer to the next value
                pointer = 0;
                readMode = Na;
                break;

            case Mg: // sets pointer to 0
                pointer = 0;
                break;

            case K: //() increments numMemory[pointer] by number inside
                intPrivateMemory = 0;
                readMode = K;
                break;

            case Ca: //() decrements numMemory[pointer] by number inside
                intPrivateMemory = 0;
                readMode = Ca;
                break;

            case C: // prints strMemory
                cout << strMemory[pointer];
                break;
            
            case F: // v0.0.3 resets the strMemory
                strMemory[pointer] = "";
                break;
            
            case Cl: // v0.1 reset the numMemory
                numMemory[pointer] = 0;
                break;

            case B: // v0.0.3 asks for bool input
                cin >> strPrivateMemory;

                if (strPrivateMemory[0] == 'n' || strPrivateMemory == "false" || strPrivateMemory == "0") {
                    boolMemory[pointer] = false;
                } else boolMemory[pointer] = true;
                break;

            case N: // v0.0.3 asks for int input (DANGEROUS IF USER INPUT IS BAD!!!)
                cin >> strPrivateMemory;
                numMemory[pointer] = stoi(strPrivateMemory);
                break;

            case O: // asks for string input
                cin >> strMemory[pointer];
                break;
            
            case Fe: //() v0.1 saves the code inside in funcMemory
                funcMemory[pointer] = {};
                readMode = Fe;
                break;
            
            case Cu: // v0.1 executes the code in funcMemory
                execute(funcMemory[pointer]);
                break;

            case 0:
                cout << "Error: Program Empty\n";
                return 404;
                break;
            case -1:
                return 13;
                break;
            default:  // Other syntax errors are handeled in reader.hpp
                cout << "Syntax Error: The element " << program[i] << " is unused\n";
                return 22;
                break;
            }
            break;
//------------------------------------------------------------------------------------------------------------
        case He:
            if (program[i] != He) {
                numMemory[pointer] += program[i];
            } else {
                readMode = READ_DEFAULT;
            }
            break;

        case Ne:
            numMemory[pointer] = program[i];

            switch (numMemory[pointer]) {
                case H:
                    numMemory[pointer] = (int)' ';
                    break;
                case He:
                    numMemory[pointer] = (int)'\n';
                    break;
            }
            strMemory[pointer] += (char)numMemory[pointer];
            numMemory[pointer] = intPrivateMemory;
            readMode = READ_DEFAULT;
            
            break;

        case Na:
            pointer = program[i];
            readMode = READ_DEFAULT;
            break;

        case K:
            if (program[i] != K) {
                numMemory[pointer] += program[i];
            } else {
                readMode = READ_DEFAULT;
            }
            break;

        case Ca:
            if (program[i] != Ca) {
                numMemory[pointer] -= program[i];
            } else {
                readMode = READ_DEFAULT;
            }
            break;
        
        case Fe:
            if (program[i] != Fe) {
                funcMemory[pointer].push_back(program[i]);
            } else {
                readMode = READ_DEFAULT;
            }
            break;

        default:
            cout << "Code Error: Please report to github";
            return -readMode;
            break;
        }
        if (pointer >= numMemory.size() - 1) {
            for (int i = numMemory.size() - 1; i < pointer; i++)
                numMemory.push_back(0);
                boolMemory.push_back(false);
                strMemory.push_back("");
                funcMemory.push_back({});
        }
    }
    return 0;
}
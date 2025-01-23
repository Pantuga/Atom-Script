#include "iostream"
#include "string"
#include "vector"
#include "array"
#include "ctype.h" // isspace() function
#include "fstream" // for file reading
#include "sstream" // "
#include "ats_interpreter.h"
using namespace std;

int atomicNum(string input) {
    for (int i = 0; i < elements.size(); i++) {
        if (input == elements[i]) return i;
    }
    return -1;
}

vector<int> read(string input) {
    vector<int> output;
    string buffer;
    bool isComment = false;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '#') isComment = true;

        if (!isComment) {
            if (isupper(input[i]) && buffer != "") {
                output.push_back(atomicNum(buffer));
                buffer = "";
                buffer += input[i];
            } else if (!isspace(input[i])) {
                buffer += input[i];
            }
        } else if (input[i] == '\n') isComment = false;
    }
    output.push_back(atomicNum(buffer));
    return output;
}

int main() {
    string filename;
    cout << "File Name: ";
    cin >> filename;

    if (filename == "-") filename = "prog.ats";
    if (filename.find('.') == string::npos) filename += ".ats";

    ifstream file(filename.c_str());  // Open the file
    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    stringstream buffer;
    buffer << file.rdbuf();  // Read the whole file content into a stringstream
    string input = buffer.str();  // Get the string content
    file.close();  // Close the file

    vector<int> code = read(input);
    for (int i = 0; i < code.size(); i++) {
        cout << code[i] << "; ";
    }
    cout << "\n--\n";
    executeProg(code);
    return 0;
}
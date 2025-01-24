#include "iostream"
#include "string"
#include "vector"
#include "array"
#include "ctype.h" // isspace() function
#include "fstream" // for file reading
#include "sstream" // "
#include "ats_interpreter.h" // where the array "elements" is
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

string askFile() {
    string filename;
    cout << "File Name: ";
    cin >> filename;

    if (filename == "-") filename = "prog.ats";
    if (filename.find('.') == string::npos) filename += ".ats";

    ifstream file(filename.c_str());  // Open the file
    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
    }
    stringstream buffer;
    buffer << file.rdbuf();  // Read the whole file content into a stringstream
    string fileStr = buffer.str();  // Get the string content
    file.close();  // Close the file

    cout << endl;
    return fileStr;
}

void exeFile() {
    int out = execute(read(askFile()));
    if (out == 0) cout << "\n\nProgram executed successfully";
    else cout << "\nProgram ended with error " << out;
}

int main() {
    exeFile();

    bool quit = false;
    while (!quit) {
        cout << "\nType \"run\" to run a program, anything else to quit\n";
        string in;
        cin >> in;

        if (in == "run") exeFile();
        else quit = true;
    }
    return 0;
}
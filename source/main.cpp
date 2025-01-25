#include "iostream"
#include "string"
#include "vector"
#include "array"
#include "ctype.h" // isspace() function
#include "fstream" // for file reading
#include "sstream" // "
#include "ats_interpreter.hpp"
#include "ats_reader.hpp"
using namespace std;

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(STDIN_FILENO, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(STDIN_FILENO, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(STDIN_FILENO, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
#endif

string askFile(string infilename = "") {
    string filename;
    if (infilename == "") {
        cout << "File Name: ";
        cin >> filename;
    } else filename = infilename;

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

void exeFile(string filename = "") {
    int out = execute(read(askFile(filename)));
    
    if (out == 0) cout << "\n\nProgram executed successfully.";
    else cout << "\nProgram ended with error: " << out;
}

int main(int argc, char* argv[]) {

    // Get the file path from the command-line argument
    if (argc < 2) {
        exeFile();
    } else {
        exeFile(argv[1]);
    }

    getch();
    return 0;
}
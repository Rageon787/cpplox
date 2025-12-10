#include <iostream>
using namespace std;

class Lox {

public:

    static void run_file() {
        cout <<  "Interpreter will be run on a file\n";
    }

    static void run_prompt() {
        while (true) {
            cout << "> ";
            string prompt;
            getline(cin, prompt);
            cout << prompt << endl;
        }

    }
};

int main(int argc, char* argv[]) {

    Lox lox;

    if (argc == 1) {
        // no arguments are present: REPL Mode
        lox.run_prompt();
    } else if (argc == 2) {
        // If there is only one argument: run file
        lox.run_file();
    } else {
        // if there is more than one arg: Exit
    }


}

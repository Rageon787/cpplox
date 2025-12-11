#include<iostream>
#include<filesystem>
#include<fstream>
#include<vector>
#include<string>
namespace fs = std::filesystem;


class Lox {

private:
public:
    static std::vector<std::string> source; // store source code as a vector of strings

    static void run_file(const fs::path& given_path) {
        std::cout << given_path << std::endl;
        // File existence check
        if (fs::exists(given_path)) {
            // file exists: read the source from the file and proceed to scanning
            std::cout << "file exists" << std::endl;
            std::ifstream file_reader(given_path);

            // read the source code from the file
            std::string line;
            while (getline(file_reader, line)) {
                source.push_back(line);
            }


        } else {
            std::cout << "file doesn't exist" << std::endl;
            // File doesn't exist: throw an error to the user
        }
    }

    static void run_prompt() {
        while (true) {
            std::cout << "> ";
            std::string prompt;
            getline(std::cin, prompt);
            std::cout << prompt << std::endl;
            // TODO: need to scan this prompt and generate a series of tokens
        }
    }


};
std::vector<std::string> Lox::source;

int main(int argc, char* argv[]) {

    Lox lox = Lox();

    argc--; // decrement the program argument

    if (argc == 0) {
        // no arguments are present: Prompt Mode
        lox.run_prompt();
    } else if (argc == 1) {
        // If there is only one argument: File mode
        lox.run_file(argv[1]);
    } else {
        // if there is more than one arg: Exit
    }


}

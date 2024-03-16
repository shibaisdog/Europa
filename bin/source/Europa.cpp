#include "VM/header/controller.h"
#include "File/header/Windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

void runing(std::string filename) {
    std::regex pattern("/");
    std::string aname = std::regex_replace(filename, pattern, "\\\\");
    std::ifstream f = open_window(aname);
    if (f.is_open()) {
        std::string line;
        while (std::getline(f,line)) {
            controller(line);
        }
        f.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        if (i != 0) {
            runing(argv[i]);
        }
    }
    return 0;
}
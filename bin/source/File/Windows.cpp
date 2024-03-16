#include "header/Windows.h"

std::ifstream open_window(std::string Filename) {
    std::ifstream File(Filename);
    return File;
}
#ifndef onType_H
#define onType_H

#include <iostream>
#include <vector>
#include <stdexcept>

extern "C" {
    #include "Heap.h"
}

class Memory {
    public:
        static std::vector<std::vector<std::string>> Heap;
};

void set(std::string name, std::string type, void* value);
void del(std::string target);
std::string getType(std::string target);
void* getPtr(std::string target);

#endif /* onType_H */
#include "../header/onType.h"
#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<std::vector<std::string>> Memory::Heap;

void set(std::string name, std::string type, void* value) {
    c_set(const_cast<char*>(name.c_str()), value);
    for (auto& var : Memory::Heap) {
        if (var[0] == name) {
            var[1] = type;
            return;
        }
    }
    Memory::Heap.push_back({name, type});
}
void del(std::string target) {
    for (auto iter = Memory::Heap.begin(); iter != Memory::Heap.end(); ++iter) {
        if ((*iter)[0] == target) {
            c_del(const_cast<char*>(target.c_str()));
            Memory::Heap.erase(iter);
            return;
        }
    }
    throw std::runtime_error("Memory Reference Error: Variable not found");
}
std::string getType(std::string target) {
    for (const auto& var : Memory::Heap) {
        if (var[0] == target) {
            return var[1];
        }
    }
    return "";
}
void* getPtr(std::string target) {
    for (const auto& var : Memory::Heap) {
        if (var[0] == target) {
            return c_get(const_cast<char*>(target.c_str()));
        }
    }
    return nullptr;
}
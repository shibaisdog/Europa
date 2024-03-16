#include "../header/onType.h"
#include "../header/extract.h"
#include <iostream>
#include <sstream>
std::vector<std::string> extractStrings(const std::string& input) {
    std::vector<std::string> results;
    std::stringstream ss(input);
    std::string word;
    while (ss >> word) {
        if (word.size() > 1 && word[0] == '&' && isalpha(word[1])) {
            results.push_back(word.substr(1)); // '&' 제거 후 추가
        }
    }
    return results;
}
std::string extractValue(const std::string& input) {
    std::stringstream ss(input);
    std::string result;
    std::string word;
    while (ss >> word) {
        if (word.size() > 1 && word[0] == '&' && isalpha(word[1])) {
            std::string type = getType(word.substr(1));
            if (type.compare("bool") == 0) {
                bool* b = static_cast<bool*>(getPtr(word.substr(1)));
                result += std::to_string(*b);
            }  else if (type.compare("int") == 0) {
                int* i = static_cast<int*>(getPtr(word.substr(1)));
                result += std::to_string(*i);
            } else if (type.compare("float") == 0) {
                float* f = static_cast<float*>(getPtr(word.substr(1)));
                result += std::to_string(*f);
            } else if (type.compare("double") == 0) {
                double* d = static_cast<double*>(getPtr(word.substr(1)));
                result += std::to_string(*d);
            } else if (type.compare("str") == 0) {
                std::string* s = static_cast<std::string*>(getPtr(word.substr(1)));
                result += *s;
            } else if (type.compare("") || getPtr(word.substr(1)) == nullptr) {
                result += "null";
            } else {
                result += "null";
            }
        } else {
            result += word;
        }
        result += " ";
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}
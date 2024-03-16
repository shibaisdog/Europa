#include "header/variable.h"

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}
bool stringToBool(const std::string& str) {
    std::string lowerStr;
    for (char c : str) {
        lowerStr += std::tolower(c);
    }
    if (lowerStr == "true" || lowerStr == "1" || lowerStr == "yes" || lowerStr == "y") {
        return true;
    } else if (lowerStr == "false" || lowerStr == "0" || lowerStr == "no" || lowerStr == "n") {
        return false;
    }
    return false;
}
void _variable(std::string Line) {
    int index = Line.find_last_of("=");
    int types = Line.find(":");
    if (index != std::string::npos && types != std::string::npos) {
        std::string name = trim(Line.substr(0,types));
        if (name.empty()) {return;}
        std::string type = trim(Line.substr(types+1,index - types - 1));
        std::string value = trim(Line.substr(index+1));
        if (value.find("&") != std::string::npos) {
            value = extractValue(value);
        }
        if (type.compare("bool") == 0) {
            static bool b = stringToBool(value);
            set(name,type,&b);
        }  else if (type.compare("int") == 0) {
            static int i = std::stoi(value);
            set(name,type,&i);
        } else if (type.compare("float") == 0) {
            static float f = std::stof(value);
            set(name,type,&f);
        } else if (type.compare("double") == 0) {
            static double d = std::stod(value);
            set(name,type,&d);
        } else if (type.compare("str") == 0) {
            static std::string str = value;
            set(name,type,&str);
        } else if (type.compare("") == 0 || value.compare("null") == 0) {
            static std::string n = "null";
            set(name,type,&n);
        } else {
            static std::string n = "null";
            set(name,type,&n);
        }
        return;
    }
    return;
}
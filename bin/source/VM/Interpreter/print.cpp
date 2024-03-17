#include "header/print.h"

void _print(std::string Line) {
    int index = Line.find("print");
    if (index != std::string::npos) {
        std::string log = Line.substr(Line.find("(")+1,Line.find(")") - Line.find("(") - 1);
        if (isNumericAndOperatorOnly(extractValue(log)) && hasOperator(extractValue(log))) {
            std::cout << evaluate(extractValue(log)) << std::endl;
        } else {
            std::cout << extractValue(log) <<std::endl;
        }
        return;
    }
    return;
}
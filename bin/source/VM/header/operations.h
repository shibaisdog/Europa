#ifndef operations_H
#define operations_H

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <regex>

int precedence(char op);
double applyOp(double a, double b, char op);
double evaluate(const std::string& expression);
bool hasOperator(const std::string& str);
bool isNumericAndOperatorOnly(const std::string& input);

#endif /* operations_H */
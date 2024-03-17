#include "../header/operations.h"

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
double evaluate(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> ops;
    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == ' ')
            continue;
        else if (isdigit(expression[i])) {
            double num = 0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if(expression[i] == '.') {
                    double fraction = 0.1;
                    while (i < expression.length() && isdigit(expression[++i])) {
                        num += (expression[i] - '0') * fraction;
                        fraction /= 10.0;
                    }
                } else {
                    num = num * 10 + (expression[i] - '0');
                }
                ++i;
            }
            --i;
            values.push(num);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop();
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }
    while (!ops.empty()) {
        double val2 = values.top();
        values.pop();
        double val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    double result = values.top();
    if (result == static_cast<int>(result)) {
        return result;
    }
    return result;
}
bool hasOperator(const std::string& input) {
    for (char c : input) {
        if (c == '.' || c == '+' || c == '-' || c == '*' || c == '/') {
            return true;
        }
    }
    return false;
}
bool isNumericAndOperatorOnly(const std::string& input) {
    for (char c : input) {
        if (!(std::isdigit(c) || c == '.' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == ' ')) {
            return false;
        }
    }
    return true;
}
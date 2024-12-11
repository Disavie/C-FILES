#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <vector>
#include <cmath>

double last_result = 0.0; // Stores the most recent result

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to apply an operation to two numbers
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: throw std::runtime_error("Invalid operator");
    }
}

// Function to evaluate the expression in Reverse Polish Notation
double evaluateRPN(const std::vector<std::string>& rpn) {
    std::stack<double> values;
    for (const auto& token : rpn) {
        if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // Push number onto the stack
            values.push(std::stod(token));
        } else {
            // Pop two values for the operator
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            values.push(applyOperation(a, b, token[0]));
        }
    }
    last_result = values.top();
    return values.top();
}

// Function to replace '~' with the last result
std::string replaceTildeWithLastResult(const std::string& expression) {
    std::string replaced = expression;
    size_t pos;
    while ((pos = replaced.find('~')) != std::string::npos) {
        replaced.replace(pos, 1, std::to_string(last_result));
    }
    return replaced;
}

// Function to convert infix expression to Reverse Polish Notation
std::vector<std::string> infixToRPN(const std::string& expression) {
    std::stack<char> operators;
    std::vector<std::string> output;
    bool lastWasOperator = true; // Tracks if last token was an operator to detect negative numbers

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (std::isdigit(c) || c == '.') {
            // Handle numbers (and decimals)
            std::string number;
            while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.')) {
                number += expression[i];
                ++i;
            }
            --i; // Adjust for loop increment
            output.push_back(number);
            lastWasOperator = false; // Number ends operator sequence
        } else if (c == '(') {
            // Handle opening parenthesis
            operators.push(c);
            lastWasOperator = true; // Parenthesis starts operator sequence
        } else if (c == ')') {
            // Handle closing parenthesis
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Pop '('
            lastWasOperator = false;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Handle operators, including unary minus
            if (c == '-' && lastWasOperator) {
                // Detect unary minus (negative number)
                std::string number = "-";
                ++i;
                while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.')) {
                    number += expression[i];
                    ++i;
                }
                --i; // Adjust for loop increment
                output.push_back(number);
                lastWasOperator = false;
            } else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    output.push_back(std::string(1, operators.top()));
                    operators.pop();
                }
                operators.push(c);
                lastWasOperator = true;
            }
        }
    }

    // Pop remaining operators
    while (!operators.empty()) {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }

    return output;
}

// Main evaluation function
double evaluateExpression(const std::string& expression, double last) {
    last_result = last;
    auto sanitized = replaceTildeWithLastResult(expression);
    auto rpn = infixToRPN(sanitized);
    return evaluateRPN(rpn);
}


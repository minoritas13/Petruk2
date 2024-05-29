#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int precedence(char op){
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return 0;
    }
}

vector<string> infixToPostfix(const vector<string>& tokens) {
    vector<string> output;
    stack<string> operators;

    for (const auto& token : tokens) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            output.push_back(token);
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.pop(); // Remove '('
        } else if (isOperator(token[0])) {
            while (!operators.empty() && precedence(operators.top()[0]) >= precedence(token[0])) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while(!operators.empty()){
        output.push_back(operators.top());
        operators.pop();
    }
}
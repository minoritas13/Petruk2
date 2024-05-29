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

vector<string> splitinfinixExpression(const string& infix) {
    vector<string> tokens ;
    string number = "";
    size_t length = infix.length();
    bool previousWasOperator = true;

    for (size_t i = 0; i < length; i++) {
        if (isdigit(infix[i]) || (infix[i] == '-' && (previousWasOperator || i == 0))) {
            number += infix[i];
            previousWasOperator = false;
        }
        else {
            if (!number.empty()) {
                tokens.push_back(number);
                number.clear();
            }
            if (infix[i] == ' ') {
                continue;
            }
            else if (isOperator(infix[i]) || infix[i] == '(' || infix[i] == ')') {
                tokens.push_back(string(1,infix[i]));
                previousWasOperator = true;
        }
    }
}

if(!number.empty()) {
    tokens.push_back(number);
}

return tokens;
}

int evaluatePostfix(const vector<string>&tokens){
	stack<int>values;
	
	for(const auto&token : tokens){
		if(isdigit(token[0]) || (token[0] == '-' && token.size() > 1)){
			values.push(stoi(token));
		} else if (isOperator(token[0])){
			int right = values.top(); values.pop();
			int left = values.top(); values.pop();
			switch (token[0]){
				case '+':values.push(left + right);break;
				case '-':values.push(left - right);break;
				case '*':values.push(left * right);break;
				case '/':values.push(left / right);break;
				case '%':values.push(left % right);break;
	    	}
	    }
    }

	return values.top();
}

int main(){
    string infix;
    getline(cin, infix);

    vector<string> tokens = splitinfinixExpression(infix);
    vector<string> postfix = infixToPostfix(tokens);
    int result = evaluatePostfix(postfix);

    cout << result << endl;

    return 0;
}
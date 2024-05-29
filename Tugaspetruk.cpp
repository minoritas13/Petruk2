vector<string>splitinfinixExpression(cons string&infinix) {
    vector<string>token ;
    string number = "";
    size_t length = infinix.length();
    bool previousWasOperator = true;

    for (size_t i = 0; i < length; i++) {
        if (isdigit(infinix[i]) || (infinix[i] == "-" && (previousWasOperator || i == 0))) {
            number += infinix[i];
            previousWasOperator = false;
        }
        else {
            if (!number.empty()) {
                token.push_back(number);
                number.clear();
            }
            if (infinix[i] == " ") {
                continue;
            }
            else if (isOperator(infinix[i]) || infinix[i] == '(' || infinix[i] == ')') {
                token.push_back(string(1,infinix[i]));
                previousWasOperator = true;
        }
    }
}

if(!number.empty()) {
    token.push_back(number);
}

return tokens;
}
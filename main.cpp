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

#pragma once
#include "head.h"

class Solution {
public:
	bool isNumber(string s) {
		return !(s == "+" || s == "-" || s == "*" || s == "/");
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		for (string s : tokens) {
			if (isNumber(s)) {
				stk.push(std::stoi(s));
			}
			else {
				int s2 = stk.top(); stk.pop();
				int s1 = stk.top(); stk.pop();
				switch (s[0])
				{
				case '+':
					stk.push(s1+s2);
					break;
				case '-':
					stk.push(s1 - s2);
					break;
				case '*':
					stk.push(s1 * s2);
					break;
				case '/':
					stk.push(s1 / s2);
					break;
				default:
					break;
				}
			}
		}
		return stk.top();
	}
};
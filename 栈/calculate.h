#pragma once
#include "head.h"

//使用栈存取正负符号而不是存取数值
class Solution {
public:
	int calculate(string s) {
		stack<char> stk;
		stk.push(1);
		int sign = 1;
		int size = s.size();
		int res = 0;
		int i = 0;
		while(i < size ) {
			if (s[i] == '(') {
				stk.push(sign);
				++i;
			}
			else if (s[i] == ')') {
				stk.pop(); ++i;
			}
			else if (s[i] == '+') {
				sign = stk.top(); ++i;
			}
			else if (s[i] == '-') {
				sign = -stk.top(); ++i;
			}
			else if (s[i] == ' ') {
				++i;
			}
			//只剩下数字了
			else {
				long num = 0;
				while (i < size&&s[i] >= '0'&&s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					++i;
				}
				res += sign * num;
			}
		}
		return res;
	}
};

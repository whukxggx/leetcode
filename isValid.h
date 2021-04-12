#pragma once
#include "head.h"

class Solution {
public:
	bool isValid(string s) {
		int size = s.size();
		if (size % 2 == 1)return false;
		stack<char> c_stack;
		unordered_map<char, char> pairs = {
			{'(',')'},{'[',']'},{'{','}'}
		};
		for (char c : s) {
			if (c=='('||c=='['||c=='{') {
				c_stack.push(c);
			}
			else {
				if (c_stack.empty() || pairs[c_stack.top()] != c) {
					return false;
				}
				c_stack.pop();
			}
		}
		return c_stack.empty();
	}
};
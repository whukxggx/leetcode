#pragma once
#include "head.h"


class Solution {
public:
	bool isValidSerialization(string preorder) {
		int size = preorder.size();
		int i = 0;
		stack<int> stk;
		stk.push(1);
		while (i < size) {
			if (stk.empty())return false;
			if (preorder[i] == ',') {
				++i;
			}
			else if (preorder[i] == '#') {
				stk.top() -= 1;
				if (stk.top() == 0)stk.pop();
				++i;
			}
			else {
				while (i < size&&preorder[i] != ',')++i;
				stk.top() -= 1;
				if (stk.top() == 0)stk.pop();
				stk.push(2);
			}
		}
		return stk.empty();
	}
};
#pragma once
#include "head.h"

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0)return 0;
		int col = matrix[0].size();
		vector<int> heights(col,0);
		int ans = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
			}
			ans = max(ans, largestRectangleArea(heights));
		}
		return ans;
	}
	int largestRectangleArea(vector<int>& heights) {
		int size = heights.size();
		stack<int> minStack;
		//右边界初始化为size
		vector<int> leftTmp(size), rightTmp(size, size);
		for (int i = 0; i < size; ++i) {
			while (!minStack.empty() && heights[minStack.top()] >= heights[i]) {
				rightTmp[minStack.top()] = i;
				minStack.pop();
			}
			leftTmp[i] = minStack.empty() ? -1 : minStack.top();
			minStack.push(i);
		}
		int ans = 0;
		for (int i = 0; i < size; ++i) {
			ans = max(ans, heights[i] * (rightTmp[i] - leftTmp[i] - 1));
		}
		return ans;
	}
};
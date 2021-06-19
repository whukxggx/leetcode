#pragma once
#include "head.h"


class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int ans = INT_MIN;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row; ++i) {
			vector<int> sum(col);
			for (int j = i; j < row; ++j) {
				for (int m = 0; m < col; ++m) {
					sum[m] += matrix[j][m];
				  }
				set<int> sumSet{ 0 };
				int s = 0;
				for (int v : sum) {
					s += v;
					auto lb = sumSet.lower_bound(s - k);
					if (lb != sumSet.end()) {
						ans = max(ans, s - *lb);
					}
					sumSet.insert(s);
				}
			}
		}
		return ans;
	}
};
#pragma once

#include "head.h"

class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int size = envelopes.size();
		vector<int> dp(size, 1);
		sort(envelopes.begin(), envelopes.end(), [](const auto x, const auto y) {
			return x[0] < y[0] || (x[0]==y[0]&&x[1] < y[1]);
		});
		for (int i = 1; i < size; ++i) {
			for (int j = 0; j < i; ++j) {
				if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};
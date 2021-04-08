#pragma once
#include "head.h"

class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int size = s.size();
		if (size == 0)return 0;
		int left = 0, right = 0;
		int cost = 0;
		int ans = 0;
		while (right < size) {
			cost += abs(s[right] - t[right]);
			++right;
			while (cost > maxCost) {
				cost -= abs(s[left] - t[left]);
				++left;
			}
			ans = max(ans, right - left);
		}
		return ans;
	}
};
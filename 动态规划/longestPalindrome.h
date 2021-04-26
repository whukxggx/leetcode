#pragma once
#include "head.h"



class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();
		vector<vector<bool>> f(size, vector<bool>(size,0));
		int maxlen = 1;
		int begin = 0;
		for (int i = 0; i < size; ++i) {
			f[i][i] = true;
			if (i < size - 1 && s[i] == s[i + 1]) {
				f[i][i + 1] = true;
				maxlen = 2;
				begin = i;
			}
		}
		for (int j = 3; j <=size; ++j) {
			for (int i = 0; i < size - j + 1; ++i) {
				int t = i + j - 1;
				if (s[i] == s[t]) {
					f[i][t] = f[i + 1][t - 1];
				}
				else {
					f[i][t] = false;
				}
				if (f[i][t]&&t - i + 1 > maxlen) {
					maxlen = t - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxlen);
	}
};
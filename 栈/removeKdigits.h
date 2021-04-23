#pragma once
#include "head.h"


class Solution {
public:
	string removeKdigits(string num, int k) {
		int size = num.size();
		int len = size - k;
		string res;
		for (int i = 0; i < size; ++i) {
			while (k > 0 && !res.empty() && res.back() > num[i]) {
				res.pop_back();
				--k;
			}
			if (res.size() < len) {
				res.push_back(num[i]);
			}
			else {
				--k;
			}
		}
		int sizeR = res.size();
		int t = 0;
		while (t < sizeR) {
			if (res[t] == '0')++t;
			else break;
		}
		string realRes = res.substr(t, sizeR - t);
		return realRes==""?"0":realRes;
	}
};
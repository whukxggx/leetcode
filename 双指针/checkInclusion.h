#pragma once
#include "head.h"

class Solution {
	unordered_map<char, int> p_map, s_map;
public:
	bool check() {
		for (const auto &p : p_map) {
			if (s_map[p.first] < p.second)return false;
		}
		return true;
	}
	bool checkInclusion(string s1, string s2) {
		int size = s2.size();
		int psize = s1.size();
		int left = 0, right = 0, length = 0;
		for (int i = 0; i < psize; ++i) {
			++p_map[s1[i]];
		}
		vector<int> ans;
		while (right < size) {
			++s_map[s2[right]];
			++right;
			while (check() && right - left >= psize) {
				if (check() && right - left == psize) {
					return true;
				}
				--s_map[s2[left]];
				++left;
			}
		}
		return false;
	}
};
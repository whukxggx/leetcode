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
public:
	vector<int> findAnagrams(string s, string p) {
		int size = s.size();
		int psize = p.size();
		int left = 0, right = 0, length = 0;
		for (int i = 0; i < psize; ++i) {
			++p_map[p[i]];
		}
		vector<int> ans;
		while (right < size) {
			++s_map[s[right]];
			++right;
			while (check() && right - left >= psize) {
				if (check() && right - left == psize) {
					ans.push_back(left);
				}
				--s_map[s[left]];
				++left;
			}
		}
		return ans;
	}
};
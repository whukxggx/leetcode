#pragma once
#include "head.h"

class Solution {
	unordered_map<char,int> t_map, s_map;
public:
	bool check() {
		for (const auto &p : t_map) {
			if (s_map[p.first] < p.second)return false;
		}
		return true;
	}
	string minWindow(string s, string t) {
		int size = s.size();
		int left = 0, right = 0,minLength=INT_MAX,ansLeft=0;
		for (int i = 0; i < t.size(); ++i) {
			++t_map[t[i]];
		}
		while (right <size) {
			if(t_map.find(s[right])!=t_map.end())s_map[s[right]]++;
			++right;
			while (check()&&left<right) {
				if (right - left < minLength) {
					minLength = right - left;
					ansLeft = left;
				}
				if(t_map.find(s[left])!=t_map.end())--s_map[s[left]];
				++left;
			}
		}
		if (minLength != INT_MAX)return s.substr(ansLeft, minLength);
		else return "";
	}
};
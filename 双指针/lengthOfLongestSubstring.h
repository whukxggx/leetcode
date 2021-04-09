#pragma once
#include "head.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.size();
		map<char, bool> check_repeat;
		int left = 0, right = 0, maxLength = 0;
		while (right < size) {
			if (check_repeat[s[right]] == false) {
				check_repeat[s[right]] = true;
				++right;
			}else {
				while (s[left] != s[right]) {
					check_repeat[s[left]] = false;
					++left;
				}
				check_repeat[s[left]] = false;
				++left;
			}
			maxLength = max(maxLength, right - left);
		}
		return maxLength;
	}
};
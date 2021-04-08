#pragma once
#include "head.h"

//最关键的是 遇到英文字母 用26长数组存储频次
class Solution {
public:
	int characterReplacement(string s, int k) {
		int size = s.size();
		vector<int> freq(26,0);//26个英文字母的频次
		int left=0, right=0;
		int maxCount = 0;
		int ans = 0;
		while (right < size) {
			++freq[s[right] - 'A'];
			maxCount = max(maxCount, freq[s[right] -'A']);//只有此字母频次变了
			++right;

			//如果k个转变不够用
			if (right - left > maxCount + k) {
				--freq[s[left] - 'A'];
				left++;
			}
			ans = max(ans, right - left);
		}
		return ans;
	}
};
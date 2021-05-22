#pragma once
#include "head.h"

class Solution {
private:
	unordered_map<int, vector<string>> ans;
	unordered_set<string> words;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		words = unordered_set<string>(wordDict.begin(), wordDict.end());
		backTrack(s, 0);
		return ans[0];//���±�0��ʼ �����Ĵ�
	}
	void backTrack(const string &s, int index) {
		if (!ans.count(index)) {
			if (index == s.size()) {
				ans[index] = { "" };
				return;
			}
			for (int i = index + 1; i <= s.size(); ++i) {
				string word = s.substr(index, i - index);
				if (words.count(word)) {
					backTrack(s, i);
					for (const string & x : ans[i]) {
						ans[index].push_back(x.empty() ? word : word + " " + x);
					}
				}
			}
		}
	}
};
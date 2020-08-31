#include"head.h"

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		int size = strs.size();
		if (size == 0)return string();
		string pref = strs[0];
		for (int i = 1; i < size; ++i)
		{
			pref = longestCommonPrefix(strs[i], pref);
			if (pref.size() == 0)break;
		}
		return pref;
	}
	string longestCommonPrefix(string s1, string s2)
	{
		int len = min(s1.size(), s2.size());
		int index = 0;
		while (index < len && s1[index] == s2[index])
		{
			++index;
		}
		return s1.substr(0, index);
	}
};

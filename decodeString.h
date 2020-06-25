#include"head.h"
//394 字符串解码
class Solution
{
	string getDigits(string s, int &ptr)
	{
		string ret = "";
		while (isdigit(s[ptr]))
		{
			ret.push_back(s[ptr]);
			++ptr;
		}
		return ret;
	}
	string getString(vector<string> sub){
		string ret="";
		for(auto & t:sub){
			ret+=t;
		}
		return ret;
	}
public:
	string decodeString(string s)
	{
		vector<string>  sta;
		int ptr = 0;
		int size = s.size();
		while (ptr < size)
		{
			if (isdigit(s[ptr]))
			{
				string digits = getDigits(s, ptr);
				sta.push_back(digits);
			}
			else if (isalpha(s[ptr]) || s[ptr] == '[')
			{
				sta.push_back(string(1, s[ptr]));
				++ptr;
			}
			else if (s[ptr] == ']')
			{
				++ptr;
				vector<string> sub;
				while (sta.back() != "[")
				{
					sub.push_back(sta.back());
					sta.pop_back();
				}
				reverse(sub.begin(), sub.end());
				sta.pop_back();
				string str=getString(sub);
				int times = stoi(sta.back());
				sta.pop_back();
				string tmp;
				while (times--)tmp += str;
				sta.push_back(tmp);
			}
		}
		string ret;
		for (const auto &a : sta)
		{
			ret += a;
		}
		return ret;
	}
};

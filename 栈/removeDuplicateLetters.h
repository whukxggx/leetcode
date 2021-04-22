#pragma once
#include "head.h"

class Solution {
public:
	string removeDuplicateLetters(string s) {
		//vis记录某个字母是否在栈中
		vector<char> num(26, 0),vis(26,0);
		for (const char& c : s)++num[c-'a'];

		string stk;//单调栈
		for (const char&c : s) {
			if (!vis[c - 'a']) {//如果字符已经存在栈中，不能添加
				while (!stk.empty() && stk.back() > c) {
					if (num[stk.back()-'a'] > 0) {//如果剩余字符串中栈顶字母数量为0了,不能出栈
						vis[stk.back() - 'a'] = 0;//此时此字母不在栈中
						stk.pop_back();
					}
					else {
						break;
					}
				}
			stk.push_back(c);
			vis[c - 'a'] = 1;
			}
			num[c - 'a'] -= 1;//只需要在添加的时候，将剩余字符串中此字符的个数计算
		}
		return stk;
	}
};
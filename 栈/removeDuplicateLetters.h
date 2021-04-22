#pragma once
#include "head.h"

class Solution {
public:
	string removeDuplicateLetters(string s) {
		//vis��¼ĳ����ĸ�Ƿ���ջ��
		vector<char> num(26, 0),vis(26,0);
		for (const char& c : s)++num[c-'a'];

		string stk;//����ջ
		for (const char&c : s) {
			if (!vis[c - 'a']) {//����ַ��Ѿ�����ջ�У��������
				while (!stk.empty() && stk.back() > c) {
					if (num[stk.back()-'a'] > 0) {//���ʣ���ַ�����ջ����ĸ����Ϊ0��,���ܳ�ջ
						vis[stk.back() - 'a'] = 0;//��ʱ����ĸ����ջ��
						stk.pop_back();
					}
					else {
						break;
					}
				}
			stk.push_back(c);
			vis[c - 'a'] = 1;
			}
			num[c - 'a'] -= 1;//ֻ��Ҫ����ӵ�ʱ�򣬽�ʣ���ַ����д��ַ��ĸ�������
		}
		return stk;
	}
};
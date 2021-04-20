#pragma once
#include "head.h"

//227. ���������� II

class Solution {
public:
	int calculate(string s) {
		stack<int> stk;
		int size = s.size();
		int num = 0;
		int i = 0;
		char preSign = '+';
		while (i < size) {
			while (isdigit(s[i])&&i!=size) {
				//�˴�����intת�� ���������Ϊ���� ����leet��ͨ����Ϊint_max�ȼ���s[i]�ᵼ�³���int��Χ,vs2017����ͨ��
				num = num * 10 +int( s[i] - '0');
				++i;
			}
			while (s[i] == ' ')++i;
			if(i==size||!isdigit(s[i])){
				switch (preSign) {
				case '+':
					stk.push(num);
					break;
				case '-':
					stk.push(-num);
					break;
				case '*':
					stk.top() *= num;
					break;
				case '/':
					stk.top() /= num;
					break;
				}
				preSign = s[i];
				num = 0;
				++i;
			}
		}
		int res = 0;
		while (!stk.empty()) {
			res += stk.top(); stk.pop();
		}
		return res;
	}
};



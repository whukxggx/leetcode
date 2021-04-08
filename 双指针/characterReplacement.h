#pragma once
#include "head.h"

//��ؼ����� ����Ӣ����ĸ ��26������洢Ƶ��
class Solution {
public:
	int characterReplacement(string s, int k) {
		int size = s.size();
		vector<int> freq(26,0);//26��Ӣ����ĸ��Ƶ��
		int left=0, right=0;
		int maxCount = 0;
		int ans = 0;
		while (right < size) {
			++freq[s[right] - 'A'];
			maxCount = max(maxCount, freq[s[right] -'A']);//ֻ�д���ĸƵ�α���
			++right;

			//���k��ת�䲻����
			if (right - left > maxCount + k) {
				--freq[s[left] - 'A'];
				left++;
			}
			ans = max(ans, right - left);
		}
		return ans;
	}
};
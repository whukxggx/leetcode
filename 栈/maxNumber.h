#pragma once
#include "head.h"

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		vector<int> sub1, sub2;
		vector<int> res;
		int start = max(0, k - size2);
		int end = min(k, size1);
		for (int i = start; i <= end; ++i) {
				sub1 = maxSequence(nums1, i);
				sub2 = maxSequence(nums2, k-i);
				vector<int> tmp = mergeSequence(sub1, sub2);
				if (!bigger(res, 0, tmp, 0))//如果比tmp小
					res.swap(tmp);
		}
		return res;
	}
	//注意获取的不一定是完全有序的
	vector<int> maxSequence(vector<int>& nums1, int len) {
		int size = nums1.size();
		vector<int> res;
		int dropNum = size - len;
		for (int i = 0; i < size; ++i) {
			while (dropNum>0&&!res.empty() && res.back() < nums1[i]) {
				res.pop_back();
				--dropNum;
			}
			if (res.size() < len) {
				res.push_back(nums1[i]);
			}else {
				--dropNum;
			}
		}
		return res;
	}
	vector<int> mergeSequence(vector<int> sub1, vector<int> sub2) {
		int size1 = sub1.size(); int size2 = sub2.size();
		int i = 0, j = 0;
		vector<int> res;
		while (i < size1&&j < size2) {
			if (bigger(sub1, i, sub2, j)) {
				res.emplace_back(sub1[i]); ++i;
			}
			else {
				res.emplace_back(sub2[j]); ++j;
			}
		}
		while (i < size1) {
			res.emplace_back(sub1[i]); ++i;
		}
		while (j < size2) {
			res.emplace_back(sub2[j]); ++j;
		}
		return res;
	}
	bool bigger(vector<int> sub1, int index1, vector<int> sub2, int index2) {
		bool res;
		int size1 = sub1.size(); int size2 = sub2.size();
		while (index1 < size1&&index2 < size2) {
			if (sub1[index1] > sub2[index2])return true;
			else if (sub1[index1] < sub2[index2]) return false;
			++index1; ++index2;
		}
		if (index1 < size1)return true;
		if (index2 < size2)return false;
		return true;
	}
};
#pragma once
#include "head.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* first = head;
		if (first == nullptr)return head;
		int len = 1;
		while (first->next!=nullptr) {
			first = first->next;
			++len;
		}
		//ºÏ³É»·
		first->next = head;
		k %= len;
		int right_len = len - k - 1;
		ListNode *rotate_head = nullptr;
		for (int i = 0; i < right_len; ++i) {
			head = head->next;
		}
		rotate_head = head->next;
		head->next = nullptr;
		return rotate_head;
	}
};
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* first = head;
		if (first == nullptr)return head;
		ListNode* second = head->next;
		ListNode* tmp = nullptr;
		if (!second)return head;
		while (second != nullptr) {
			if (second->val == first->val) {
				while (second != nullptr&&second->val == first->val) {
					tmp = second;
					second = second->next;
					delete tmp;
					tmp = nullptr;
				}
				first->next = second;
			}
			else {
				first = first->next;
				second = second->next;
			}
		}
		return head;
	}
};
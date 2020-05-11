#include"head.h"


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)return l2;
        if (l2 == nullptr)return l1;
        int tp = l1->val + l2->val;
        int valp = tp % 10;
        int p = tp/10;
        ListNode* head = new ListNode(valp);
        l1 = l1->next;
        l2 = l2->next;
        ListNode* tmp =head;
        int once = 1;
        while (l1 != nullptr && l2 != nullptr) {
            int t = l1->val + l2->val + p;
            int val = t % 10;
            p = t / 10;
            tmp->next = new ListNode(val);
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int t = l1->val + p;
            int val = t % 10;
            p = t / 10;
            tmp->next = new ListNode(val);
            tmp = tmp->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int t = l2->val + p;
            int val = t % 10;
            p = t / 10;
            tmp->next = new ListNode(val);
            tmp = tmp->next;
            l2 = l2->next;
        }
        if (p == 1) {
            tmp->next = new ListNode(1);
        }
        return head;
    }
};
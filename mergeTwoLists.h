#include "head.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(1);
        ListNode *tmp = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        while (l1 != nullptr)
        {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        while (l2 != nullptr)
        {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        ListNode *t=tmp->next;
        delete tmp;tmp=nullptr;
        return t;
    }
};
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
    ListNode *treverse(ListNode *first, ListNode *last)
    {
        ListNode *head = new ListNode(0);
        head->next = first;
        ListNode *tmp = first;
        head->next = last->next;
        while (tmp != last)
        {
            ListNode *t = tmp->next;
            tmp->next = head->next;
            head->next = tmp;
            tmp = t;
        }
        tmp->next = head->next;
        head->next = tmp;
        tmp = head->next;
        delete head;
        head = nullptr;
        return tmp;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *last = head;
        for (int i = 0; i < k - 1 && last != nullptr; ++i)
        {
            last = last->next;
        }
        if (last != nullptr)
            head = last;
        ListNode *t = new ListNode(0);
        while (last != nullptr)
        {
            ListNode *f = last->next;
            t->next = treverse(first, last);
            t = first; //逆置后的结尾
            first = f;
            last = f;
            for (int i = 0; i < k - 1 && last != nullptr; ++i)
            {
                last = last->next;
            }
        }
        return head;
    }
};
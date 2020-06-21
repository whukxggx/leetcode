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
    ListNode *removeElements(ListNode *head, int val)
    {
        if(head==nullptr)return head;
        ListNode *pre;
        ListNode *cur;
        while (head!=nullptr&&head->val == val)
        {
            pre = head;
            head = head->next;
            delete pre;
            pre = nullptr;
        }
        pre = head; //此时head
        if (head != nullptr)
            cur = head->next;
        else cur=nullptr;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
                continue;
            }
            pre=pre->next;
            cur = cur->next;
        }
        return head;
    }
};
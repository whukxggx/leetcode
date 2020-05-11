#include"head.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *nhead=head;
        //复制一份
        while(nhead!=NULL){
            Node *t=new Node(nhead->val);
            t->next=nhead->next;
            nhead->next=t;
            nhead=t->next;
        }
        nhead=head;
        while(nhead!=NULL){
            if(nhead->random!=NULL)
                nhead->next->random=nhead->random->next;
            nhead=nhead->next->next;
        }
        nhead=head;
        Node *copyHead=NULL;
        Node *copyNode=NULL;
        if(nhead!=NULL){
            copyHead=copyNode=nhead->next;
            nhead->next=copyNode->next;
            nhead=nhead->next;
        }
        while(nhead!=nullptr){
            copyNode->next=nhead->next;
            copyNode=copyNode->next;
            nhead->next=copyNode->next;
            nhead=nhead->next;
        }
        return copyHead;
    }
};
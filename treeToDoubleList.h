#include"head.h"

class Solution {
   public:
	  Node* treeToDoublyList(Node* root) {
		 if(root==nullptr)return nullptr;
		 Node *lastNode=nullptr;
		 convert(root,&lastNode);
		 Node *head=lastNode;
		 while(head!=nullptr&&head->left!=nullptr)
			head=head->left;
		 head->left=lastNode;
		 lastNode->right=head;
		 return head;
	  }
	  void convert(Node *root,Node ** lastNode){
		 if(root==nullptr)return;
		 Node *cur=root;
		 if(cur->left!=nullptr){
			convert(cur->left,lastNode);
		 }
		 cur->left=*lastNode;
		 if((*lastNode)!=nullptr)(*lastNode)->right=cur;
		 *lastNode=cur;
		 if(cur->right!=nullptr){
			convert(cur->right,lastNode);
		 }
	  }
};


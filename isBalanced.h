#include"head.h"
//面试题 04.04. 检查平衡性

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int deep(TreeNode *root){
        int left=0,right=0;
        if(root==nullptr)return 0;
        if(root->left)left=deep(root->left) ;
        if(root->right)right=deep(root->right);
        int deep=max(left,right)+1;
        return deep;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        if(root->left){
            bool left=isBalanced(root->left);
            if(!left)return false;
        }
        if(root->right){
            bool right=isBalanced(root->right);
            if(!right)return false;
        }
        int le_deep=deep(root->left);
        int ri_deep=deep(root->right);
        if(abs(le_deep-ri_deep)>1)return false;
        else return true;
    }
};
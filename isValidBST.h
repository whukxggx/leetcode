

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return findIfValid(root);
    }
    bool findIfValid(TreeNode *root){
        if(root==nullptr)return true;
        bool left=findIfValid(root->left);
        if(root->left){
            if(root->left->val>=root->val)return false;
        }
        if(root->right){
            if(root->right->val<=root->val)return false;
        }
        bool right=findIfValid(root->right);
        return left&&right;
    }
};
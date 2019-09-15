/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool res = true;
        long last =LONG_MIN;
        find_bg(root,last,res);
        return res;
    }
    void find_bg(TreeNode* root,long &last,bool &res)
    {
        if(root==NULL) return ;
        find_bg(root->left,last,res);
        if(last>=root->val)
        {
            res = false; 
            return;
        }
        last = root->val;
        find_bg(root->right,last,res);
        return;
    }
 
};

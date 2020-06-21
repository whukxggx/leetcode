#include"head.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vec;
        if(root==NULL)return vec;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> vtmp;
            while(size>0){
                TreeNode *tmp=q.front();
                vtmp.push_back(tmp->val);
                q.pop();
                --size;
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            vec.push_back(vtmp);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
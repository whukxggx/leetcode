#include "head.h"

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
    bool isParent(TreeNode *x, TreeNode *p)
    {
        return p->left == x || p->right == x;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        if (root == NULL)
            return vec;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *tmp = root;
        while (!s.empty())
        {
            if (!isParent(tmp, s.top()))
                aux(s);
            tmp = s.top();
            s.pop();
            vec.push_back(tmp->val);
        }
        return vec;
    }
    void aux(stack<TreeNode *> &s)
    {
        TreeNode *x;
        while (x = s.top())
        {
            if (x->left)
            {
                if (x->right)
                    s.push(x->right);
                s.push(x->left);
            }
            else
            {
                s.push(x->right);
            }
        }
        s.pop();
    }
};
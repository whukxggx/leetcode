#pragma once
#include "head.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	unordered_map<TreeNode*, int> m_has, m_no;
public:
	void rem(TreeNode* root) {
		if (root == nullptr)return;
		rem(root->left);
		rem(root->right);
		m_has[root] = root->val + m_no[root->left] + m_no[root->right];
		m_no[root] = max(m_has[root->left], m_no[root->left]) + max(m_has[root->right], m_no[root->right]);
	}
	int rob(TreeNode* root) {
		rem(root);
		return max(m_has[root], m_no[root]);
	}
};
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
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodes;
		vector<int> ans;
		if (root == NULL) return ans;
		nodes.push(root);
		while (!nodes.empty()) {
			TreeNode* tmp = nodes.top();
			nodes.pop();
			ans.push_back(tmp->val);
			if (tmp->right!=nullptr) nodes.push(tmp->right);
			if (tmp->left!=nullptr) nodes.push(tmp->left);
		}
		return ans;
	}
};

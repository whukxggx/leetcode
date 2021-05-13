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
	vector<TreeNode*> generateTrees(int begin, int end) {
		if (begin > end)return { nullptr };
		vector<TreeNode*> res;
		for (int i = begin; i <=end; ++i) {
			vector<TreeNode*> leftTrees = generateTrees(begin, i - 1);
			vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
			for (auto &left : leftTrees) {
				for (auto &right : rightTrees) {
					TreeNode* t = new TreeNode(i);
					t->left = left;
					t->right = right;
					res.emplace_back(t);
				}
			}
		}
		return res;
	}
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)return { nullptr };
		return generateTrees(1, n);
	}
};
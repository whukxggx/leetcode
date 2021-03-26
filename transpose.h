#pragma once
//×ªÖÃ¾ØÕó
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row == 0)return matrix;
		int col = matrix[0].size();
		vector<vector<int>> vec_ret(col+1,vector<int>(row+1));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				vec_ret[j][i] = matrix[i][j];
			}
		}
		return vec_ret;
	}
};
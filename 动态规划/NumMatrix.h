#pragma once
#include "head.h"

class NumMatrix {
	vector<vector<int>> sums;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows> 0) {
			int cols = matrix[0].size();
			sums.resize(rows+1,vector<int>(cols+1));
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < cols; ++j) {
					sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + matrix[i][j];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
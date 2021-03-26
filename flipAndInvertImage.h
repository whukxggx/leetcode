#pragma once
#include "head.h"

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
		int size = image.size();
		if (size == 0)return image;
		for (int i = 0; i < size; ++i) {
			reverse(image[i].begin(), image[i].end());
			for (int j = 0; j < image[i].size(); ++j) {
				image[i][j] = !image[i][j];
			}
		}
		return image;
	}
};
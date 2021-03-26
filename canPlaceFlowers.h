#pragma once
#include "head.h"

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int size = flowerbed.size();
		vector<int> flowerbed_aux;
		flowerbed_aux.push_back(0);
		flowerbed_aux.insert(flowerbed_aux.end(), flowerbed.begin(), flowerbed.end());
		flowerbed_aux.push_back(0);
		for (vector<int>::iterator ite = flowerbed_aux.begin();
			ite+2 != flowerbed_aux.end(); ++ite) {
			if (*ite == 0 && *(ite + 1) == 0 && *(ite + 2) == 0) {
				--n;
				*(ite + 1) = 1;
			}
		}
		if (n <= 0)return true;
		return false;
	}
};
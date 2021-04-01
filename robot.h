#pragma once
#include "head.h"

class Solution {
public:
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		int size = command.size();
		int x_1 = 0, y_1 = 0;
		for (char c : command) {
			if (c == 'U')++y_1;
			else ++x_1;
		}
		if (helper(command, x_1, y_1, x, y) == false) { return false; }
		for (vector<int> v : obstacles) {
			if (v[0]<=x&&v[1]<=y&&helper(command, x_1, y_1, v[0], v[1]) == true)return false;
		}
		return true;
	}
	//2 1 3 2
	bool helper(string command, int x_1, int y_1, int x, int y) {
		int k = 0;
		if (x_1 != 0 && y_1 != 0) {
			k = min(x / x_1, y / y_1);
		}else if (x_1 != 0) {
			k = x / x_1;
		}
		else if (y_1 != 0) {
			k = y / y_1;
		}else {
			return true;
		}
		x -= k * x_1;
		y -= k * y_1;
		//只进行一次循环
		int size = command.size();
		int x_0 = 0, y_0 = 0;
		for (int i = 0; i < size; ++i) {
			if (x_0 == x && y_0 == y) {
				return true;
			}
			if (command[i] == 'U')
				++y_0;
			else
				++x_0;
		}
		return (x_1==x&&y_1==y);
	}
};
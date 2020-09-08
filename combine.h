#include"head.h"

class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> res;
		vector<int> tmp;
		dfs(res, tmp, 1, n, k);
		return  res;
	}
	void dfs(vector<vector<int>> &vec, vector<int> &df, int x, int n, int k)
	{
		if (df.size() == k)
		{
			vec.push_back(df);
			return;
		}
		for (int i = x; i <= n; ++i)
		{
			df.push_back(i);
			dfs(vec, df, i + 1, n, k);
			df.pop_back();
		}
	}
};

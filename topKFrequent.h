#include"head.h"

class Solution
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		map<int, int> counter;
		vector<int> res;
		for (auto t : nums)
		{
			counter[t]++;
		}
		using pai = std::pair<int, int>;
		priority_queue<pai, vector<pai>, std::greater<pai>> minHea;
		for (auto &pair : counter)
		{
			minHea.push({pair.second, pair.first});
			if (minHea.size() > k)minHea.pop();
		}
		while (!minHea.empty())
		{
			res.push_back(minHea.top().second);
			minHea.pop();
		}
		return res;
	}
};

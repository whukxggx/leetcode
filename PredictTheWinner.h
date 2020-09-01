class Solution
{
public:
	bool PredictTheWinner(vector<int>& nums)
	{
		int size = nums.size();
		vector<vector<int>> vec(size, vector<int>(size));
		for (int j = 0; j < size; ++j)
		{
			for (int i = j + 1; i < size; ++i)
			{
				vec[i][j] = 0;
			}
		}
		for (int i = 0; i < size; ++i)
			vec[i][i] = nums[i];
		for (int l = 2; l <= size; ++l)
		{
			for (int i = 0; i < size - l + 1; ++i)
			{
				int j = i + l - 1;
				vec[i][j] = max(nums[i] - vec[i + 1][j], nums[j] - vec[i][j - 1]);
			}
		}
		return vec[0][size - 1] >= 0;
	}
};

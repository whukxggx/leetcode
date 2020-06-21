#include"head.h"


//53. 最大子序和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        int ans;
        vector<int> dp(size);
        dp[0]=nums[0];
        ans=nums[0];
        for(int i=1;i<size;++i){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(dp[i],ans);
        }
        return ans;
    }
};

//还可分治，见算法导论
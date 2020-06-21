#include"head.h"

//523. 连续的子数组和

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size=nums.size();
        vector<int> sum(size,0);
        sum[0]=nums[0];
        for(int i=1;i<size;++i){
            sum[i]+=nums[i]+sum[i-1];
        }
        if(k==0&&sum[size-1]!=0)return false;
        for(int i=1;i<size;++i){
            for(int j=0;j<i;++j){
                int tmp=sum[i]-sum[j]+nums[j];
                if (tmp == k || (k != 0 && tmp % k == 0))return true;
            }
        }
        return false;
    }
};
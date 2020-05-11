#include"head.h"

//16. 最接近的三数之和
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int size = nums.size();
    if(size<3)return 0;
    sort(nums.begin(), nums.end());
    int min=nums[0]+nums[1]+nums[2];
    for (int i = 0; i < size-1; ++i) {
        int t = nums[i];
        int L = i + 1;
        int R = size - 1;
        while (L < R) {
            int sum=t+nums[L]+nums[R];
            if(abs(target-sum)<abs(target-min))
                min=sum;
            else if(sum>target)
                R--;
            else if(sum<target)
                L++;
            else if(sum==target)
                return min;
        }
    }
    return min;
    }
};
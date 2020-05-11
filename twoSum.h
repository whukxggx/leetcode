//1. 两数之和
#include"head.h"


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        for(int i=0;i<size-1;++i){
            int tmp=nums[i];
            for(int j=i+1;j<size;++j){
                if(tmp+nums[j]==target){
                    vector<int> a{i,j};
                    return a;
                }
            }
        }
        vector<int> a(2,0);
        return a;
    }
};
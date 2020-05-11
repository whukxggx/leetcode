#include"head.h"


//11. 盛最多水的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int left=0;
        int right=size-1;
        int ans=INT_MIN;
        while(left<right){
            int nowArea=min(height[left],height[right])*(right-left);
            ans=max(ans,nowArea);
            if(height[left]>height[right]){
                --right;
            }else{
                ++left;
            }
        }
        return ans;
    }
};
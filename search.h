#include"head.h"


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        if(size==0)return -1;
        if(size==1)return nums[0]==target?0:-1;
        int begin=0,end=size-1;
        while(begin<=end){
            int mid=(begin+end)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>=nums[0]){//此处为什么要有=
                if(target>=nums[0]&&target<nums[mid]){
                    end=mid-1;
                }else{
                    begin=mid+1;
                }
            }else{
                if(target<=nums[size-1]&&target>nums[mid]){
                    begin=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
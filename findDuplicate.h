#include"head.h"

//287. 寻找重复数

//二分法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        int left=1;
        int right=size-1;
        while(left<right){
            int mid=(left+right)/2;
            int cnt=0;
            for(auto x:nums){
                if(x<=mid)
                    cnt++;
            }
            if(cnt>mid){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};


//快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        int left=1;
        int right=size-1;
        while(left<right){
            int mid=(left+right)/2;
            int cnt=0;
            for(auto x:nums){
                if(x<=mid)
                    cnt++;
            }
            if(cnt>mid){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
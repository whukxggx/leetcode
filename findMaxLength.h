#include"head.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int count=0;
        int size=nums.size();
        int maxLen=0;
        for(int i=0;i<size;++i){
            if(nums[i]==0)count--;
            else count++;
            if(m.find(count)==m.end()){
                m[count]=i;
            }else{
                maxLen=max(maxLen,i-m[count]);
            }
            if(count==0)maxLen=i+1;
        }
        return maxLen;
    }
};
#include"head.h"


class Solution {
   public:
	  vector<vector<int>> fourSum(vector<int>& nums, int target) {
		 vector<vector<int>> vecRet;
		 int size=nums.size();
		 if(size<3)return vecRet;
		 sort(nums.begin(),nums.end());
		 for(int i=0;i<=size-4;++i){
			if(i>0&&nums[i]==nums[i-1])continue;
			for(int j=i+1;j<=size-3;++j){
			   if(j>i+1&&nums[j]==nums[j-1])continue;
			   int l=j+1;
			   int r=size-1;
			   while(l<r){
				  if(nums[i]+nums[j]+nums[l]+nums[r]==target){
					 vecRet.push_back({nums[i],nums[j],nums[l],nums[r]});
					 while(l<r&&nums[l+1]==nums[l])++l;
					 while(r>l&&nums[r-1]==nums[r])--r;
					 ++l;--r;
				  }else if(nums[i]+nums[j]+nums[l]+nums[r]<target){
					 ++l;
				  }else{
					 --r;
				  }
			   }
			}
		 }
		 return vecRet;
	  }
};


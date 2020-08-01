#include"head.h"


class Solution {
   public:
	  inline	bool isIn(int num,int size){
		 if(num>=1&&num<=size)return true;
		 else return false;
	  }
	  int firstMissingPositive(vector<int>& nums) {
		 int size=nums.size();
		 for(int i=0;i<size;++i){
			while(isIn(nums[i],size)&&nums[i]!=nums[nums[i]-1]){
			   swap(nums[i],nums[nums[i]-1]);
			}
		 }
		 for(int i=0;i<size;++i){
			if(nums[i]!=i+1)return i+1;
		 }
		 return size+1;
	  }
};

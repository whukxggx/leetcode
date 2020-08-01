#include"head.h"


class Solution {
   public:
	  int reversePairs(vector<int>& nums) {
		 int size=nums.size();
		 vector<int> tmp(size);
		 return mergeSort(nums,tmp,0,size-1);
	  }
	  int mergeSort(vector<int> &nums,vector<int>& tmp,int begin,int end){
		 if(begin>=end)return 0;
		 int mid=(begin+end)/2;
		 int inverse_count=mergeSort(nums,tmp,begin,mid)+mergeSort(nums,tmp,mid+1,end);
		 int i=begin,j=mid+1,pos=begin;
		 while(i<=mid&&j<=end){
			if(nums[i]<=nums[j]){
			   inverse_count+=(j-mid-1);
			   tmp[pos]=nums[i];
			   ++i;
			}
			else{
			   tmp[pos]=nums[j];
			   ++j;
			}
			++pos;
		 }
		 for(int k=i;k<=mid;++k){
			tmp[pos]=nums[k];
			++pos;
			inverse_count+=(j-mid-1);
		 }
		 for(int k=j;k<=end;++k){
			tmp[pos]=nums[k];
			++pos;
		 }
		 copy(tmp.begin()+begin,tmp.begin()+end+1,nums.begin()+begin);
		 return inverse_count;
	  }
};


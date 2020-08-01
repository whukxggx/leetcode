class Solution {
public:
    int majorityElement(vector<int>& nums) {
	int size=nums.size();
  	int count=0;
  	int tmp=nums[0];
	for(auto const &n:nums){
		if(count==0)tmp=n;
		count+=(n==tmp)?1:-1;
	}
	return tmp;	
    }
};

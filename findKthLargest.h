class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size=nums.size();
        return quickSelect(nums,0,size-1,size-1-k);
    }
    int quickSelect(vector<int> &nums,int begin,int end,int k_small){
        if(begin==end)return nums[begin];
        int p=begin+paration(nums,begin,end);
        if(p==k_small)return nums[p];
        else if(p>k_small) return quickSelect(nums,begin,p-1,k_small);
        return quickSelect(nums,p+1,end,k_small);
    }
    int paration(vector<int> &nums,int begin,int end){
        int x=nums[begin];
        int i=begin+1;
        for(int j=begin+1;j<=end;++j){
            if(nums[j]<nums[i]){
                swap(nums[i],nums[j]);
                ++i;
            }
        }
        --i;
        swap(nums[begin],nums[i]);
        return i;
    }
}; 
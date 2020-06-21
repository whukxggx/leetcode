#include"head.h"


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<bool> visited(nums.size(),false);
        vector<int> tmp;
        dfs(vec,nums,visited,tmp);
        return vec;
    }
    void dfs(vector<vector<int>> &vec,vector<int> nums,vector<bool> &visited,vector<int> &tmp){
        if(tmp.size()==visited.size()){
            vec.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]==false){
                visited[i]=true;
                tmp.push_back(nums[i]);
                dfs(vec,nums,visited,tmp);
                tmp.pop_back();
                visited[i]=false;
            }
        }
    }
};
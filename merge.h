#include"head.h"

struct compares{
    bool operator()(vector<int> v1,vector<int> v2){
        return v1[0]<v2[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size=intervals.size();
        if(size==0||size==1)return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),compares());
        int i=0;
        while(i<size){
            int begin=intervals[i][0];
            int end=intervals[i][1];
            ++i;
            while(i<size&&intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
                ++i;
            }
            ans.push_back({begin,end});
        }
        return ans;
    }
};
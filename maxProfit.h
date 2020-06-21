#include"head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(size==0||size==1)return 0;
        if(size==2)return max(0,prices[1]-prices[0]);
        vector<int> dp(size,0);
        dp[0]=0;
        dp[1]=max(dp[0],prices[1]-prices[0]);
        int _min=min(prices[0],prices[1]);
        for(int i=2;i<size;++i){
            dp[i]=max(dp[i-1],prices[i]-_min);
            _min=min(_min,prices[i]);
        }
        return dp[size-1];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(size==0||size==1)return 0;
        if(size==2)return max(0,prices[1]-prices[0]);
        int maxProfit=0;
        int _min=prices[0];
        for(int i=1;i<size;++i){
            if(prices[i]-_min>maxProfit){
                maxProfit=prices[i]-_min;
            }
            _min=min(_min,prices[i]);
        }
        return maxProfit;
    }
};
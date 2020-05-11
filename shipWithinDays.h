#include"head.h"

//1011. 在 D 天内送达包裹的能力

class Solution {
public:
    int checkNDays(vector<int> weights,int capa){
        int d=0;
        int sum=0;
        for(int t:weights){
            sum+=t;
            if(sum>capa){
                sum=t;
                ++d;
            }
        }
        ++d;
        return d;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int maxw=weights[0];
        int sum=0;
        for(int t:weights){
            if(t>maxw)maxw=t;
            sum+=t;
        }
        int hi=sum;
        int lo=maxw;
        while(lo<hi){
            int mid=(lo+hi)/2;
            int d=checkNDays(weights,mid);
            if(d>D){
                lo=mid+1;
            }else if(d<=D){
                hi=mid;
            }
        }
        return lo;
    }
};
#include"head.h"




class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();
        vector<int>  vec(size+1);
        int t=1;
        for(int i=size-1;i>=0;--i){
            int val=digits[i]+t;
            t=val/10;
            vec[i+1]=val%10;
        }
        if(t==1)vec[0]=1;
        else{
            for(int i=0;i<size;++i){
                vec[i]=vec[i+1];
            }
            vec.resize(size);
        }
        return vec;
    }
};
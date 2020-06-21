//7. 整数反转

#include"head.h"

class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x!=0){
            int pop=x%10;
            x/=10;
            if(ans>INT_MAX/10||(ans==INT_MAX/10&&pop>7))return 0;
            if(ans<INT_MIN/10||(ans==INT_MIN/10&&pop<-8))return 0;
            ans*=10;
            ans+=pop;
        }
        return ans;
    }
};
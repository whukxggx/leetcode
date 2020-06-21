#include"head.h"


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1=version1.size();
        int size2=version2.size();
        int i=0, j=0;
        int sum1,sum2;
        while(i<size1||j<size2){
            sum1=0;sum2=0;
            while(i<size1&&version1[i]!='.')sum1=sum1*10+version1[i++]-'0';
            while(j<size2&&version2[j]!='.')sum2=sum2*10+version2[j++]-'0';
            if(sum1>sum2)return 1;
            else if(sum1<sum2)return -1;
            ++i;
            ++j;
        }
        return 0;
    }
};
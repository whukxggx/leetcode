#include"head.h"

class Solution {
public:
    string orderlyQueue(string S, int K) {
        int size=S.size();
        if(K>1){
            sort(S.begin(),S.end());
            return S;
        }
        string ans=S;
        for(int i=0;i<size;++i){
            S.push_back(S[0]);
            S=S.substr(1,size);
            if(ans>S)ans=S;
        }
        return ans;
    }
};
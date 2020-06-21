#include"head.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
        deque<int> de;
        while(x>0){
            int t=x%10;
            x=x/10;
            de.push_back(t);
        }
        while(de.size()!=0&&de.size()!=1){
            if(de.front()!=de.back())return false;
            de.pop_back();
            de.pop_front();
        }
        return true;
    }
};
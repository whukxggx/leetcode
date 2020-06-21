#include"head.h"



class Solution {
private:
    unordered_map<char,int> s_map,t_map;
public:
    bool check(){
        for(const auto &p:t_map){
            if(s_map[p.first]<p.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int size=s.size();
        for(const auto &p:t){
            ++t_map[p];
        }
        int l=0;int r=0;
        int len=INT_MAX;
        int ansL=-1;
        while(r<size){
            if(t_map.find(s[r])!=t_map.end()){
                ++s_map[s[r]];
            }
            while(check()&&l<=r){
                if(r-l+1<len){
                    len=r-l+1;
                    ansL=l;
                }
                if(t_map.find(s[l])!=t_map.end()){
                    --s_map[s[l]];
                }
                ++l;
            }
            ++r;
        }
        return ansL==-1?string():s.substr(ansL,len);
    }
};
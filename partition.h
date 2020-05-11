#include"head.h"


//131. 分割回文串

//回溯
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<string> vec_aux;
        if(s.size()==0)return vec;
        backTracking(s,vec,vec_aux);
        return vec;
    }
    void backTracking(string s,vector<vector<string>> &vec,vector<string> &vec_aux){
        if(s.size()==0)vec.push_back(vec_aux);
        for(int i=1;i<=s.size();++i){
            string sub1=s.substr(0,i);
            if(isPalind(sub1)){
                vec_aux.push_back(sub1);
                backTracking(s.substr(i,(s.size()-i)),vec,vec_aux);
                vec_aux.pop_back();
            }
        }
    }
    bool isPalind(string s){
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};
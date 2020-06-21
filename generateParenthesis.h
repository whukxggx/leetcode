#include"head.h"

//22. 括号生成

//回溯
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string s="";
        backTrack(vec,s,0,0,n);
        return vec;
    }
    void backTrack(vector<string> &vec,string s,int count1,int count2,int n){
        if(s.size()==2*n){
            vec.push_back(s);
            return;
        }
        if(count1<n){
            s.push_back('(');
            backTrack(vec,s,count1+1,count2,n);
            s.pop_back();
        }
        if(count2<count1){
            s.push_back(')');
            backTrack(vec,s,count1,count2+1,n);
            s.pop_back();
        }
    }
};
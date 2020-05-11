//活动选择 
#include<iostream>
#include<vector>
using namespace std;


//返回活动集合，注意假设结束时间已经排好序
vector<int> select_activity_max(vector<int> s,vector<int> f){
    int len=s.size();
    int m=0;
    vector<int> r;
    r.push_back(m);
    for(int k=1;k<len;k++){
        if(s[k]>=f[m]){
            r.push_back(k);
            m=k;
        }
    }
    return r;
}
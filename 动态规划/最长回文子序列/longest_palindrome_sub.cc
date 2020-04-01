//最长回文子序列
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longest_palin(string s){
    vector<vector<int>> v(s.size(),vector<int>(s.size()));
    int maxLen=1;
    int len=s.size();
    if(len==0)return 0;
    if(len==1) return 1;
    for(int i=0;i<len;i++){
        v[i][i]=1;
        if(i<len-1){
            if(s[i]==s[i+1]){
                v[i][i+1]=2;
                maxLen=2;
            }else{
                v[i][i+1]=1;
            }
        }
    }
    for(int l=3;l<=len;l++){
        for(int i=0;i<len-l+1;i++){
            int j=i+l-1;
            if(s[i]==s[j]){
                v[i][j]=v[i+1][j-1]+2;
                maxLen=v[i][j];
            }else{
                v[i][j]=max(v[i+1][j],v[i][j-1]);
            }
        }
    }
    return maxLen;
}
int main(){
    string s="character";
    int x=longest_palin(s);
    cout<<x<<endl;
    return 0;
}


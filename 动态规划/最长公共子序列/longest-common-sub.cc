//最长公共子序列
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int findLongest(string a,string b){
    const int alen=a.size();
    const int blen=b.size();
    vector<vector<int>> lc(alen,vector<int>(blen));//
/*
     int **p;
     p=new int*[alen];
     for(int i=0;i<alen;i++){
         *p=new int[blen];
     }
*/
    for(int i=0;i<alen;++i){
        lc[i][0]=0;
    }
    for(int i=0;i<blen;++i){
        lc[0][i]=0;
    }
    for(int i=1;i<alen;i++){
        for(int j=1;j<blen;j++){
            if(a[i]==b[j]){
                lc[i][j]=lc[i-1][j-1]+1;
            }else{
                lc[i][j]=max(lc[i-1][j],lc[i][j-1]);
            }
        }
    }
    return lc[alen-1][blen-1];
}   
 int main(){
    string a="$ACCGGTAC";
    string b="$CGATGCATCGATC";
    int x=findLongest(a,b);
    cout<<x<<endl;
    return 0;
 }


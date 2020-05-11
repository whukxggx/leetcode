#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int n=20;

const int m=70;//背包所能容纳的最多的重量
//w和v分别是重量和价值
//需要一个二维数组来辅助，其中i表示物品，j表示背包容量
vector<int> bag_0_1(vector<int> w,vector<int> v){
    vector<vector<int>> mem(n,vector<int>(m));//容量最多m-1
    
    //物品为第0个时
    for(int j=0;j<m;j++){
        if(j>w[0])
            mem[0][j]=v[0];
        else
            mem[0][j]=0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j<w[i]){
                mem[i][j]=mem[i-1][j];
            }
            else{
                mem[i][j]=max(mem[i-1][j],mem[i-1][j-w[i]]+v[i]);
            }
        }
    }
}
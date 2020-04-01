//编辑距离
//此处主要有三种操作，插入，替换，删除

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int minDistance(string word1, string word2) {
    int size1=word1.size();
    int size2=word2.size();
    vector<vector<int>> m(size1+1,vector<int>(size2+1));//注意让坐标从1真正开始
    m[0][0]=0;
    for(int i=1;i<=size1;i++){
        m[i][0]=m[i-1][0]+1;
    }
    for(int j=1;j<=size2;j++){
        m[0][j]=m[0][j-1]+1;
    }    
    for(int i=1;i<=size1;++i){
        for(int j=1;j<=size2;++j){
            if(word1[i-1]==word2[j-1]){//注意字符串中的位置是要从0开始的
                m[i][j]=m[i-1][j-1];
            }else{
                //注意m[i-1][j],m[i][j-1],m[i-1][j-1]分别对应删除，插入，替换操作
                int tmp=min(m[i-1][j],m[i][j-1]);
                m[i][j]=min(tmp,m[i-1][j-1])+1;
            }
        }
    }
}
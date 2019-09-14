#include<iostream>
using namespace std;
//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//思路，近似于数学归纳法，设已经知道为n-1及以下的时候是多少，能否知道n的时候
//是多少；

int numTrees(int n) {
	int g[n+1];
	g[0]=1;g[1]=1;
	for(int i=2;i<=n;i++)
		g[i]=0;
	for(int i=2;i<=n;i++)
		for(int j=0;j<i;j++)
			g[i]+=(g[j]*g[i-j-1]);
	return g[n];
}

int main(){
	int n=numTrees(3);
	cout<<n<<endl;
	return 0;
}

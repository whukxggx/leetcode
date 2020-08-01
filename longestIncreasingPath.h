#include"head.h"

//深度优先搜索
class Solution {
   public:
	  vector<vector<int>>  dirs={{1,0},{0,1},{-1,0},{0,-1}};
	  int longestIncreasingPath(vector<vector<int>>& matrix) {
		 int row=matrix.size();
		 if(row==0)return 0;
		 int col=matrix[0].size();
		 vector<vector<int>> memo(row,vector<int>(col));
		 int max_length=0;
		 for(int i=0;i<row;++i){
			for(int j=0;j<col;++j){
			   max_length=max(max_length,dfs(matrix,i,j,memo));
			}
		 }
		 return max_length;
	  }

	  int dfs(vector<vector<int>> &matrix,int m,int n,vector<vector<int>> &memo){
		 if(memo[m][n]!=0)return memo[m][n];//如果非空，已经计算过最长长度
		 int row=matrix.size();
		 int col=matrix[0].size();//此处假定矩阵不为空，因此检验需在外部
		 ++memo[m][n];
		 for(vector<int> dir:dirs){
			int _m=m+dir[0];int _n=n+dir[1];
			if(_m<row&&_n<col&&_m>=0&&_n>=0&&matrix[_m][_n]>matrix[m][n]){
			   memo[m][n]=max(memo[m][n],dfs(matrix,_m,_n,memo)+1);
			}
		 }
		 return memo[m][n];
	  }
};

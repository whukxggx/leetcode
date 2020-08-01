#include"head.h"

//54 螺旋矩阵
class Solution {
   public:
	  vector<int> spiralOrder(vector<vector<int>>& matrix) {
		 vector<int> ret;
		 int rows=matrix.size();
		 if(rows==0)return ret;
		 int cols=matrix[0].size();
		 if(cols==0)return ret;
		 vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
		 vector<vector<bool>> isVisited(rows,vector<bool>(cols));
		 for(auto x:isVisited){
			for(auto y:x){
			   y=false;
			}
		 }
		 int row=0,col=0;
		 int total=rows*cols;
		 int directionsIndex=0;
		 for(int i=0;i<total;++i){
			ret.push_back(matrix[row][col]);
			isVisited[row][col]=true;
			int nextRow=row+directions[directionsIndex][0];
			int nextCol=col+directions[directionsIndex][1];
			if(nextRow<0||nextRow>=rows||nextCol<0||nextCol>cols||isVisited[nextRow][nextCol]){
			   directionsIndex=(directionsIndex+1)%4;
			}
			row+=directions[directionsIndex][0];
			col+=directions[directionsIndex][1];
		 }
		 return ret;
	  }
};

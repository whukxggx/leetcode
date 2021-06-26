class Solution {
private:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    int rows,cols;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows=matrix.size();
        if(rows==0)return 0;
        cols=matrix[0].size();
        int ans=0;
        vector<vector<int>> memo(rows,vector<int>(cols,0));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                ans=max(ans,dfs(matrix,i,j,memo));
            }
        }
        return ans;
    }
    int  dfs(const vector<vector<int>> &matrix,int row,int col,vector<vector<int>> &memo){
        if(memo[row][col]!=0)return memo[row][col];

        ++memo[row][col];
        for(int i=0;i<4;++i){
            int newRow=row+dir[i][0];int newCol=col+dir[i][1];
            if(newRow>=0&&newRow<rows&&newCol>=0&&newCol<cols&&matrix[newRow][newCol]>matrix[row][col]){
                memo[row][col]=max(memo[row][col],dfs(matrix,newRow,newCol,memo)+1);
            }
        }
        return memo[row][col];
    }
};
#include"head.h"


class Solution {
   public:
	  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		 vector<vector<int>> vecRet;
		 sort(candidates.begin(),candidates.end());
		 vector<int> tmp;
		 dfs(vecRet,tmp,candidates,0,target);
		 return vecRet;
	  }
	  void dfs(vector<vector<int>>& vecp,vector<int> &vec,vector<int> candidates,int start,int target){
		 if(target==0){
			vecp.push_back(vec);
			return;
		 }
		 for(int i=start;i<candidates.size()&&target>=candidates[i];++i){
			if(i>start&&candidates[i]==candidates[i-1])continue;
			vec.push_back(candidates[i]);
			dfs(vecp,vec,candidates,i+1,target-candidates[i]);
			vec.pop_back();
		 }
	  }
};


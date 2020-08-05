#include"head.h"

class Solution {
   public:
	  vector<string> restoreIpAddresses(string s) {
		 vector<string> ret;
		 if(s.size()<4)return ret;
		 dfs(ret,s,0,0);
		 return ret;
	  }
	  void dfs(vector<string>& vec,string& s,int numPoints,int pos){
		 if(numPoints==3){
			if(valid(pos+1,s.size()-1,s)){
			   vec.push_back(s);
			}
			return;
		 }
		 for(int i=pos+1;i<s.size();++i){
			if(valid(pos,i,s)){
			   s.insert(s.begin()+i+numPoints,'.');
			   dfs(vec,s,numPoints+1,i+1);
			   s.erase(s.begin()+i+numPoints,1);
			}
		 }
		 return;
	  }
	  bool valid(int left,int right,string& s){
		 int sum=0;
		 if(left!=right&&s[left]=='0')return false;
		 for(int i=left;i<=right;++i){
			sum=sum*10+(s[i]-'0');
			if(sum>255)return false;
		 }
		 return true;
	  }
};

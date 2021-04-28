#include"head.h"


class Solution {
   public:
	  bool isMatch(string s, string p) {
		 return aux_Match(s,p);
	  }
	  bool aux_Match(string s,string p){
		 if(p.empty())return s.empty();
		 //p为*的情况
		 if(p[1]=='*'){
			if(!s.empty()&&(p[0]==s[0]||(p[0]=='.'))){
			   return  aux_Match(s.substr(1),p)
				  ||aux_Match(s.substr(0),p.substr(2));
			}
			else{
			   return aux_Match(s,p.substr(2));
			}
		 }
		 //p位为.的情况
		 if(!s.empty()&&s[0]==p[0]||(p[0]=='.'&&s.size()>0)){
			return aux_Match(s.substr(1),p.substr(1));
		 }
		 return false;
	  }
};


class Solution {
public:
	bool isMatch(string s, string p) {
		int ssize = s.size();
		int psize = p.size();

		//vec[i][j] s前i个是否与p前j个匹配
		vector<vector<bool>> vec(ssize+1, vector<bool>(psize+1));
		vec[0][0] = true;
		//i j 代表前几个
		for (int i = 0; i <= ssize; ++i) {
			for (int j = 1; j <= psize; ++j) {
				if (p[j-1] != '*') {
					if (i != 0) {
						if (s[i-1] == p[j - 1] || p[j - 1] == '.') {
							vec[i][j] = vec[i - 1][j - 1];
						}
					}
				}
				//p[j]是*时
				else {
					if (j >= 2) {
						vec[i][j] = vec[i][j - 2];
					}
					if (j >= 2 && i >= 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
						vec[i][j] = vec[i][j] || vec[i - 1][j];
					}
				}
			}
		}
		return vec[ssize][psize];
	}
};
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


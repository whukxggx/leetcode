#include"head.h"

class Solution {
   map<char,string> _map{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"}
	  ,{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
   public:
   vector<string> letterCombinations(string digits){
	  vector<string> ret;
	  string s="";
	  if(digits.size()==0)return ret;
	  backTrack(ret,s,digits,0);
	  return ret;
   }
   void backTrack(vector<string>& vec,string& s,string digits,int nextDigit){
	  if(nextDigit==digits.size()){
		 vec.push_back(s);
		 return;
	  }
	  for(int i=0;i<_map[digits[nextDigit]].size();++i){
		 s.push_back(_map[digits[nextDigit]][i]);
		 backTrack(vec,s,digits,nextDigit+1);
		 s.pop_back();
	  }
	  return;
   }
};

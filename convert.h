#include"head.h"


class Solution {
   public:
	  string convert(string s, int numRows) {
		 int size=s.size();
		 if(numRows==1)return s;
		 int arrSize=min(size,numRows);
		 vector<string> arr(arrSize);
		 int row=0;
		 bool isDown=false;
		 for(auto c: s){
			arr[row].push_back(c);
			if(row==0||row==numRows-1) isDown= !isDown;
			row+=(isDown?1:-1);
		 }
		 string ret;
		 for(auto str:arr){
			ret+=str;
		 }
		 return ret;
	  }
};


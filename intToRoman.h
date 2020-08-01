#include"head.h"


class Solution {
   public:
	  string intToRoman(int num) {
		 vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		 vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		 int size=symbols.size();
		 string ret;
		 for(int i=0;i<size;++i){
			while(num>=values[i]){
			   ret+=symbols[i];
			   num-=values[i];
			}
		 }
		 return ret;
	  }
};


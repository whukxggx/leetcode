#include"head.h"


class Solution {
   public:
	  int lengthOfLongestSubstringKDistinct(string s, int k) {
		 int left=0;
		 int right=0;
		 int size=s.size();
		 if(k==0)return 0;
		 if(size==0)return 0;
		 map<char,int> _map;
		 int maxlen=1;
		 int current_diff=0;
		 while(right<size){
			_map[s[right]]++;
			if(_map[s[right]]==1)current_diff++;
			right++;
			while(current_diff>k){
			   _map[s[left]]--;
			   if(_map[s[left]]==0)current_diff--;
			   left++;
			}
			maxlen=max(maxlen,right-left);
		 }
		 return maxlen;
	  }
};


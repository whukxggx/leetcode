#include"head.h"

typedef long long ll;
class Solution {
	private:
		int  getNumber(bool isneg,vector<char> vec){
			ll ans=0;
			int t=0;
			if(vec.size()==0)return 0;
			while(vec.size()!=0){
				ans+=((vec.back()-'0')*pow(10,t));
				++t;
				vec.pop_back();
			}
			if(isneg&&ans-1>INT_MAX){return INT_MIN;}
			else if(isneg) return (int)(-ans);
			else if(!isneg&&ans>=INT_MAX) return INT_MAX;
			else if(!isneg)return (int)ans;
			return (int)ans;
		}

	public:
		int myAtoi(string str) {
			int size=str.size();
			int ptr=0;
			while(ptr<size&&str[ptr]==' ')++ptr;
			bool isneg=false;
			if(ptr<size){
				//如果首个非空字母不是数字或者正负号，返回0
				if(!isdigit(str[ptr])&&str[ptr]!='+'&&str[ptr]!='-')return 0;
				if(str[ptr]=='-'){
					isneg=true;
					++ptr;
				}else if(str[ptr]=='+') ++ptr;
				while(ptr<size&&str[ptr]=='0')++ptr;
				vector<char> vec;
				while(ptr<size&&isdigit(str[ptr])){
					vec.push_back(str[ptr]);
					++ptr;
				}
				if(vec.size()>10&&isneg)return INT_MIN;
				if(vec.size()>10&&!isneg)return INT_MAX;
				return getNumber(isneg,vec);
			}else{
				return 0;
			}
			return 0;
		}
};


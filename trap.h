#include "head.h"
//面试题 17.21. 直方图的水量

//单调栈
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size=height.size();
        stack<int> s;
        int ans;
        for(int i=0;i<size;++i){
            while(!s.empty()&&height[s.top()]<height[i]){
                int x=s.top();
                s.pop();
                if(s.empty())break;
                int width=i-s.top()-1;
                int h=min(height[s.top()],height[i]);
                ans+=(h-height[x])*width;
            }
            s.push(i);
        }
        return ans;
    }
};

//直接每根柱子计算两边最高
int trap(vector<int> &height)
{
    int size=height.size();
    vector<int> left(size,0);
    vector<int> right(size,0);
    for(int i=1;i<size;++i){
        left[i]=max(left[i-1],height[i-1]);
    }
    for(int i=size-2;i>=0;--i){
        right[i]=max(right[i+1],height[i+1]);
    }
    int ans=0;
    for(int i=1;i<size-1;++i){
        int h=min(left[i],right[i]);
        ans+=max(0,h-height[i]);
    }
    return ans;
}
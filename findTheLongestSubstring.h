#include "head.h"

//1371. 每个元音包含偶数次的最长子字符串
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int size = s.size();
        vector<int> pos(1 << 5, -1); //用五位表示五个元音
        int ans = 0, status = 0;
        pos[0]=0;
        for (int i = 0; i < size; ++i)
        {
            //0代表偶数个，1代表奇数个
            if (s[i] == 'a')
            {
                status ^= (1 << 0);
            }
            else if (s[i] == 'e')
            {
                status ^= (1 << 1);
            }
            else if (s[i] == 'i')
            {
                status ^= (1 << 2);
            }
            else if (s[i] == 'o')
            {
                status ^= (1 << 3);
            }
            else if (s[i] == 'u')
            {
                status ^= (1 << 4);
            }
            if(pos[status]!=-1){
                ans=max(ans,i+1-pos[status]);
            }else{
                pos[status]=i+1;
            }
        }
        return ans;
    }
};
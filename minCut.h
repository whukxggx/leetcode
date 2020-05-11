#include"head.h"

//132. 分割回文串 II

int aux_mincut(string s, int start, vector<vector<bool>> dp) {
    if (dp[start][s.size() - 1])return 0;
    int minx = INT_MAX;
    for (int i = start; i < s.size(); ++i) {
        if (dp[start][i]) {
            minx = min(minx, 1 + aux_mincut(s, i + 1, dp));
        }
    }
    return minx;
}

    int minCut(string s) {
        vector<vector<string>> vec;
        vector<string> vec_aux;
        if (s.size() == 0)return 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
            if (i != s.size() - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
            else if(i!=s.size()-1) {
                dp[i][i + 1] = false;
            }
        }
        for (int l = 3; l <= s.size(); ++l) {
            for (int i = 0; i < s.size() - l + 1; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j]&&dp[i+1][j-1])dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
        return aux_mincut(s, 0, dp);
    }












//高手算法
/*
int minCut(String s) {
        if(s == null || s.length() <= 1)
            return 0;
        int len = s.length();
        int dp[] = new int[len];
        Arrays.fill(dp, len-1);
        for(int i = 0; i < len; i++){
            // 注意偶数长度与奇数长度回文串的特点
            mincutHelper(s , i , i , dp);  // 奇数回文串以1个字符为中心
            mincutHelper(s, i , i+1 , dp); // 偶数回文串以2个字符为中心
        }
        return dp[len-1];
    }
void mincutHelper(String s, int i, int j, int[] dp){
        int len = s.length();
        while(i >= 0 && j < len && s.charAt(i) == s.charAt(j)){
            dp[j] = Math.min(dp[j] , (i==0?-1:dp[i-1])+1);
            i--;
            j++;
        }
    }
*/
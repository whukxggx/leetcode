//最长回文子序列
    int longestPalindromeSubseq(string s) {
        int maxLen = 1;
        int size = s.size();
        if(size==0) return 0;
        if(size==1)return 1;
        vector<vector<int>> dp(size, vector<int>(size));
        //初始化长度为1和2的部分
        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
            if (i < size - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 2;
                    maxLen = 2;
                }else{
                    dp[i][i+1]=1;
                }
            }
        }
        //从长度为3的开始
        for (int len = 3; len <= size; ++len) {
            for (int i = 0; i + len - 1 < size; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1]+2;
                    maxLen=dp[i][j];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return maxLen;
    }
---------------------------------------------------------------------------------
    int countSubstrings(string s) {
        int N = s.size();
        int result = 0;
        for (int center = 0; center < 2 * N - 1; center++) { //可能总共有2*N-1个回文中心
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right <= N - 1 && s[left] == s[right]) {
                left--;
                right++;
                result++;
            }
        }
        return result;
    }
---------------------------------------------------------------------------------
//中心扩展
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = getLong(s, i, i);
            int len2 = getLong(s, i, i + 1);
            int len = max(len1, len2);
            if (len == 5) {
                cout << "1";
            }
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
    int getLong(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
---------------------------------------------------------------------------------
//动态规划
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;
        int size = s.size();
        if (size == 0 || size == 1) return s;
        vector<vector<int>> dp(size, vector<int>(size));
        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
            if (i < size - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 1;
                    start = i;
                    maxLen = 2;
                }
            }
        }
        //从长度为3的开始
        for (int len = 3; len <= size; ++len) {
            for (int i = 0; i + len - 1 < size; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
---------------------------------------------------------------------------------
manacher算法

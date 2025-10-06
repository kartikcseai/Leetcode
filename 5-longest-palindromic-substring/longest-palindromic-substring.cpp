class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLength = 1;
        
        // Substrings of length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        // Substrings of length 2
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        // Substrings of length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};

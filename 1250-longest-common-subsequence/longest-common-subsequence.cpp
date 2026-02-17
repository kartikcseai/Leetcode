class Solution {
public:
    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1 + LCS(s1, s2, i+1, j+1, dp);
        else return dp[i][j] = max(LCS(s1, s2, i+1, j, dp), LCS(s1, s2, i, j+1, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return LCS(s1, s2, 0, 0, dp);
    }
};
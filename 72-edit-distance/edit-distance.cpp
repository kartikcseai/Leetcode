class Solution {
public:
    int t[501][501];
    int helper_minDistance(string& s1, string& s2, int i, int j){
        int n = s1.length(), m = s2.length();
        if(i == n) return m - j; // insertion
        if(j == m) return n - i; // deletion
        if(t[i][j] != -1) return t[i][j];
        if(s1[i] == s2[j]) return t[i][j] = helper_minDistance(s1, s2, i + 1, j + 1);
        else {
            int insertC = helper_minDistance(s1, s2, i, j + 1);
            int deleteC = helper_minDistance(s1, s2, i + 1, j);
            int replaceC = helper_minDistance(s1, s2, i + 1, j + 1);
            return t[i][j] = 1 + min({insertC, deleteC, replaceC});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        memset(t, -1, sizeof(t));
        return helper_minDistance(s1, s2, 0, 0);
    }
};
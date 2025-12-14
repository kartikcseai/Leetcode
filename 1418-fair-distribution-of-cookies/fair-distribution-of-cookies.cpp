class Solution {
public:
    int ans = INT_MAX;
    void backtrack(vector<int>& cookies, vector<int>& kids, int idx) {
        if (idx == cookies.size()) {
            int unfairness = *max_element(kids.begin(), kids.end());
            ans = min(ans, unfairness);
            return;
        }
        for (int i = 0; i < kids.size(); i++) {
            kids[i] += cookies[idx];
            if (kids[i] < ans) backtrack(cookies, kids, idx + 1);
            kids[i] -= cookies[idx];
            if (kids[i] == 0) break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kids(k, 0);
        backtrack(cookies, kids, 0);
        return ans;
    }
};

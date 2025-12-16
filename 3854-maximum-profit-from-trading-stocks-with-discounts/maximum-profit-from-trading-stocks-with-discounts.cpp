class Solution {
public:
    vector<vector<int>> adj;
    pair<vector<int>, vector<int>> dp[161];
    bool solved[161];
    vector<int> merge(vector<int>& a, vector<int>& b) {
        int bud = a.size();
        vector<int> res(bud, -1e9);
        for (int i = 0; i < bud; i++) {
            if (a[i] < 0) continue;
            for (int j = 0; i + j < bud; j++) res[i + j] = max(res[i + j], a[i] + b[j]);
        }
        return res;
    }
    pair<vector<int>, vector<int>> solve(int node, vector<int>& present, vector<int>& future, int b){
        if (solved[node]) return dp[node];
        solved[node] = true;
        vector<int> dp0(b + 1, 0); 
        vector<int> dp1(b + 1, 0);
        for (int c : adj[node]) {
            auto [c0, c1] = solve(c, present, future, b);
            dp0 = merge(dp0, c0);
            dp1 = merge(dp1, c1);
        }
        vector<int> res0 = dp0;
        vector<int> res1 = dp0;
        int full = present[node], half = present[node] / 2;
        int profitFull = future[node] - full, profitHalf = future[node] - half;
        for (int i = full; i <= b; i++) res0[i] = max(res0[i], dp1[i - full] + profitFull);
        for (int i = half; i <= b; i++) res1[i] = max(res1[i], dp1[i - half] + profitHalf);
        return dp[node] = {res0, res1};
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy,int budget){
        adj.assign(n, {});
        memset(solved, false, sizeof(solved));
        for (auto& e : hierarchy) adj[e[0] - 1].push_back(e[1] - 1);
        auto res = solve(0, present, future, budget);
        return *max_element(res.first.begin(), res.first.end());
    }
};

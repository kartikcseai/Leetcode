class Solution {
    #define ll long long
    ll INF = 1e18;
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(4, -1)));

        function<ll(ll, ll, ll)> rec = [&](ll id, ll kk, ll st) ->ll {
            if(kk < 0) return -INF;
            if(id == n) return (st ? -INF : 0);
            if(dp[id][kk][st] != -1) return dp[id][kk][st];
            ll notTake = rec(id+1, kk, st);
            ll take1 = -INF, take2 = -INF;
            if(st == 0) {
                take1 = -prices[id] + rec(id+1, kk, 1);
                take2 = prices[id] + rec(id+1, kk, 2);
            } else if(st == 1) {
                take1 = prices[id] + rec(id+1, kk-1, 0);
            } else {
                take2 = -prices[id] + rec(id+1, kk-1, 0);
            }
            return dp[id][kk][st] = max({notTake, take1, take2});
        };

        return rec(0, k, 0);
    }
};
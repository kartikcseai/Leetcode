class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> s(n+1, 0), t(n+1, 0);
        for (int i=1;i<=n;i++) {
            s[i]=s[i-1]+(long long)prices[i-1]*strategy[i-1];
            t[i]=t[i-1]+prices[i-1];
        }
        long long ans = s[n]; 
        for (int i=k;i<=n;i++){
            long long originalSegmentProfit=s[i]-s[i-k];
            long long sellSegmentProfit=(t[i]-t[i-k/2]);
            long long totalWithMod=s[n]-originalSegmentProfit+sellSegmentProfit;
            ans=max(ans,totalWithMod);
        }
        return ans;
    }
};

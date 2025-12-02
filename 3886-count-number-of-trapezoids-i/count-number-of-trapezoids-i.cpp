class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;
        unordered_map<long long, long long> cnt; 
        for (auto &p : points) cnt[p[1]]++;
        vector<long long> pairs; 
        pairs.reserve(cnt.size());
        for (auto &kv : cnt) {
            long long c = kv.second;
            if (c >= 2) pairs.push_back( (c * (c - 1) / 2) % MOD ); 
            else pairs.push_back(0);
        }
        long long res = 0;
        long long sum = 0;
        for (long long num : pairs) {
            res = (res + sum * num % MOD) % MOD;
            sum = (sum + num) % MOD;
        }
        return (int)res;
    }
};

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
        vector<pair<int, long long>> st; // {value, count}
        for (int x : nums) {
            while (!st.empty() && st.back().first < x)st.pop_back();
            if (!st.empty() && st.back().first == x) {
                st.back().second++;
                ans += st.back().second;
            } else {
                st.push_back({x, 1});
                ans += 1;
            }
        }
        return ans;
    }
};

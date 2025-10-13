class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int freq = 0;
        int ans = 0;
        for (int x : nums) {
            if (++m[x] > freq) {
                freq = m[x];
                ans = 0;
            }
            if (m[x] == freq) {
                ans += m[x];
            }
        }
        return ans;
    }
};

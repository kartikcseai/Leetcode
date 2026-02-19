class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        if (k % 2 != 0 && n == 1) return -1;
        for (int i = 0; i < min(n, k + 1); i++) {
            if (k - i != 1) ans = max(ans, nums[i]);
        }
        return ans;
    }
};
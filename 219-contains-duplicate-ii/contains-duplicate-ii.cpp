class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        // Use two nested loops to compare each element with others within the range of k
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n && j <= i + k; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false; 
    }
};

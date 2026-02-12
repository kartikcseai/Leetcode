class Solution {
public:
    int dfs_helper(vector<int>& nums, int idx, int curr_sum, int target){
        if(idx == nums.size()) return (curr_sum == target) ? 1 : 0;
        int add = dfs_helper(nums, idx + 1, curr_sum + nums[idx], target);
        int sub = dfs_helper(nums, idx + 1, curr_sum - nums[idx], target);
        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs_helper(nums, 0, 0, target);
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0) return false; // If total sum is odd we can't partition it into two subsets
        int target=total_sum/2;
        vector<bool> dp(target+1, false);
        dp[0]=true;
        for (int num : nums) {
            // Iterate backward to avoid using the same number multiple times
            for (int j=target;j>=num;j--) {
                dp[j]=dp[j] || dp[j-num];
            }
        }
        return dp[target];
    }
};
class Solution {
public:
    bool check_divisibility(vector<int>& nums, int k) {
        int target_check=0;
        for (int x : nums) target_check+=x;
        return target_check%k==0;
    }
    int minOperations(vector<int>& nums, int k) {
        int target_check=0;
        for (int x:nums) target_check += x;
        int minimum_ans=0;
        if (target_check%k==0) return 0; 
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i]>0 && !check_divisibility(nums, k)) {
                nums[i]--;  
                minimum_ans++;
            }
            if (check_divisibility(nums, k)) break;
        }
        return minimum_ans;
    }
};

class Solution {
public:
    int max_sum_ka(vector<int>& nums){
        int max_sum = nums[0], curr_sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    int min_sum_ka(vector<int>& nums){
        int min_sum = nums[0], curr_sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr_sum = min(curr_sum + nums[i], nums[i]);
            min_sum = min(min_sum, curr_sum);
        }
        return min_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0 ;
        for(int i = 0; i < nums.size(); i++) total_sum += nums[i];
        int max_sum = max_sum_ka(nums);
        int min_sum = min_sum_ka(nums);
        int circular_sum = total_sum - min_sum;
        if (max_sum > 0) return max(max_sum, circular_sum);
        return max_sum;
    }
};
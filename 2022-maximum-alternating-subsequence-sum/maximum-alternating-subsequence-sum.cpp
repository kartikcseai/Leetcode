class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;
        for(int i=0;i<nums.size();i++) {
            long long new_even = max(even, odd + nums[i]);
            long long new_odd  = max(odd, even - nums[i]);
            even = new_even;
            odd = new_odd;
        }
        return even;
    }
};
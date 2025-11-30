class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        long long prefix_sum=0;
        vector<long long> v(k, LLONG_MAX/2);
        v[k-1]=0;
        for (int i=0;i<(int)nums.size();i++) {
            prefix_sum+=nums[i];
            int r=i%k;
            ans=max(ans, prefix_sum-v[r]);
            v[r]=min(v[r], prefix_sum);
        }
        return ans; 
    }
};
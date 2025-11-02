class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // sort by descending absolute value
        sort(nums.begin(), nums.end(), [](int a, int b){
            return llabs(a) > llabs(b);
        });
        long long ans = 0;
        int k = (n + 1) / 2;  //mid value
        for (int i = 0; i < k; ++i) {
            long long x = nums[i];
            ans += x * x;
        }
        for (int i = k; i < n; ++i) {
            long long x = nums[i];
            ans -= x * x;
        }
        return ans;
    }
};

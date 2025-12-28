class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1,0), prefix(n+1,0);
        dp[0]=1;
        prefix[0]=1;
        deque<int> mx, mn;
        int left=0;
        for (int right=0;right<n;right++) {
            while (!mx.empty() && nums[mx.back()]<=nums[right]) mx.pop_back();
            mx.push_back(right);
            while (!mn.empty() && nums[mn.back()]>=nums[right]) mn.pop_back();
            mn.push_back(right);
            while (nums[mx.front()]-nums[mn.front()]>k) {
                if (mx.front()==left) mx.pop_front();
                if (mn.front()==left) mn.pop_front();
                left++;
            }
            long long val=prefix[right];
            if (left>0) val=(val-prefix[left-1]+MOD)%MOD;
            dp[right+1]=val;
            prefix[right+1]=(prefix[right]+dp[right+1])%MOD;
        }

        return dp[n];
    }
};

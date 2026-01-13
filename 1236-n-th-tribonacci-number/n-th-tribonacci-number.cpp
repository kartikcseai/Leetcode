class Solution {
public:
    int tribonacci_dp_helper(int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=tribonacci_dp_helper(n-1,dp)+tribonacci_dp_helper(n-2,dp)+tribonacci_dp_helper(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return tribonacci_dp_helper(n,dp);
    }
};
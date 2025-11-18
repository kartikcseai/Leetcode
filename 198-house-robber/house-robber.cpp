class Solution {
public:
    vector<int> dp;
    int profit(vector<int>& arr, int i){
        if(i==arr.size()-1) return arr[i]; // single house
        if(i==arr.size()-2) return max(arr[i], arr[i+1]); // 2 houses
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(arr[i]+profit(arr, i+2), profit(arr, i+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1); // constraints mein limit se zadya ka size declare kar do -> CP 
        return profit(nums, 0);
    }
};
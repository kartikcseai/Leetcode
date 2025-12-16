class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int sum = 0, current = 0;
        for (int i=0;i<n;i++) { // Calculate the sum of the array and the initial F(0)
            sum+=nums[i];
            current+=i*nums[i];
        }
        int max_ret=current;
        for (int k=1;k<n;k++){ // Calculate F(k) for k=1 to n-1
            current+=sum-n*nums[n-k];
            max_ret=max(max_ret, current);
        }
        return max_ret;
    }
};

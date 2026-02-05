class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i = 0; i<nums.size(); i++){
            int targetIndex = (i + nums[i] % n + n) % n;
            result[i] = nums[targetIndex];
        }
        return result;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int max_peak = INT_MIN;
        int peak_index = 0;
        for(int i=0;i<n;i++) {
            if (nums[i]>max_peak) {
                max_peak=nums[i];
                peak_index=i;
            }
        }
        return peak_index;
    }
};

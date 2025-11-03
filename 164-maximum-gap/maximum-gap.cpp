class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int max_element = INT_MIN;
        int curr_differnce = 0;
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<n-1 ; i++){
            curr_differnce = nums[i]-nums[i+1];
            if(curr_differnce > max_element) max_element = curr_differnce;
            max_element = max(abs(curr_differnce),max_element);
        }
        return max_element;
    }
};
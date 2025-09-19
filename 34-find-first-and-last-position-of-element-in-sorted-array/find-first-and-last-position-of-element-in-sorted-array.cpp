class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1); // initialize with [-1, -1]
        if(nums.empty()) return ans;
        
        int n = nums.size();
        
        // Find first occurrence
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] >= target) hi = mid - 1;
            else lo = mid + 1;
            if(nums[mid] == target) ans[0] = mid;
        }
        
        // Find last occurrence
        lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] <= target) lo = mid + 1;
            else hi = mid - 1;
            if(nums[mid] == target) ans[1] = mid;
        }
        
        return ans;
    }
};

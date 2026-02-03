class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        int i = 0;
        while(i < n - 1 && nums[i] < nums[i + 1]) i++;
        if(i == 0) return false;
        int j = i;
        while(j < n - 1 && nums[j] > nums[j + 1]) j++;
        if(j == i || j == n - 1) return false;
        while(j < n - 1 && nums[j] < nums[j+1]) j++;
        return j == n - 1; 
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                ans = nums[i + 1];
                break;
            } 
        }
        if(ans == -1) return nums[0];
        else return ans;
    }
};
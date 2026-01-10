class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, zero_count=0, max_len=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0) zero_count++;
            while(zero_count>1){
                if(nums[left]==0) zero_count--;
                left++;}
            max_len=max(max_len,right-left);
        }
        return max_len;
    }
};
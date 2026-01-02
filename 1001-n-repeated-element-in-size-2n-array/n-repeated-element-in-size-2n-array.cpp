class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i=0;i<nums.size();i++){
            if(seen.find(nums[i])!=seen.end()) return nums[i];
            seen.insert(nums[i]);
        }
        return -1;
    }
};
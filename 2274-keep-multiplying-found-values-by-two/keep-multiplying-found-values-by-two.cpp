class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans_value=1;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        ans_value=original;
        while(s.find(ans_value)!=s.end()){
            ans_value=2*ans_value;
        }
        return ans_value;
    }
};
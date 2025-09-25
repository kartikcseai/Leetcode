class Solution {
public:
    void permutation(vector<int>& nums, int idx, vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            bool skip = false;
            for (int j = idx; j < i; j++) {
                if (nums[j] == nums[i]) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;            
            
            swap(nums[idx], nums[i]);
            permutation (nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permutation (nums, 0, ans);
        return ans;
    }
};
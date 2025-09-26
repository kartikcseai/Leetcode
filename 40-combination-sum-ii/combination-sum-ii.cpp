class Solution {
public:
    void helper(vector<int>& candidates, int start, vector<int>& comb, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // skip duplicates
            if (candidates[i] > target) break; // pruning since sorted
            comb.push_back(candidates[i]);
            helper(candidates, i + 1, comb, ans, target - candidates[i]); //  move to next index
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //  sort for skipping duplicates
        vector<vector<int>> ans;
        vector<int> comb;
        helper(candidates, 0, comb, ans, target);
        return ans;
    }
};

class Solution {
public:
    set<vector<int>> s;
    void helper_combination(vector<int>& candidates, int i, vector<int>& comb, vector<vector<int>>& ans, int target){
        if(i== candidates.size() || target<0) return; 
        if(target==0){
            if(s.find(comb)==s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }
        comb.push_back(candidates[i]);
        helper_combination(candidates, i+1, comb, ans, target-candidates[i]);
        helper_combination(candidates, i, comb, ans, target-candidates[i]);
        comb.pop_back();
        helper_combination(candidates, i+1, comb, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper_combination(candidates, 0, comb, ans, target);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    void combine_backtracking(int start, int n, int k){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        for(int i=start; i<=n-(k-curr.size())+1; i++){
            curr.push_back(i);
            combine_backtracking(i+1, n, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        combine_backtracking(1,n,k);
        return res;
    }
};
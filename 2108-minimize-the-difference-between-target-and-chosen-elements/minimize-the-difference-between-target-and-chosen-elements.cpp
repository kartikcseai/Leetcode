class Solution {
public:
    int m,n,t;
    vector<vector<int>> matrix;
    unordered_map<long long, int> memo;
    int dfs_helper(int i, int sum){
        if(i==m) return abs(sum-t);
        long long key=((long long)i<<32) | sum;
        if(memo.count(key)) return memo[key];
        int res=INT_MAX;
        for(int val:matrix[i]){
            res=min(res,dfs_helper(i+1,sum+val));
            if(res==0) break;
        }
        return memo[key]=res;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        matrix=mat; t=target;
        m=mat.size(); n=mat[0].size();
        return dfs_helper(0,0);
    }
};
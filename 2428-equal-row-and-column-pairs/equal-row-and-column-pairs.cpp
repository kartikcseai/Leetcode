class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string key;
            for(int x:grid[i]) key+=to_string(x)+",";
            mp[key]++;
        }
        int ans=0;
        for(int col=0;col<n;col++){
            string key;
            for(int row=0;row<n;row++) key+=to_string(grid[row][col])+",";
            ans+=mp[key];
        }
        return ans;
    }
};
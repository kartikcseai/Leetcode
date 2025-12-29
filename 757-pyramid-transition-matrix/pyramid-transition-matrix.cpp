class Solution {
public:
    unordered_map<string,bool> memo;
    unordered_map<string,vector<char>> mp;
    void buildNextRows(const string& row, int idx, string curr, vector<string>& res){
        if(idx==row.size()-1){
            res.push_back(curr);
            return;
        }
        string key;
        key+=row[idx];
        key+=row[idx+1];
        if(!mp.count(key)) return;
        for(char c:mp[key]) buildNextRows(row,idx+1,curr+c,res);
    }
    bool dfs_helper(string row){
        if(row.size()==1) return true;
        if(memo.count(row)) return memo[row];
        vector<string> nextRows;
        buildNextRows(row,0,"",nextRows);
        for(const string& next:nextRows) if(dfs_helper(next)) return memo[row]=true;
        return memo[row]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(const string& s:allowed) mp[s.substr(0,2)].push_back(s[2]);
        return dfs_helper(bottom);
    }
};
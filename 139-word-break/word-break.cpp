class Solution {
public:
    int t[301];
    unordered_set<string> us;
    bool helper_wordBreak(int idx, string& s){
        int n = s.length();
        if(idx >= n) return true;
        if(t[idx] != -1) return t[idx];
        if(us.find(s) != us.end()) return true;
        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx, l);
            if(us.find(temp) != us.end() && helper_wordBreak(idx + l, s)) return t[idx] = true;
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        for(auto& w : wordDict) us.insert(w);
        return helper_wordBreak(0, s);    
    }
};
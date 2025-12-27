class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int> m1,m2;
        for(char c:word1) m1[c]++;
        for(char c:word2) m2[c]++;
        if(m1.size()!=m2.size()) return false;
        for(const auto& m:m1) if(!m2.count(m.first)) return false;
        vector<int> v1,v2;
        for(const auto& c:m1) v1.push_back(c.second);
        for(const auto& c:m2) v2.push_back(c.second);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};
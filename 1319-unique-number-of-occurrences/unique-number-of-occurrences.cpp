class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int m:arr) um[m]++;
        unordered_set<int> s;
        for(const auto& m:um){
            if(s.count(m.second)) return false;
            s.insert(m.second);
        } 
        return true;
    }
};
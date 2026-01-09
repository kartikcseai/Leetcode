class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> seen;
        int count=1;
        for(char c:s){
            if(seen.count(c)){
                count++;
                seen.clear();
            }
            seen.insert(c);
        }
        return count;
    }
};
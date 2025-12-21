class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> um;
        for(char c:s) um[c]++;
        string result="";
        for(char c:order){
            while(um[c]>0){
                result+=c;
                um[c]--;
            }
        }
        for(auto& rem:um){
            while(rem.second>0){
                result+=rem.first;
                rem.second--;
            }
        }
        return result;
    }
};
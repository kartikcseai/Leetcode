class Solution {
public:
    int partitionString(string s) {
        vector<bool> seen(26,false);
        int count=1;
        for(char c:s){
            if(seen[c-'a']){
                count++;
                fill(seen.begin(),seen.end(),false);
            }
            seen[c-'a']=true;
        }
        return count;
    }
};
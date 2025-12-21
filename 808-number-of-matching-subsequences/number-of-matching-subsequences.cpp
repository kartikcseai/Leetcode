class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<string, int>>> buckets(26);
        for (string &word:words) buckets[word[0]-'a'].push_back({word, 0});
        int count=0;
        for (char c:s){
            int idx=c-'a';
            auto curr=buckets[idx];
            buckets[idx].clear();
            for (auto &p:curr){
                string &word=p.first;
                int pos=p.second+1;
                if(pos==word.size()) count++; 
                else buckets[word[pos]-'a'].push_back({word, pos});
            }
        }
        return count;
    }
};

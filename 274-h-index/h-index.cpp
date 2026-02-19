class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h_idx = 0;
        for(int i = 0; i < citations.size(); i++){
            if (citations[i] >= i + 1) h_idx = i + 1;
            else break;
        }
        return h_idx;
    }
};
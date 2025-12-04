class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x:nums)
            if(x%2==0) freq[x]++;
        int max_freq=0, most_frequent=-1;
        for(auto &p:freq){
            if (p.second>max_freq || (p.second==max_freq && p.first<most_frequent)) {
                max_freq = p.second;
                most_frequent = p.first;
            }
        }
        return most_frequent;
    }
};
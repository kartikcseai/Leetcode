class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i:nums) um[i]++;
        int rounds=0;
        for(auto& f:um){
            if(f.second==1) return -1;
            rounds+=f.second/3;
            if(f.second%3!=0) rounds++;
        }
        return rounds;
    }
};
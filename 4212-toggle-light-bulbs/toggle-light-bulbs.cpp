class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int, int> um;
        vector<int> result;
        for(auto& i : bulbs) um[i]++;
        for(auto& i : um) {
            if(i.second%2 != 0) result.push_back(i.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
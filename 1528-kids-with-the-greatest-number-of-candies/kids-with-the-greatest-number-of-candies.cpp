#include<algorithm>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int n=candies.size();
        int sum=0;
        int mx = *max_element(candies.begin(), candies.end());
        for(int i=0;i<n;i++){
            sum=extraCandies+candies[i];
            if(sum>=mx) result.push_back(true);
            else result.push_back(false);
            sum=0;
        }
        return result;
    }
};
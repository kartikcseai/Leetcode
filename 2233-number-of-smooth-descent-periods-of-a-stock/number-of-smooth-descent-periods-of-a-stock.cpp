class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 1;
        long long streak = 1;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1) streak++;
            else streak=1;
            count+=streak;
        }
        return count;
    }
};
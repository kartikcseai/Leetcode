class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int maxTime = neededTime[0];
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                totalCost += min(maxTime, neededTime[i]);
                maxTime = max(maxTime, neededTime[i]);
            } else maxTime = neededTime[i];
        }
        return totalCost;
    }
};

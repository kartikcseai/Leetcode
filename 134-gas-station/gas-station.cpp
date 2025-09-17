class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int start = 0, tank = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // If tank is negative, can't start from here or before
            if (tank < 0) {
                start = i + 1;  // try next station
                tank = 0;       // reset tank
            }
        }

        // If overall gas is less than cost, not possible
        return (totalGas < totalCost) ? -1 : start;
    }
};
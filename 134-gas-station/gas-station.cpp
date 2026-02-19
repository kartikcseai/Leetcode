class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0;
        int start = 0, tank = 0;
        for(int i = 0; i < gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        return (total_gas < total_cost) ? -1 : start;
    }
};
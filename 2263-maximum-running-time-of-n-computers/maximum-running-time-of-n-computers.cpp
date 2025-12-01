class Solution {
public:
    bool check_runtime(const vector<long long>& batteries, int n, long long time) {
        long long total_time = 0;
        for (long long battery : batteries) {
            total_time += min(battery, time); 
            if (total_time >= n * time) {
                return true; 
            }
        }
        return total_time >= n * time;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        vector<long long> batteriesLL(batteries.begin(), batteries.end());
        long long low = 0, high = 0;
        for (long long battery : batteriesLL) high += battery;
        while (low < high) {
            long long mid = low + (high - low + 1) / 2;
            if (check_runtime(batteriesLL, n, mid)) low = mid;  
            else high = mid - 1; 
        }
        return low;
    }
};

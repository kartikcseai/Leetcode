class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Step 1: sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        // Step 2: iterate through intervals
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // Compare with the last interval in merged
            if (intervals[i][0] <= merged.back()[1]) {
                // Overlap → merge
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap → add new interval
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};

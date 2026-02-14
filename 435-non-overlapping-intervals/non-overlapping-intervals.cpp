class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count = 0, i = 0, j = 1;
        while(j < n){
            vector<int> current_intervals = intervals[i];
            vector<int> next_intervals = intervals[j];
            int current_start = current_intervals[0], current_end = current_intervals[1];
            int next_start = next_intervals[0], next_end = next_intervals[1];
            if(next_start >= current_end){
                i = j;
                j++;
            } else {
                if (current_end <= next_end) {
                    j++;
                    count++;
                } else {
                    i = j;
                    j++;
                    count++;
                }
            }
        } 
        return count;
    }
};
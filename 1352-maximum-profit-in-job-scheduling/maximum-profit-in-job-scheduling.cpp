class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<array<int,3>> jobs(n);
        for(int i=0;i<n;i++) jobs[i]={endTime[i],startTime[i],profit[i]};
        sort(jobs.begin(),jobs.end()); // sort by endTime
        vector<int> dp(n);
        vector<int> ends(n); // For binary search, use a separate array of end times
        for(int i=0;i<n;i++) ends[i]=jobs[i][0];
        for(int i=0;i<n;i++){
            int e=jobs[i][0], s=jobs[i][1], p=jobs[i][2];
            // find non-conflicting jobs
            int j=upper_bound(ends.begin(), ends.end(),s)-ends.begin()-1;
            int includeProfit=p+(j>=0?dp[j]:0);
            int excludeProfit=(i>0?dp[i-1]:0);
            dp[i]=max(includeProfit,excludeProfit);
        }
        return dp[n-1];
    }
};
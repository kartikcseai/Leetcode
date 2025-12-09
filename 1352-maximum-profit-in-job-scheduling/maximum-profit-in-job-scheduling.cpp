class Solution {
public:
    vector<int> memo;
    int solve(int i, vector<vector<int>>& jobs) {
        if (i==jobs.size()) return 0;
        if (memo[i]!=-1) return memo[i];
        int start=jobs[i][0];
        int end=jobs[i][1];
        int profit=jobs[i][2];
        // binary search for next non-conflicting job
        int l=i+1, r=jobs.size()-1, nxt=jobs.size();
        while (l<=r) {
            int mid=(l+r)/2;
            if(jobs[mid][0]>=end) {
                nxt=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        int take=profit+solve(nxt, jobs);
        int skip=solve(i + 1, jobs);

        return memo[i]=max(take, skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> jobs(n);
        for (int i=0;i<n;i++)
            jobs[i]={startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end()); // sort by start time
        memo.assign(n, -1);
        return solve(0, jobs);
    }
};

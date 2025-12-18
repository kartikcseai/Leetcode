class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> result(n,-1);
        vector<pair<int,int>> starts;
        for(int i=0;i<n;i++) starts.push_back({intervals[i][0],i});
        sort(starts.begin(),starts.end());
        for(int i=0;i<n;i++){
            int end=intervals[i][1];
            int left=0, right=n-1;
            while(right>=left){
                int mid=left+(right-left)/2;
                if(starts[mid].first>=end){
                    result[i]=starts[mid].second;
                    right=mid-1;
                }
                else left=mid+1;
            }
        }
        return result;
    }
};
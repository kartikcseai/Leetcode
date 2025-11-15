class Solution {
public:
    typedef pair<int, vector<int>> pa;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pa> pq;
        for(vector<int> v:arr){
            int x=v[0], y=v[1];
            int distance=x*x+y*y;
            pq.push({distance,v});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            vector<int> v=pq.top().second;
            ans.push_back(v);
            pq.pop();
        }
        return ans;      
    }
};
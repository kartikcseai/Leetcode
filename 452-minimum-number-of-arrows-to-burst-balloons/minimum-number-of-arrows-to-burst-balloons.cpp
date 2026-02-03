    bool cmp(vector<int>& i1, vector<int>& i2){
        return i1[1] < i2[1];
    }
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), cmp);
        int last_end_time = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0] <= last_end_time) ans++;
            else last_end_time = points[i][1];
        }
        return points.size() - ans;
    }
};
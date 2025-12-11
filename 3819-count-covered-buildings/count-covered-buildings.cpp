class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> row_min_y, row_max_y;
        unordered_map<int, int> col_min_x, col_max_x;
        for(auto& b:buildings){
            int x=b[0], y=b[1];
            if(!row_min_y.count(x)) row_min_y[x]=row_max_y[x]=y;
            else{
                row_min_y[x]=min(row_min_y[x],y);
                row_max_y[x]=max(row_max_y[x],y);
            }
            if(!col_min_x.count(y)) col_min_x[y]=col_max_x[y]=x;
            else{
                col_min_x[y]=min(col_min_x[y],x);
                col_max_x[y]=max(col_max_x[y],x);
            }
        }
        int ans=0;
        for(auto& b:buildings){
            int x=b[0],y=b[1];
            bool has_left=(row_min_y[x]<y), has_right=(row_max_y[x]>y);
            bool has_down=(col_min_x[y]<x), has_up=(col_max_x[y]>x);
            if(has_left && has_right && has_down && has_up) ans++;
        }
        return ans;
    }
};
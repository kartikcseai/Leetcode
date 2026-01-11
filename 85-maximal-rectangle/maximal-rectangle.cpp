class Solution {
public:
    int largest_rectansgle_area(vector<int>& heights){
        stack<int> st;
        int max_area=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                int w=st.empty()?i:i-st.top()-1;
                max_area=max(max_area,h*w);
            }
            st.push(i);
        }
        heights.pop_back();
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m=matrix.size(),n=matrix[0].size();
        vector<int> heights(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') heights[j]+=1;
                else heights[j]=0;
            }
            ans=max(ans,largest_rectansgle_area(heights));
        }
        return ans;
    }
};
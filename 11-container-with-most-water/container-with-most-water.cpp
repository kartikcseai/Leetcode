class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ma = INT_MIN;
        while(l < r){
            int w = r - l;
            int h = min(height[l], height[r]);
            int ca = h * w;
            ma = max(ma, ca);
            height[l] < height[r] ? l++ : r--;
        }
        return ma;
    }
};
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> diff1, diff2;
        
        for (int n : set1) {
            if (set2.find(n) == set2.end())
                diff1.push_back(n);
        }
        
        for (int n : set2) {
            if (set1.find(n) == set1.end())
                diff2.push_back(n);
        }
        
        return {diff1, diff2};
    }
};
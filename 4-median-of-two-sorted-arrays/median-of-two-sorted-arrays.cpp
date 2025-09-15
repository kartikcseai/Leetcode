class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged(n + m);
        
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) 
                merged[k++] = nums1[i++];
            else 
                merged[k++] = nums2[j++];
        }
        while (i < n) merged[k++] = nums1[i++];
        while (j < m) merged[k++] = nums2[j++];
        
        int total = n + m;
        if (total % 2 == 1) {
            return merged[total / 2];  // odd
        } else {
            return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;  // even
        }
    }
};
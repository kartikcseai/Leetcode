class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int nextGreater = -1;
            bool found = false;

            // Find nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    // Look for next greater element to the right
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > nums1[i]) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break; // stop after finding nums1[i] in nums2
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};

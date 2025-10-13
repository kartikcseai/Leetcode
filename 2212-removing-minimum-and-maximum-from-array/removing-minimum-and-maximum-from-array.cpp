class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        
        if (minIndex > maxIndex) swap(minIndex, maxIndex);
        
        int option1 = maxIndex + 1;                // remove both from front
        int option2 = n - minIndex;                // remove both from back
        int option3 = (minIndex + 1) + (n - maxIndex); // one front, one back
        
        return min({option1, option2, option3});
    }
};

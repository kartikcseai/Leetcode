class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums) {
            if(seen.count(num)) {
                return num;  // duplicate found
            }
            seen.insert(num);
        }
        return -1; // should never reach here if problem guarantees a duplicate
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Find min and max element
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        // 2. Create frequency array with index shift
        int offset = -minVal;  // shift negatives to positive index
        vector<int> freq(maxVal - minVal + 1, 0);

        for(int num : nums) {
            freq[num + offset]++;  // shifted index
        }

        // 3. Store (freq, num) pairs
        vector<pair<int,int>> pairs;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] > 0) {
                pairs.push_back({freq[i], i - offset}); // shift back
            }
        }

        // 4. Sort by frequency (descending)
        sort(pairs.rbegin(), pairs.rend());

        // 5. Take top k numbers
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(pairs[i].second);
        }
        return result;
    }
};

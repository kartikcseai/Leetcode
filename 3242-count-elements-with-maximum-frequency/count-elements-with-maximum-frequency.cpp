class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }
        // Step 2: Find the maximum frequency
        int maxFreq = 0;
        for (int i = 1; i <= 100; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }
        // Step 3: Sum up all frequencies equal to maxFreq
        int total = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] == maxFreq) {
                total += freq[i];
            }
        }
        return total;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char current = s[right];

            // If character already exists and is inside the current window
            if (charIndex.find(current) != charIndex.end() && charIndex[current] >= left) {
                left = charIndex[current] + 1;
            }

            // Update last seen index of current character
            charIndex[current] = right;

            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

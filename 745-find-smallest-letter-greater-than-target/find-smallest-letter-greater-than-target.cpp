class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (letters[mid] <= target) 
                lo = mid + 1; 
            else 
                hi = mid - 1; 
        }
        if (lo == letters.size()) return letters[0];
        return letters[lo];
    }
};

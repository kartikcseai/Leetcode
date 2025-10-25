class Solution {
public:
    // Helper function to calculate total hours needed at a given eating speed k
    bool canFinish(const vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int pile : piles) {
            // Using (pile + k - 1) / k instead of ceil(pile / k) for integer math
            hours += (pile + k - 1) / k;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  // Minimum possible speed
        int right = *max_element(piles.begin(), piles.end()); // Maximum possible speed (largest pile)
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, mid, h)) {
                result = mid;     // mid works, try smaller speed
                right = mid - 1;
            } else {
                left = mid + 1;   // mid too slow, increase speed
            }
        }

        return result;
    }
};
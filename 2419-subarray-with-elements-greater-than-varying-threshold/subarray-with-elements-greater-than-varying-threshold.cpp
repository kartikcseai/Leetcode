class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n), right(n);

        // Previous smaller element index
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next smaller element index
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Check each nums[i] as minimum in its span
        for (int i = 0; i < n; i++) {
            int span = right[i] - left[i] - 1;  // max length where nums[i] is min
            // Minimal length required so that nums[i] * k > threshold
            int k_min = threshold / nums[i] + 1;
            if (k_min <= span) return k_min;   // return the valid subarray length
        }
        return -1;
    }
};

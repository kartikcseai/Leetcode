class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;  // store indices, not characters
        st.push(-1);    // base index to handle edge cases
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // reset base index
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

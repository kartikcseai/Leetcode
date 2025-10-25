class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Handle potential collisions
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (st.top() < -a) {
                    // Right-moving asteroid is smaller → destroyed
                    st.pop();
                    continue;
                } else if (st.top() == -a) {
                    // Equal size → both destroyed
                    st.pop();
                }
                destroyed = true;
                break;
            }

            // If current asteroid survives, push it
            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector (reverse order)
        vector<int> result(st.size());
        for (int i = (int)st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
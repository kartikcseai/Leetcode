class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
    vector<int> dfs(TreeNode* node, int distance, int& ans) {
        if (!node) return vector<int>(distance + 1, 0);
        if (!node->left && !node->right) {
            vector<int> v(distance + 1, 0);
            v[1] = 1;
            return v;
        }

        vector<int> L = dfs(node->left, distance, ans);
        vector<int> R = dfs(node->right, distance, ans);
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance) {
                    ans += L[i] * R[j];
                }
            }
        }
       vector<int> cur(distance + 1, 0);
        for (int i = 1; i < distance; i++) {
            cur[i + 1] += L[i];
            cur[i + 1] += R[i];
        }
        return cur;
    }
};

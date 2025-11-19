class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root==NULL) return -1;
        vector<long long> sums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long levelSum = 0;
            int sz=q.size();
            for (int i=0;i<sz;i++) {
                TreeNode* node=q.front();
                q.pop();
                levelSum+=node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            sums.push_back(levelSum);
        }
        if(k>(int)sums.size()) return -1;
        sort(sums.begin(), sums.end());
        return sums[sums.size()-k];
    }
};

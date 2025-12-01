class Solution {
public:
    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void last_level_f(TreeNode* root, int current_level, int last_level, vector<int>& last_level_elements) {
        if (root == NULL) return;
        if (current_level == last_level) last_level_elements.push_back(root->val);
        last_level_f(root->left, current_level + 1, last_level, last_level_elements);
        last_level_f(root->right, current_level + 1, last_level, last_level_elements);
    }
    int findBottomLeftValue(TreeNode* root) {
        int n = levels(root);
        int last_level = n - 1; 
        vector<int> last_level_elements;
        last_level_f(root, 0, last_level, last_level_elements);
        return last_level_elements[0];
    }
};

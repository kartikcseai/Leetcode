class Solution {
public:
    int getHeight(TreeNode* node, bool left) {
        int height = 0;
        while (node) {
            height++;
            node = left ? node->left : node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;  // (2^h) - 1 nodes
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

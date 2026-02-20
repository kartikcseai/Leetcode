class Solution {
public:
    void helper_invertTree(TreeNode* root){
        if(root == NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        helper_invertTree(root->left);
        helper_invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper_invertTree(root);
        return root;
    }
};
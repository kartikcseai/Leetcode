class Solution {
public:
    void helper(TreeNode* root, int val, int depth, int current_depth){
        if(root==NULL) return;
        if(current_depth==depth-1){
            TreeNode* old_left=root->left;
            TreeNode* old_right=root->right;
            root->left=new TreeNode(val);
            root->left->left=old_left;
            root->right=new TreeNode(val);
            root->right->right=old_right;
            return;
        }
        helper(root->left, val, depth, current_depth+1);
        helper(root->right, val, depth, current_depth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        helper(root, val, depth, 1);
        return root;
    }
};
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int total_sum = 0;
        if(root->left){
            if(!root->left->left && !root->left->right) total_sum += root->left->val;
            else total_sum += sumOfLeftLeaves(root->left);
        }        
        total_sum += sumOfLeftLeaves(root->right);
        return total_sum;
    }
};
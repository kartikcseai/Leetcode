class Solution {
public:
    int min_Difference=INT_MAX;
    int prev_val=-1; // use -1 -> to indicate no value is stored
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev_val!=-1) min_Difference=min(min_Difference, root->val-prev_val);
        prev_val=root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_Difference;
    }
};
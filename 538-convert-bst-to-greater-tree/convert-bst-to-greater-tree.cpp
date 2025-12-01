class Solution {
public:
    void inorder(TreeNode* root, int &sum){
        if(root==NULL) return;
        inorder(root->right, sum);
        root->val+=sum;
        sum=root->val;
        inorder(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        inorder(root, sum);
        return root;       
    }
};
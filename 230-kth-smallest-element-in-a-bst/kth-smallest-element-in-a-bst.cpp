class Solution {
public:
    void inorderTraversal(TreeNode* root, int &result, int &k){
        if(root==NULL) return;
        inorderTraversal(root->left, result, k);
        k--;
        if(k==0){
            result=root->val;
            return;
        }
        inorderTraversal(root->right, result, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result=-1;
        inorderTraversal(root, result, k);
        return result;

    }
};
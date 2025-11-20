class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void preorder(TreeNode* root, int level, vector<int>& ans){
        if(root==NULL) return;
        ans[level]=root->val;
        preorder(root->left, level+1, ans);
        preorder(root->right, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root, 0, ans);
        return ans;
    }
};
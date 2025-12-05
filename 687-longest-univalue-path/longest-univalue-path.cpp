class Solution {
public:
    int helper(TreeNode* root, int &ans){
        if(root==NULL) return 0;
        int left_len=helper(root->left, ans), right_len=helper(root->right, ans);
        int left_path=0, right_path=0;
        if(root->left && root->left->val==root->val) left_path=left_len+1;
        if(root->right && root->right->val==root->val) right_path=right_len+1;
        ans=max(ans, left_path+right_path);
        return max(left_path,right_path);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};
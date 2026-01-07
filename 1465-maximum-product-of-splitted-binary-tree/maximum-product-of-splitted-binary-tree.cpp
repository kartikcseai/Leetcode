class Solution {
public:
    long long total=0;
    long long ans=0;
    const int MOD=1e9+7;
    long long getTotalSum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+getTotalSum(root->left)+getTotalSum(root->right);
    }
    long long dfs_helper(TreeNode* root){
        if(root==NULL) return 0;
        long long subSum=root->val+dfs_helper(root->left)+dfs_helper(root->right);
        ans=max(ans,subSum*(total-subSum));
        return subSum;
    }
    int maxProduct(TreeNode* root) {
        total=getTotalSum(root);
        dfs_helper(root);
        return ans%MOD;
    }
};
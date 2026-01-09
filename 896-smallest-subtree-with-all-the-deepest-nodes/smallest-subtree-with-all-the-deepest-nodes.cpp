class Solution {
public:
    pair<int,TreeNode*> dfs_helper(TreeNode* root){
        if(root==NULL) return{0,NULL};
        auto left=dfs_helper(root->left);
        auto right=dfs_helper(root->right);
        if(left.first==right.first) return {left.first+1,root};
        else if(left.first>right.first) return {left.first+1,left.second};
        else return {right.first+1,right.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs_helper(root).second;
    }
};
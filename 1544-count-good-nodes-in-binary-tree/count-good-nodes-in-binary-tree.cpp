class Solution {
public:
    int dfs_helper(TreeNode* root, int maxS){
        if(root==NULL) return 0;
        int good=0;
        if(root->val>=maxS){
            good=1;
            maxS=root->val;
        }
        return good+dfs_helper(root->left,maxS)+dfs_helper(root->right,maxS);
    }
    int goodNodes(TreeNode* root) {
        return dfs_helper(root,root->val);
    }
};
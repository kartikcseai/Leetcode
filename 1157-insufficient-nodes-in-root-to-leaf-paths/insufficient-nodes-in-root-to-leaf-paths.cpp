class Solution {
public:
    bool helper_func(TreeNode* root, int sum, int limit){
        if(root==NULL) return true; // treat NULL as insufficient
        sum+=root->val;
        if(root->left==NULL && root->right==NULL) return sum<limit; // if leaf exist -> check if path sum meets the limit
        bool check_left=helper_func(root->left, sum, limit); // check further for left subtree 
        bool check_right=helper_func(root->right, sum, limit); // check further for right subtree
        // insufficient children -> remove
        if(check_left==true) root->left=NULL;
        if(check_right==true) root->right=NULL;
        // If both children are bad, this node is insufficient too
        return check_left && check_right;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // if root is insufficient then delete the whole tree
        return helper_func(root, 0, limit)?NULL:root;
    }
};
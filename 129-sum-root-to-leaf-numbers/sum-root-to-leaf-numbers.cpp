/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, long long current_value){
        if(root==NULL) return 0;
        current_value=current_value*10+root->val;
        if(root->left==NULL && root->right==NULL) return current_value;
        return helper(root->left, current_value) + helper(root->right, current_value);
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};
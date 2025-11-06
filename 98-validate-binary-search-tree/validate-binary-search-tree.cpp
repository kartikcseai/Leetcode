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
    bool helper(TreeNode* root, TreeNode* mi, TreeNode* mx){
        if(root==NULL) return true;
        if(mi!=NULL && root->val<=mi->val) return false;
        if(mx!=NULL && root->val>=mx->val) return false;
        return helper(root->left, mi, root) && helper(root->right, root, mx);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
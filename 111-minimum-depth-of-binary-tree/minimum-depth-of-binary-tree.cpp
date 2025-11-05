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
    int levels(TreeNode* root){
        if(root==NULL) return 1;
        if(root->left==NULL) return 1+levels(root->right);
        else if(root->right==NULL) return 1+levels(root->left);
        else return 1+min(levels(root->left), levels(root->right));
    }
    int minDepth(TreeNode* root) {
        return levels(root)-1;
    }
};
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
    int maxDia=0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia, dia);
        helper(root->left);
        helper(root->right);
        return maxDia;
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia=0;
        return helper(root);
    }
};
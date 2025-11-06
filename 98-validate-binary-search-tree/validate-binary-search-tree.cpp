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
    long long maxTree(TreeNode* root){
        if(root==NULL) return LLONG_MIN;
        return max((long long)(root->val), max(maxTree(root->left), maxTree(root->right))); 
    }
    long long minTree(TreeNode* root){
        if(root==NULL) return LLONG_MAX;
        return min((long long)(root->val),min(minTree(root->left), minTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        else if(root->val <= maxTree(root->left)) return false;
        else if(root->val >= minTree(root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
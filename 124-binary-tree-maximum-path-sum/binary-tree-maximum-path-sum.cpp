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
    int findMaxSum(TreeNode* root, int &maxSum){
        if(root==NULL) return 0;
        int leftSum=max(0,findMaxSum(root->left, maxSum));
        int rightSum=max(0,findMaxSum(root->right, maxSum));
        int currentPathSum=root->val + leftSum + rightSum;
        maxSum=max(maxSum,currentPathSum);
        return root->val+max(leftSum,rightSum);

    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findMaxSum(root, maxSum);
        return maxSum;
    }
};
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
    void inorder(TreeNode* root, vector<TreeNode*>& ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> ans;
        inorder(root, ans);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right=ans[i+1];
            ans[i]->left=NULL;
        }
        ans[n - 1]->left=NULL;
        ans[n - 1]->right=NULL;
        return ans[0]; 
    }
};
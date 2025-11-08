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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* build(vector<int>& ans, int lo, int hi){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* root = new TreeNode(ans[mid]); 
        root->left=build(ans, lo, mid-1);
        root->right=build(ans, mid+1, hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return build(ans, 0,ans.size()-1);
    }
};
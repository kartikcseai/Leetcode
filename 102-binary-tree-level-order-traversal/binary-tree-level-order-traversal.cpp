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
        if(root==NULL) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    void nthLevel(TreeNode* root, int curr_level, int level, vector<int>& ans_array){ 
        if(root==NULL) return;
        if(curr_level==level){
            ans_array.push_back(root->val);
            return;
        } 
        nthLevel(root->left, curr_level+1, level, ans_array); 
        nthLevel(root->right, curr_level+1, level, ans_array);
    }
    void levelOrder(TreeNode* root, vector<vector<int>>& ans){
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int> ans_array;
            nthLevel(root, 1, i, ans_array);
            ans.push_back(ans_array);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root,ans);
        return ans;
    }
};
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
    void nthLevelLtoR(TreeNode* root, int curr_level, int level, vector<int>& ans_array){ 
        if(root==NULL) return;
        if(curr_level==level){
            ans_array.push_back(root->val);
            return;
        } 
        nthLevelLtoR(root->left, curr_level+1, level, ans_array); 
        nthLevelLtoR(root->right, curr_level+1, level, ans_array);
    }
    void nthLevelRtoL(TreeNode* root, int curr_level, int level, vector<int>& ans_array){ 
        if(root==NULL) return;
        if(curr_level==level){
            ans_array.push_back(root->val);
            return;
        } 
        nthLevelRtoL(root->right, curr_level+1, level, ans_array);
        nthLevelRtoL(root->left, curr_level+1, level, ans_array); 
    }
    void levelOrder(TreeNode* root, vector<vector<int>>& ans){
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int> ans_array;
            if(i%2==0) nthLevelRtoL(root, 1, i, ans_array);
            else nthLevelLtoR(root, 1, i, ans_array);
            ans.push_back(ans_array);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root,ans);
        return ans;
    }
};
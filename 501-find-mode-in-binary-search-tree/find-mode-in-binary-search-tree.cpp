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
    void inorderTraversal(TreeNode* root, vector<int>& ans, int &maxCount, int &currCount, TreeNode*& prev){
        if(root==NULL) return;
        inorderTraversal(root->left, ans,maxCount,currCount, prev);
        if (prev && root->val==prev->val) currCount++;
        else currCount=1;
        if(currCount>maxCount){
            maxCount=currCount;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(currCount==maxCount) ans.push_back(root->val);
        prev=root;
        inorderTraversal(root->right, ans, maxCount,currCount, prev);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        TreeNode* prev=NULL;
        int maxCount=0, currCount=0;
        inorderTraversal(root, ans,maxCount,currCount,prev);
        return ans;
    }
};
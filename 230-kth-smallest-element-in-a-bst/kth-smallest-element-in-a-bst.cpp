
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans[k-1];

    }
};
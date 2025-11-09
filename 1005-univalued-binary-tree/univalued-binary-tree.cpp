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
    void inorder_traversal(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorder_traversal(root->left, ans);
        ans.push_back(root->val);
        inorder_traversal(root->right, ans);
    }
    bool isUnivalTree(TreeNode* root) {
        vector<int> ans;
        inorder_traversal(root, ans);
        int first_element=ans[0];
        bool flag=false;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==first_element) flag=true;
            else {
                flag=false;
                break;
            }
        }
        if(flag==true) return true;
        else return false;
    }
};
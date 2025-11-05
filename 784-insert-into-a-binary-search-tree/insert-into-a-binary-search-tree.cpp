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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val > val){ // go left
            if(root->left==NULL){ // attach it here
                TreeNode* temp=new TreeNode(val);
                root->left=temp;
                return root;
            }
            else insertIntoBST(root->left, val);
        }
        else{ // root->val < val :  go right
            if(root->right==NULL){ // attach it here
                TreeNode* temp=new TreeNode(val);
                root->right=temp;
                return root;
            }
            else insertIntoBST(root->right, val);
        }
        return root;
    }
};
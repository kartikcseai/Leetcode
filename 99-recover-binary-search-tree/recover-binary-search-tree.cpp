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
    void correctBST(TreeNode* root, TreeNode*& first, TreeNode*& middle, TreeNode*& last, TreeNode*& prev){
        if (root==NULL) return;
        correctBST(root->left, first, middle, last, prev); // for left sub-tree
        if(prev && root->val < prev->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        correctBST(root->right, first, middle, last, prev); // for right sub-tree


    }
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL, *middle=NULL, *last=NULL, *prev=NULL;
        correctBST(root, first, middle, last, prev);
        if(first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};
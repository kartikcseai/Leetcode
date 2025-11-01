/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool existsInTree(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return existsInTree(root->left, target) || existsInTree(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(p==root || q==root) return root;
      else if(existsInTree(root->left, p) && existsInTree(root->right, q)) return root; // p left mein aur q right exist karta hai 
      else if(existsInTree(root->right, p) && existsInTree(root->left, q)) return root; // p right mein hai aur q left mein hai 
      else if(existsInTree(root->left, p) && existsInTree(root->left, q)) return lowestCommonAncestor(root->left, p, q); // p left mein hai but q right mein nahi hai toh q bhi right mein hi hoga -> recursion call
      else return lowestCommonAncestor(root->right, p, q);

    }
};
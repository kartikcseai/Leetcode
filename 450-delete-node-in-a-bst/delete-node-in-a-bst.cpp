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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right!=NULL){
            pred=pred->right;
        }
        return pred;
    }   
    TreeNode* ios(TreeNode* root){
        TreeNode* succ=root->right;
        while(succ->left!=NULL){
            succ=succ->left;
        }
        return succ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // case 1 : No child
            if(root->left==NULL && root->right==NULL) return NULL; 
            // case 2 : 1 child 
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
            // case 3 : 2 child  
            if(root->left!=NULL && root->right!=NULL){
                // replace the root with its pred/succ
                TreeNode* succ = ios(root);
                root->val=succ->val;
                root->right=deleteNode(root->right, succ->val);
            }
        }
        else if (root->val > key){ // go left
            root->left=deleteNode(root->left,key);
        }
        else{ // root->val<val : go right
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};
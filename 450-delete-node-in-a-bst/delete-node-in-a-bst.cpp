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
            if(root->left==NULL && root->right==NULL) return NULL; 
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* succ = ios(root);
                root->val=succ->val;
                root->right=deleteNode(root->right, succ->val);
            }
        }
        else if (root->val > key) root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key);
        return root;
    }
};
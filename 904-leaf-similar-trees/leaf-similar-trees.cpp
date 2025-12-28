class Solution {
public:
    void get_leaves(TreeNode* root, vector<int>& leaf){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);
            return;
        }
        get_leaves(root->left, leaf);
        get_leaves(root->right, leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1,leaves2;
        get_leaves(root1, leaves1);
        get_leaves(root2, leaves2);
        return leaves1==leaves2;
    }
};
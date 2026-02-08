class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int LST_height = height(root->left);
        int RST_height = height(root->right);
        if(LST_height==-1 || RST_height==-1 || abs(LST_height-RST_height)>1) return -1;
        return 1+max(LST_height, RST_height);
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};
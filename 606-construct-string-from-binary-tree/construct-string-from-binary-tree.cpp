class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==NULL) return "";
        string result=to_string(root->val);
        if(root->left!=NULL) result+="("+tree2str(root->left)+")";
        else if(root->right!=NULL) result+="()";
        if(root->right!=NULL) result+="("+tree2str(root->right)+")";
        return result;
    }
};
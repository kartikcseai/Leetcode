class Solution {
public:
    TreeNode* build_tree_helper(vector<int>& preorder, int pre_lo, int pre_hi, vector<int>& inorder, int in_lo, int in_hi){
        if(pre_lo>pre_hi) return NULL;
        TreeNode* root=new TreeNode(preorder[pre_lo]);
        if(pre_lo==pre_hi) return root;
        int i=in_lo;
        while(i<=in_hi){
            if(inorder[i]==preorder[pre_lo]) break;
            i++;
        }
        int left_count=i-in_lo, right_count=in_hi-i;
        root->left=build_tree_helper(preorder, pre_lo+1, pre_lo+left_count, inorder, in_lo, i-1);
        root->right=build_tree_helper(preorder, pre_lo+left_count+1, pre_hi, inorder, i+1, in_hi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build_tree_helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};
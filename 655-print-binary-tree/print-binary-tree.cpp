class Solution {
public:
    int getheight(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(getheight(root->left),getheight(root->right));
    }
    void dfs_traversal(TreeNode* root, int row, int col, vector<vector<string>>& result, int height){
        if(root==NULL) return;
        result[row][col]=to_string(root->val);
        int offset=pow(2,height-row-2); // calculate spacing between nodes at next level 
        if(root->left!=NULL) dfs_traversal(root->left, row+1, col-offset, result, height);
        if(root->right!=NULL) dfs_traversal(root->right, row+1, col+offset, result, height);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int row_m=getheight(root); // height
        int col_n=pow(2,row_m)-1; // width
        vector<vector<string>> result(row_m, vector<string>(col_n, ""));
        dfs_traversal(root, 0, (col_n-1)/2, result, row_m);
        return result;
    }
};
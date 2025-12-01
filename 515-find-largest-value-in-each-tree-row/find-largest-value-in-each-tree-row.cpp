class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    void level_printing(TreeNode* root, int current_level, int level, vector<int>& temp){
        if(root==NULL) return;
        if(current_level==level) temp.push_back(root->val);
        level_printing(root->left, current_level+1, level, temp);
        level_printing(root->right, current_level+1, level, temp);
    }
    vector<int> largestValues(TreeNode* root) {
        int n=levels(root);
        vector<int> result;
        int level_max;
        for(int i=0;i<n;i++){
            vector<int> temp;
            level_printing(root, 0, i, temp);
            level_max=*max_element(temp.begin(), temp.end());
            result.push_back(level_max);
        }
        return result;
    }
};
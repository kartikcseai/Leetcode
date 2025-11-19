class Solution {
public:
        int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    void nthLevel(TreeNode* root, int curr_level, int level, vector<int>& ans_array){ 
        if(root==NULL) return;
        if(curr_level==level){
            ans_array.push_back(root->val);
            return;
        } 
        nthLevel(root->left, curr_level+1, level, ans_array); 
        nthLevel(root->right, curr_level+1, level, ans_array);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int> ans_array;
            nthLevel(root, 1, i, ans_array);
            long long sum = 0;
            for(int x : ans_array) sum += x;
            ans.push_back((double)sum / ans_array.size());
        }
        return ans;
    }
};
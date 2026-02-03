class Solution {
public:
    int max_depth(Node* root){
        if(root == NULL) return 0; 
        int depth = 0;
        for(Node* child : root->children) depth = max(depth, max_depth(child));
        return depth + 1;
    }
    void level_order_helper(Node* root, int curr_level, int total_level, vector<int>& level){
        if(root == NULL) return;
        if(curr_level == total_level){
            level.push_back(root->val);
            return;
        }
        for(Node* child : root->children) level_order_helper(child, curr_level + 1, total_level, level);
    }
    void nth_level(Node* root, vector<vector<int>>& ans){
        int n = max_depth(root);
        for(int i=1; i<=n; i++){
            vector<int> level;
            level_order_helper(root, 1, i, level);
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        nth_level(root, ans);
        return ans;
    }
};
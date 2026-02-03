class Solution {
public:
    void N_aryPreorder(Node* root, vector<int>& ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        for(Node* children : root->children) N_aryPreorder(children, ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        N_aryPreorder(root, ans);
        return ans;
    }
};
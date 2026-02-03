class Solution {
public:
    void Nary_postorder(Node* root, vector<int>& ans){
        if(root == NULL) return;
        for(Node* child : root->children) Nary_postorder(child, ans);
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        Nary_postorder(root, ans);
        return ans;        
    }
};
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        stack<TreeNode*> st, post;
        st.push(root);
        while(!st.empty()) {
            TreeNode* temp = st.top(); st.pop();
            post.push(temp);
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        unordered_map<TreeNode*, pair<int,int>> mp;
        while(!post.empty()) {
            TreeNode* temp = post.top(); post.pop();
            int sum = temp->val, cnt = 1;
            if(temp->left) {
                sum += mp[temp->left].first;
                cnt += mp[temp->left].second;
            }
            if(temp->right) {
                sum += mp[temp->right].first;
                cnt += mp[temp->right].second;
            }
            mp[temp] = {sum, cnt};
            if(temp->val == sum / cnt) ans++;
        }

        return ans;
    }
};

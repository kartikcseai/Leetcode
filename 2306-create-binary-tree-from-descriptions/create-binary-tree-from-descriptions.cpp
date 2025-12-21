class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> children;
        for(auto& d:descriptions){
            int parent=d[0], child=d[1], isLeft=d[2];
            if(!mp.count(parent)) mp[parent]=new TreeNode(parent);
            if(!mp.count(child)) mp[child]=new TreeNode(child);
            if(isLeft) mp[parent]->left=mp[child];
            else mp[parent]->right=mp[child];
            children.insert(child);
        }
        for(auto& d:descriptions) if(!children.count(d[0])) return mp[d[0]];
        return NULL;
    }
};
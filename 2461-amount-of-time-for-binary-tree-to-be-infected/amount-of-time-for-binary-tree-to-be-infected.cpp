class Solution {
public:
    TreeNode* first;
    void find(TreeNode* root, int start){
        if(root==NULL) return;
        if(root->val==start) {
            first=root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        if(root==NULL) return;
        if(root->left!=NULL) parent[root->left]=root;
        if(root->right!=NULL) parent[root->right]=root;
        mark_parent(root->left, parent);
        mark_parent(root->right, parent);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parent(root, parent);
        unordered_set<TreeNode*> isInfected;
        isInfected.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first,0});
        int maxLevel=0;
        while(q.size()>0){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int level=p.second;
            maxLevel=max(maxLevel,level);
            TreeNode* temp=p.first;
            if(temp->left!=NULL){
                if(isInfected.find(temp->left)==isInfected.end()){
                    q.push({temp->left,level+1});
                    isInfected.insert(temp->left);
                }
            }
            if(temp->right!=NULL){
                if(isInfected.find(temp->right)==isInfected.end()){
                    q.push({temp->right,level+1});
                    isInfected.insert(temp->right);
                }
            }
            if(parent.find(temp)!=parent.end()){
                if(isInfected.find(parent[temp])==isInfected.end()){
                    q.push({parent[temp],level+1});
                    isInfected.insert(parent[temp]);
                }                
            }
        }
        return maxLevel;
    }
};
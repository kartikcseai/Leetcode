class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int best_level=1;
        long long max_sum=LLONG_MIN;
        while(!q.empty()){
            int size=q.size();
            long long sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front(); q.pop();
                sum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(sum>max_sum){
                max_sum=sum;
                best_level=level;
            }
            level++;
        }
        return best_level;
    }
};
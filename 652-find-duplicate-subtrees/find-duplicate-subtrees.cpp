/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<string, int> freq;
    vector<TreeNode*> result;
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string s = to_string(root->val) + "," +
                   serialize(root->left) + "," +
                   serialize(root->right);

        if (++freq[s] == 2) {  
            result.push_back(root);
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};

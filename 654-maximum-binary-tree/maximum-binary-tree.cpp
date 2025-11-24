class Solution {
public:
    TreeNode* maximum_binary_tree(vector<int>& nums, int lo, int hi){
        if(lo>hi) return NULL;
        int maxIndex = max_element(nums.begin()+lo, nums.begin()+hi+1)-nums.begin();
        int maxValue = nums[maxIndex];
        TreeNode* root = new TreeNode(maxValue);
        root->left=maximum_binary_tree(nums, lo, maxIndex-1);
        root->right=maximum_binary_tree(nums, maxIndex+1, hi);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maximum_binary_tree(nums, 0, nums.size()-1);    
    }
};
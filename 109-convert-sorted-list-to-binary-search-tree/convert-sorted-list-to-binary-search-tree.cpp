class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    TreeNode* buildBST(ListNode*& head, int lo, int hi) {
        if (lo > hi) return nullptr;

        int mid = lo + (hi - lo) / 2;

        TreeNode* left = buildBST(head, lo, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = buildBST(head, mid + 1, hi);

        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        return buildBST(head, 0, n - 1);
    }
};

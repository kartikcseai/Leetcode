/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> removeSet(nums.begin(), nums.end());
        ListNode temp(0, head);
        ListNode* pre = &temp;
        while (pre->next != nullptr) {
            if (removeSet.count(pre->next->val)) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return temp.next;
    }
};
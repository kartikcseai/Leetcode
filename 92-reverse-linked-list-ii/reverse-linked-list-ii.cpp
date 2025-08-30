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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int i = left - 1;
        int j = right - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        ListNode* dummy = new ListNode(arr[0]);
        ListNode* curr = dummy;
        for (int k = 1; k < arr.size(); k++) {
            curr->next = new ListNode(arr[k]);
            curr = curr->next;
        }

        return dummy;  
    }
};
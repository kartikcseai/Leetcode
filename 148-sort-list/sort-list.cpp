class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr; 

        vector<int> arr;
        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(arr[0]);
        ListNode* curr = dummy;

        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return dummy;
    }
};

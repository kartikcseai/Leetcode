class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nn = NULL;
        while(curr != NULL){
            nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn; 
        }
        return prev;
    }
};
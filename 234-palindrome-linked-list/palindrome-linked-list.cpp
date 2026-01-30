class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL) slow = slow->next;
        ListNode* prev = NULL;
        while(slow != NULL){
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        ListNode* left = head;
        ListNode* right = prev;
        while(right != NULL){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

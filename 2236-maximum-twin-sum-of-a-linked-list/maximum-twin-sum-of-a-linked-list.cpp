class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        while(slow!=NULL){
            ListNode* nxt=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nxt;
        }
        int ans=0;
        ListNode* left=head;
        ListNode* right=prev;
        while(right!=NULL){
            ans=max(ans,left->val+right->val);
            left=left->next;
            right=right->next;
        }
        return ans;
    }
};
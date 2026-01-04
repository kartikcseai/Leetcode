class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode*prev=dummy;
            while(prev->next!=NULL && prev->next->val<curr->val) prev=prev->next;
            ListNode* nextTemp=curr->next;
            curr->next=prev->next;
            prev->next=curr;
            curr=nextTemp;
        }
        return dummy->next;
    }
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return; // base case : empty list or single node
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){ // find middle of ll using slow and fast pointer
            slow=slow->next;
            fast=fast->next->next;
        } // slow is at middle
        // Reverse second half
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
        slow->next=NULL; // cut the list into two halfs 
        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        } // prev is head of reversed second half
        // merge both halfs
        ListNode* first=head;
        ListNode* second=prev;
        while(second!=NULL){
            ListNode* t1=first->next;
            ListNode* t2=second->next;
            first->next=second;
            second->next=t1;
            first=t1;
            second=t2;
        }
    }
};
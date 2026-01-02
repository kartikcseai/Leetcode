class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead=new ListNode(0);
        ListNode* greaterHead=new ListNode(0);
        ListNode* less=lessHead;
        ListNode* greater=greaterHead;
        while(head!=NULL){
            if(head->val<x){
                less->next=head;
                less=less->next;
            }
            else{
                greater->next=head;
                greater=greater->next;
            }
            head=head->next;
        }
        greater->next=NULL;
        less->next=greaterHead->next;
        ListNode* result=lessHead->next;
        delete lessHead;
        delete greaterHead;
        return result;
    }
};
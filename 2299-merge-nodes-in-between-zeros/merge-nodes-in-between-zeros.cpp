class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        int sum=0;
        head=head->next;
        while(head!=NULL){
            if(head->val==0){
                tail->next=new ListNode(sum);
                tail=tail->next;
                sum=0;
            }
            else sum+=head->val;
            head=head->next;
        }
        return dummy->next;
    }
};
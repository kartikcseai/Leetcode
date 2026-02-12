class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* result = NULL;
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry){
            int sum = carry;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = result;
            result = node;
        }
        return result;
    }
};
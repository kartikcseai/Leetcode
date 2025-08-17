/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* tempA=headA;
        int lenA=0;
        while(tempA != NULL){
            lenA++;
            tempA=tempA->next;
        }

        ListNode* tempB=headB;
        int lenB=0;
        while(tempB != NULL){
            lenB++;
            tempB=tempB->next;
        }

        tempA=headA;
        tempB=headB;

        if(lenA>lenB){
            int ext=lenA-lenB;
            for(int i=1;i<=ext;i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        else{
            int ext=lenB-lenA;
            for(int i=1;i<=ext;i++){
                tempB=tempB->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempB;
        }
    }
};
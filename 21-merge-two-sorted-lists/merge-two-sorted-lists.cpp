/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;

        ListNode* temp1=list1;
        while(temp1!=NULL){
            arr.push_back(temp1->val);
            temp1=temp1->next;
        }

        ListNode* temp2=list2;
        while(temp2!=NULL){
            arr.push_back(temp2->val);
            temp2=temp2->next;
        }

        if(arr.size()==0) return NULL;

        sort(arr.begin(), arr.end());

        ListNode* dummy=new ListNode(arr[0]);
        ListNode* curr=dummy;
        for(int i=0;i<=arr.size()-1;i++){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};
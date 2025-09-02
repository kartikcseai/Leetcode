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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=k-1;
        while(i<arr.size() && j<arr.size()){
            int x=i,y=j;
            while(x<y){
                swap(arr[x],arr[y]);
                x++;
                y--;
            }
            i=i+k;
            j=j+k;
        }
        ListNode* dummy=new ListNode(arr[0]);
        ListNode* curr=dummy;
        for(int i=0;i<arr.size();i++){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};
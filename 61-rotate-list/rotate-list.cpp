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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int n = arr.size();
        if (n == 0) return NULL;
        k = k % n;
        int i, j;

        // reverse last k elements
        for (i = n - k, j = n - 1; i < j; i++, j--){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        // reverse first n - k elements
        for (i = 0, j = n - k - 1; i < j; i++, j--){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        // reverse the entire array
        for (i = 0, j = n - 1; i < j; i++, j--){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        ListNode* dummy=new ListNode(arr[0]);
        ListNode* curr=dummy;
        for(int x=0 ; x<arr.size() ; x++){
            curr->next=new ListNode(arr[x]);
            curr=curr->next;
        }
        return dummy->next;
    }
};
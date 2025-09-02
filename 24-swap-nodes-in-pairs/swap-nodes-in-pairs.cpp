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
    ListNode* swapPairs(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        if(arr.size()==0) return NULL;
        int i=0;
        int j=i+1;
        while(i<(arr.size()-1)){
            swap(arr[i],arr[j]);
            i=i+2;
            j=j+2;
        }
        ListNode* dummy = new ListNode(arr[0]);
        ListNode* curr = dummy;

        for (int i = 0; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return dummy->next;
    }
};
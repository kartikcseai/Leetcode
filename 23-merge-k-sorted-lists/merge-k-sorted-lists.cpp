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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        if (arr.empty()) return NULL;
        sort(arr.begin(),arr.end());

        ListNode* dummy=new ListNode(arr[0]);
        ListNode* curr=dummy;
        for(int i=0;i<arr.size();i++){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr) {  
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0, j = arr.size() - 1;
        while(i < j) {
            if(arr[i] != arr[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};

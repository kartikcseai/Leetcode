class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_deque; // stores indicies of element in decreasing order
        deque<int> min_deque; // stores indicies of element in increasing order
        int l = 0, result = 0;
        for(int r = 0; r < nums.size(); r++){
            while(!max_deque.empty() && nums[max_deque.back()] < nums[r]) max_deque.pop_back();
            while(!min_deque.empty() && nums[min_deque.back()] > nums[r]) min_deque.pop_back();
            max_deque.push_back(r);
            min_deque.push_back(r);
            while(nums[max_deque.front()] - nums[min_deque.front()] > limit){
                if (max_deque.front() == l) max_deque.pop_front();
                if (min_deque.front() == l) min_deque.pop_front();
                l++;
            } 
            result = max(result, r - l + 1);
        } 
        return result;
    }
};
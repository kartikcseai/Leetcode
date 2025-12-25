class Solution {
public:
    int kadane(const vector<int>& arr){
        int max_sum=arr[0], curr_sum=arr[0];
        for(int i=1;i<arr.size();i++){
            curr_sum=max(arr[i],curr_sum+arr[i]);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int max_normal=kadane(nums);
        vector<int> inverted_nums=nums;
        for (int i=0;i<n;i++) inverted_nums[i]=-inverted_nums[i];
        int min_normal=kadane(inverted_nums);
        int total_sum=0;
        for(int i=0;i<n;i++) total_sum+=nums[i];
        int max_circular=total_sum+min_normal;
        if(max_circular==0) return max_normal;
        return max(max_normal,max_circular);
    }
};
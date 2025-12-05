class Solution {
public:
    int sum_of_subarray(int start, int end, vector<int>& nums){
        int sum=0;
        for(int i=start;i<=end;i++){
            sum+=nums[i];
        }
        return sum;
    }
    int countPartitions(vector<int>& nums) {
        vector<int> result; int count=0;
        for(int i=1;i<nums.size();i++){
            int first_sum=sum_of_subarray(0, i, nums);
            int second_sum=sum_of_subarray(i+1, nums.size()-1, nums);
            if(abs(second_sum-first_sum)%2==0) count++;
        }
        return count;
    }
};
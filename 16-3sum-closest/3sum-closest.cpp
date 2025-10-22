class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(k>j){
                int current_sum=nums[i]+nums[j]+nums[k];
                if(abs(current_sum-target)<abs(closest-target)) closest=current_sum;
                // adjustments
                if(target>current_sum) j++;
                else if (current_sum>target) k--;
                else return current_sum;
            }
        }
        return closest;
    }
};
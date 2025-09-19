class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int minn=INT_MAX;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            minn=min(minn,nums[mid]);
            if (nums[mid]<=nums[high]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return minn;
    }
};
class NumArray {
public:
    vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        prefix_sum=nums;
        for(int i=1;i<prefix_sum.size();i++) prefix_sum[i]+=prefix_sum[i-1];
    }
    int sumRange(int left, int right) {
        if(left==0) return prefix_sum[right];
        return prefix_sum[right]-prefix_sum[left-1];
    }
};

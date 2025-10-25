class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        vector<int> post(n);
        post[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
            post[n-1-i] = post[n-i] + nums[n-1-i];
        }
        
        if(post[1] == 0){
             return 0;
        }
        for(int i=1;i<n-1;i++){
            
            if(pre[i-1] == post[i+1]){
                return i;
            }
        }
        
        if(pre[n-2] == 0){
            return n-1;
        }
        
        return -1;
    }
};
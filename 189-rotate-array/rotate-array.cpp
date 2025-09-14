class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k%n;
        reverse(0,n-k-1,nums);
        reverse(n-k,n-1,nums);
        reverse(0,n-1,nums);
    }
    void reverse(int i, int j, vector<int>& nums){
        for(int x=i,y=j;x<=y;x++,y--){
            int temp=nums[x];
            nums[x]=nums[y];
            nums[y]=temp;
        }
    }
};
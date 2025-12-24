class Solution {
public:
    void merge(vector<int>& nums, vector<int>& idx, vector<int>& ans, int left, int mid, int right){
        vector<int> temp(right-left+1);
        int i=left,j=mid+1,k=0;
        int rightCount=0;
        while(i<=mid && j<=right){
            if(nums[idx[j]]<nums[idx[i]]){
                rightCount++;
                temp[k++]=idx[j++];
            }
            else{
                ans[idx[i]]+=rightCount;
                temp[k++]=idx[i++];
            }
        }
        while(i<=mid){
            ans[idx[i]]+=rightCount;
            temp[k++]=idx[i++];
        }
        while(j<=right) temp[k++]=idx[j++];
        for(int x=0;x<temp.size();x++) idx[left+x]=temp[x];
    }
    void mergeSort(vector<int>& nums, vector<int>& idx, vector<int>& ans, int left, int right){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums,idx,ans,left,mid);
        mergeSort(nums,idx,ans,mid+1,right);
        merge(nums,idx,ans,left,mid,right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i]=i;
        mergeSort(nums,idx,ans,0,n-1);
        return ans;
    }
};
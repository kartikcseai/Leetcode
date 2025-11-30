class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total=0;
        for(int x:nums) total+=x;
        long long need=total%p;
        if(need==0) return 0;
        unordered_map<long long,int> mp;
        mp[0]=-1;
        long long prefix=0;
        int res=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            long long mod=prefix%p;
            long long req=(mod-need+p)%p;
            if(mp.count(req)) res=min(res,i-mp[req]);
            mp[mod]=i;
        }
        if(res==nums.size()) return -1;
        return res==nums.size()+1?-1:res;
    }
};

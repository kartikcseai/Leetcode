class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD=1e9+7;
        long long ans=0;
        unordered_map<long long, long long> left,right;
        for(int x:nums) right[x]++;
        for(int x:nums){
            right[x]--;
            long long target=(long long)x*2;
            long long lc=0, rc=0;
            if(left.count(target)) lc=left[target];
            if(right.count(target)) rc=right[target];
            ans=(ans+(lc*rc)%MOD)%MOD;
            left[x]++;
        }
        return (int)ans;
    }
};
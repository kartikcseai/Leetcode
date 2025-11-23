class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n=nums.size();
        long long expected=n*(n+1)/2;
        long long actual=0;
        for(int x:nums) actual+=x;
        return expected-actual;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        // Check each bit position
        for (int bit=0;bit<32;bit++) {
            int count=0;
            // Count how many numbers have this bit set
            for (int x:nums) if ((x>>bit)&1) count++;
            // If bit count is not divisible by 3,
            // this bit belongs to the single number
            if (count%3!=0) result|=(1<<bit);
        }
        return result;
    }
};

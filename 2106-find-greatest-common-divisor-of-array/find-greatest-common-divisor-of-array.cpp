class Solution {
public:
    int GCD(int a, int b){
        if(a==0) return b;
        else return GCD(b%a, a);
    }
    int findGCD(vector<int>& nums) {
        int min_number=*min_element(nums.begin(),nums.end());
        int max_number=*max_element(nums.begin(),nums.end());
        return GCD(min_number,max_number);
    }
};
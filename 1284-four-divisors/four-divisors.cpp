class Solution {
public:
    vector<int> getDivisors(int num){
        vector<int> divisors;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                divisors.push_back(i);
                if(i!=num/i) divisors.push_back(num/i);
            }
        }
        return divisors;
    }
    int sumFourDivisors(vector<int>& nums) {
        int total_sum=0;
        for(int num:nums){
            vector<int> divisors=getDivisors(num);
            if(divisors.size()==4){
                int divisorSum=0;
                for(int divisor:divisors) divisorSum+=divisor;
                total_sum+=divisorSum;
            }
        }
        return total_sum;
    }
};
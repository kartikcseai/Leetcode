class Solution {
public:
    int commonFactors(int a, int b) {
        int common_factors=0;
        for(int i=min(a,b);i>=1;i--){
            if(a%i==0 && b%i==0) common_factors++;
        }
        return common_factors;
    }
};
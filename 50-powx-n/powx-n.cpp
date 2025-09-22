class Solution {
public:
    double myPow(double x, int n) {
        long long expo=n;
        if(expo==1) return x;
        return x*pow(x,expo-1);
    }
};
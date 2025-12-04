class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int size=n/2;
        vector<bool> isprime(size, true);
        for(int i=3;i*i<n;i+=2){
            if(isprime[i/2]){
                for(int j=i*i;j<n;j+=2*i) isprime[j/2]=false;
            }
        }
        int count_prime=1;
        for(int i=3;i<n;i+=2) 
            if(isprime[i/2]) count_prime++;
        return count_prime;
    }
};
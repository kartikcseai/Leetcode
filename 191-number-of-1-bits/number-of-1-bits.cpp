class Solution {
public:
    int hammingWeight(int n) {
        vector<int> a;
        while(n){
            int bit = n % 2;
            a.push_back(bit);
            n = n / 2;
        }
        int ans = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] == 1) ans++;
        return ans;
    }
};
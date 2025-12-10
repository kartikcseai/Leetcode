class Solution {
public:
    static int countPermutations(vector<int>& complexity) {
        const int ele_0=complexity[0], 
        ele_1=*min_element(complexity.begin()+1, complexity.end()),
        mod=1e9+7,
        n=complexity.size();
        if(ele_0>=ele_1) return 0;
        long long count=1;
        for(int i=1;i<=n-1;i++){
            count*=i;
            if(count>=mod) count%=mod;
        }
        return count;
    }
};
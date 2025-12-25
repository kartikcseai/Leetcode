class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k){
        sort(happiness.rbegin(),happiness.rend());
        long long total_happiness=0;
        for(int i=0;i<k;i++){
            int decrement_happiness=happiness[i]-i;
            if(decrement_happiness>0) total_happiness+=decrement_happiness;
            else break;
        }
        return total_happiness;
    }
};
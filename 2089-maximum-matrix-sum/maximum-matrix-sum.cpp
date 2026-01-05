class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int negative_count=0;
        int minAbs=INT_MAX;
        for(auto& row:matrix){
            for(int x:row){
                if(x<0) negative_count++;
                sum+=llabs(x);
                minAbs=min(minAbs,abs(x));
            }
        }
        if(negative_count%2==1) sum-=2LL*minAbs;
        return sum;
    }
};
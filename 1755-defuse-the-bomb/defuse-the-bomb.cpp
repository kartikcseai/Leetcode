class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(),0);
        if(k==0) return res;
        for(int i=0;i<code.size();i++){
            int sum=0;
            if(k>0) for(int j=1;j<=k;j++) sum+=code[(i+j)%code.size()];
            else for(int j=1;j<=-k;j++) sum+=code[(i-j+code.size())%code.size()];
            res[i]=sum;
        }
        return res;
    }
};
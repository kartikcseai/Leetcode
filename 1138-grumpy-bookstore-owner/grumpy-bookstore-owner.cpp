class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k=minutes;
        int prevloss=0;
        int n=customers.size();
        for(int i=0;i<k;i++){
            if(grumpy[i]==1) prevloss+=customers[i];
        }
        int maxloss=prevloss;
        int maxidx=0;
        int i=1,j=k;
        while(j<n){
            int currloss=prevloss;
            if(grumpy[j]==1) currloss+=customers[j];
            if(grumpy[i-1]==1) currloss-=customers[i-1];
            if(maxloss<currloss){
                maxloss=currloss;
                maxidx=i;
            }
            prevloss=currloss;
            i++;
            j++;
        }
        //filling zeros in the grumpy array window
        for(int i=maxidx;i<maxidx+k;i++){
            grumpy[i]=0;
        }
        //maximum satisfaction
        int maxS=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) maxS+=customers[i];
        }
        return maxS;
    }
};
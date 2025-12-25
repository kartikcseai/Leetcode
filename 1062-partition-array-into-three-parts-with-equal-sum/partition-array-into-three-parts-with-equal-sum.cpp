
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        for (auto num:arr) total+=num;
        if (total%3) return false;
        int target=total/3;
        int parts=0;
        int sum=0;
        for (int i=0;i<n-1;i++) {
            sum+=arr[i];
            if (target==sum) {
                parts++;
                sum=0;
                if(parts==2) return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count_apples=0;
        for(int i=0;i<apple.size();i++) count_apples+=apple[i];
        sort(capacity.rbegin(),capacity.rend());
        int check_capacity=0, count=0;
        for(int i=0;i<capacity.size();i++){
            if(check_capacity<count_apples){
                check_capacity+=capacity[i];
                count++;
            }
        }
        return count;
    }
};
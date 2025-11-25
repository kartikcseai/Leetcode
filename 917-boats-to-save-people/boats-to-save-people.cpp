class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int no_of_boat=0;
        int i=0, j=people.size()-1;
        while(j>=i){
            if(people[i]+people[j]<=limit){
                no_of_boat++;
                i++; j--;
            }
            else { // heaviest wala case 
                no_of_boat++;
                j--;
            }
        }
        return no_of_boat;
    }
};
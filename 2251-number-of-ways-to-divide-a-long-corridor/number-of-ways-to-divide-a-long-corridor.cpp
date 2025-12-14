class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD=1e9+7;
        long long result=1;
        int seatCount=0;
        for(int c:corridor) if(c=='S') seatCount++;
        if(seatCount==0 || seatCount%2!=0) return 0; // invalid if no seat or add number of seats
        int seatSeen=0, plantsBetween=0;
        bool countingPlants=false;   
        for(int c:corridor){
            if(c=='S'){
                seatSeen++;
                if(seatSeen%2==1){
                    if(countingPlants){
                        result=(result*(plantsBetween+1))%MOD;
                        plantsBetween=0;
                    }
                    countingPlants=true;
                }
            }
            else if (c=='P' && countingPlants && seatSeen%2==0) plantsBetween++;
        }
        return result;
    }
};
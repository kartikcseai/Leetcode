class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if(n==0 || meetings.empty()) return -1;
        sort(meetings.begin(),meetings.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0];
        });
        priority_queue<long,vector<long>,greater<long>> availableRooms;
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> roomEndTimes;
        for(int i=0;i<n;i++) availableRooms.push(i);
        vector<int> roomBookingCount(n,0);
        for(const auto& m:meetings){
            long start=m[0],end=m[1];
            while(!roomEndTimes.empty() && roomEndTimes.top().first<=start){
                int room=roomEndTimes.top().second;
                roomEndTimes.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty()){
                int room=availableRooms.top();
                availableRooms.pop();
                roomBookingCount[room]++;
                roomEndTimes.push({end,room});
            }
            else{
                auto [endTime,room]=roomEndTimes.top();
                roomEndTimes.pop();
                roomBookingCount[room]++;
                roomEndTimes.push({endTime+(end-start),room});
            }
        }
        int maxBookings=0,mostBookedRooms=-1;
        for(int i=0;i<n;i++){
            if(roomBookingCount[i]>maxBookings){
                maxBookings=roomBookingCount[i];
                mostBookedRooms=i;
            }
        }
        return mostBookedRooms;
    }
};
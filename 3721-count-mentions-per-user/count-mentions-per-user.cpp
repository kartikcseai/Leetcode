class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            int t1 = stoi(a[1]), t2 = stoi(b[1]);
            if (t1 != t2) return t1 < t2;
            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });
        for (auto &e : events) {
            int timestamp = stoi(e[1]);
            while (!pq.empty() && pq.top().first <= timestamp) {
                auto [_, uid] = pq.top();
                pq.pop();
                online[uid] = true;
            }

            if (e[0]=="OFFLINE") {
                int uid = stoi(e[2]);
                online[uid] = false;
                pq.push({timestamp + 60, uid});
            } 
            else {
                const string &s = e[2];

                if (s=="ALL") {
                    for (int i=0;i<numberOfUsers;i++)
                        mentions[i]++;
                }
                else if (s=="HERE"){
                    for (int i=0;i<numberOfUsers;i++)
                        if (online[i]) mentions[i]++;
                }
                else {
                    stringstream ss(s);
                    string token;
                    while (ss>>token) {
                        if (token.rfind("id", 0)==0) {
                            int uid=stoi(token.substr(2));
                            mentions[uid]++;
                        }
                    }
                }
            }
        }
        return mentions;
    }
};

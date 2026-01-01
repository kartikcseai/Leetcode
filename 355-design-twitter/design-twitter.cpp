class Twitter {
private:
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});}
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        followees[userId].insert(userId);
        for (int u : followees[userId]) {
            for (auto &t : tweets[u]) pq.push(t); 
        }
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);}
    void unfollow(int followerId, int followeeId) {
        if (followerId!=followeeId) followees[followerId].erase(followeeId);}
};

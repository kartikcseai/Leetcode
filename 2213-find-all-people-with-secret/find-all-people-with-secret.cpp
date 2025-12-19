class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;
        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            // People involved at this time
            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;
            // Collect all meetings at the same time
            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0], y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }
            // BFS on each connected component
            unordered_set<int> visited;
            for (int p : people) {
                if (visited.count(p)) continue;
                queue<int> q;
                vector<int> component;
                bool hasSecret = false;
                q.push(p);
                visited.insert(p);
                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    component.push_back(cur);
                    if (knows[cur]) hasSecret = true;
                    for (int nei : graph[cur]) {
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
                // If anyone in component has secret → everyone gets it
                if (hasSecret) {
                    for (int x : component) {
                        knows[x] = true;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knows[i]) result.push_back(i);
        }
        return result;
    }
};

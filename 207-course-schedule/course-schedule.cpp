class Solution {
public:
    bool is_cyclic_dfs(int src, vector<bool>& visited, vector<bool>& recursion_path, vector<vector<int>>& edges){
        visited[src] = true;
        recursion_path[src] = true;
        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0], u = edges[i][1];
            if(u == src){
                if(!visited[v]) {
                    if(is_cyclic_dfs(v, visited, recursion_path, edges)) return true;
                } else if(recursion_path[v]) return true;
            }
        }
        recursion_path[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<bool> recursion_path(n, false);
        for(int i = 0; i < n; i++){
            if(is_cyclic_dfs(i, visited, recursion_path, edges)) return false;
        }
        return true;
    }
};
class Solution {
  public:
    // bool dfs(int cur, vector<vector<int>> &edges, vector<int> &visited, vector<int> &path) {
    //     visited[cur] = 1;
    //     path[cur] = 1;
    
    //     for (int k : edges[cur]) {
    //         if (!visited[k]) {
    //             if (dfs(k, edges, visited, path))
    //                 return true;
    //         } else if (path[k]) {
    //             return true;  
    //         }
    //     }
    
    //     path[cur] = 0;  
    //     return false;
    // }
    
    // bool isCyclic(int V, vector<vector<int>> &edges) {
    //     vector<int> visited(V, 0);
    //     vector<int> path(V, 0);
    //     for (int i = 0; i < V; i++) {
    //         if (!visited[i]) {
    //             if (dfs(i, edges, visited, path))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
        }
        
        int n = adj.size();
        vector<int>indegree(n,0);
        queue<int> q ;
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            for(auto k : adj[i]){
                indegree[k]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto k : adj[front]){
                indegree[k]--;
                if(indegree[k] == 0){
                    q.push(k);
                }
            }
        }
        return ans.size() != n;
    }
};
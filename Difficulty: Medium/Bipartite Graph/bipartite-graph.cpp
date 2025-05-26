class Solution {
  public:
    vector<vector<int>> constructadj(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        return adj;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> color(V, -1);
    
    vector<vector<int>> adj = constructadj(V,edges);
    queue<int> q;
    
    for(int i = 0; i < V; i++) {

        if(color[i] == -1) {

            color[i] = 0;
            q.push(i);
            
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                for(auto &v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
        return true;
        
    }
};
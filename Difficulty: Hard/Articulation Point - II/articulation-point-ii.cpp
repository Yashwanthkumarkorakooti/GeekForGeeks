class Solution {
  public:
    void dfs(int cur, int parent, vector<vector<int>> &adj, vector<int>&visited, 
                vector<int>&dist, vector<int>&low, vector<int> &ap, int & timer){
        visited[cur] = 1 ;
        dist[cur] = timer ;
        low[cur] = timer;
        timer++;
        int child = 0 ;
        for(auto k : adj[cur]){
            if (k == parent) continue;
            if(k != parent){
                if(!visited[k]){
                    child++;
                    dfs(k,cur,adj,visited,dist,low,ap,timer);
                    low[cur] = min(low[cur], low[k]);
                    if (parent != -1 && low[k] >= dist[cur]) {
                        ap[cur] = 1;
                    }
                }
                else{
                    low[cur] = min(low[cur], dist[k]);
            }
            }
        }
        if (parent == -1 && child > 1) {
            ap[cur] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto k : edges){
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        vector<int> visited(V,0);
        vector<int> dist(V);
        vector<int> low(V);
        int timer = 0 ;
        vector<int> ap(V,0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, dist, low, ap, timer);
            }
        }

        
        vector<int> ans ;
        for(int i=0;i<V;i++){
            if(ap[i] == 1) ans.push_back(i);
        }
        
        if(ans.empty()) return {-1} ;
        sort(ans.begin(),ans.end());
        return ans;
    }
};
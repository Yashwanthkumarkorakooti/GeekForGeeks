class Solution {
  public:
    void dfs(int cur,int parent,vector<int>&visited,vector<vector<int>>&adj,vector<int>&disc,
            vector<int>&low, int &timer, vector<vector<int>> &bridges){
        visited[cur] = 1 ;
        disc[cur] = timer ;
        low[cur] = timer ;
        timer++;
        for(auto k : adj[cur]){
            if(k != parent){
                if(!visited[k]){
                    dfs(k,cur,visited,adj,disc,low,timer,bridges);
                    low[cur] = min(low[cur], low[k]);
                    if(low[k] > disc[cur]){
                        bridges.push_back({cur,k});
                    }
                }else{
                    low[cur] = min(low[cur], low[k]);
                }
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for(auto k : edges){
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        vector<int>visited(V,0);
        vector<int> disc(V) ;
        vector<int> low(V) ;
        vector<vector<int>> bridges ;
        int timer = 0 ;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj, disc, low, timer, bridges);
            }
        }
        for (auto& bridge : bridges) {
            if ((bridge[0] == c && bridge[1] == d) || (bridge[0] == d && bridge[1] == c)) {
                return true;
            }
        }
        return false;
    }
};
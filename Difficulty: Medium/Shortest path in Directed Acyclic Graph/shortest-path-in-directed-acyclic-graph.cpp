// User function Template for C++
class Solution {
  public:
    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int>&visited, stack<int>&stk){
        visited[node] = 1 ;
        for(auto& k : adj[node]){
            int neighbour = k.first;
            if(!visited[neighbour]){
                dfs(neighbour,adj,visited,stk);
            }
        }
        stk.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int>visited(V,0);
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto& edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        stack<int> stk;
        dfs(0,adj,visited,stk);
        
        vector<int>dist(V,INT_MAX);
        dist[0] = 0 ;
        
        while(!stk.empty()){
            int cur = stk.top();
            stk.pop();
            if(dist[cur] != INT_MAX){
                for(auto& k : adj[cur]){
                    int neighbour = k.first;
                    int weight = k.second;
                    if(dist[cur]+ weight < dist[neighbour]){
                        dist[neighbour] = dist[cur] + weight;
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i] == INT_MAX) dist[i] = -1 ;
        }
        
        return dist;
    }
};

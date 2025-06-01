class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        queue<int>q ;
        q.push(src);
        
        vector<int> visited(n,0);
        visited[src] = 1 ;
        
        vector<int> dist(n,-1);
        dist[src] = 0 ;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto& k: adj[cur]){
                if(!visited[k]){
                    dist[k] = dist[cur]+1;
                    visited[k] = 1 ;
                    q.push(k);
                }
            }
        }
        return dist;
    }
};
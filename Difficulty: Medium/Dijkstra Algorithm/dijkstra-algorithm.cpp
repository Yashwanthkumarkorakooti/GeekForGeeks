// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e : edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        
        int n = adj.size();
        vector<int>dist(n,INT_MAX);
        dist[src] = 0 ;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto x = pq.top();
            int d = x.first;
            int cur = x.second;
            pq.pop();
            
            if(d>dist[cur]) continue;
            
            for(auto k : adj[cur]){
                int neighbour = k.first;
                int weight = k.second;
                if(dist[cur]+weight < dist[neighbour]){
                    dist[neighbour] = dist[cur]+weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        return dist;
    }
};
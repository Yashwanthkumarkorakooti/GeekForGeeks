class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &y : flights){
            adj[y[0]].push_back({y[1],y[2]});
        }
        queue<pair<int,pair<int,int>>> q ;
        q.push({1, {0, src}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto x = q.front() ;
            q.pop();
            int length = x.first;
            int d = x.second.first ;
            int cur = x.second.second;

            for(auto edge : adj[cur]){
                int neighbour = edge.first;
                int weight = edge.second ;
                if((d+weight < dist[neighbour]) && (length <= k+1)) {
                    dist[neighbour] = d + weight;
                    q.push({length+1,{dist[neighbour],neighbour}});
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
        
    }
};
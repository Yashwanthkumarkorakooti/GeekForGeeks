// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0 ;

        vector<int> paths(n,0);
        paths[0] = 1 ;

        const int MOD = 1e9 + 7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>> > pq ;
        pq.push({0,0});

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            long long d = x.first ;
            int cur = x.second ;
            for(auto k : adj[cur]){
                int neighbour = k.first ;
                int weight = k.second ;
                long long new_dist  = d + weight ;
                if(new_dist < dist[neighbour]){
                    dist[neighbour] = new_dist ;
                    pq.push({dist[neighbour],neighbour});
                    paths[neighbour] = paths[cur];
                }
                else if (new_dist == dist[neighbour]){
                    paths[neighbour] = (paths[neighbour]+paths[cur])%MOD;
                }
            }
        }
        return paths[n-1];
        
    }
};
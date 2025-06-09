// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        dist[src] = 0 ;
        
        for(int i=1;i<V;i++){
            for(auto& x:edges){
                int a = x[0];
                int b = x[1];
                int weight = x[2];
                if(dist[a] != 1e8 && dist[a]+weight < dist[b]){
                    dist[b] = dist[a] + weight ;
                }
            }
        }
        for(auto& x:edges){
            int a = x[0];
            int b = x[1];
            int weight = x[2];
            if(dist[a] != 1e8 && dist[a]+weight < dist[b]){
                return {-1} ;
            }
        }
        return dist ;
    }
};

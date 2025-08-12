class Solution {
  public:
  
    bool isSafe(int node, vector<vector<int>> &adj, vector<int>&color, int c){
        for (int neighbor : adj[node]) {
            if (color[neighbor] == c) return false;
        }
        return true;
    }
    
    bool solve(int node, vector<vector<int>> &adj, vector<int>&color, int m){
        int n = adj.size();
        if(node == n) return true;
        
        for(int i=1;i<=m;i++){
            if(isSafe(node,adj,color,i)){
                color[node] = i;
                if(solve(node+1,adj,color,m)) return true;
                color[node] = 0 ;
            }
        }
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> color(v,0);
        return solve(0,adj,color,m);
    }
};
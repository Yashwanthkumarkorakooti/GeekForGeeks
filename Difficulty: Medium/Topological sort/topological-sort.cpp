class Solution {
  public:
    // void dfs(int cur,vector<vector<int>>& adj, vector<int>&visited, stack<int>&stk){
    //     visited[cur] = 1 ;
    //     for(auto k : adj[cur]){
    //         if(!visited[k]){
    //             dfs(k,adj,visited,stk);
    //         }
    //     }
    //     stk.push(cur);
    // }
    
    // vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //     vector<vector<int>> adj(V);
    //     for (auto& e : edges) {
    //         int u = e[0], v = e[1];
    //         adj[u].push_back(v);
    //     }
    
    //     stack<int> stk;
    //     vector<int> visited(V,0);
    //     for(int i=0;i<V;i++){
    //         if(!visited[i]){
    //             dfs(i,adj,visited,stk);
    //         }
    //     }
        
    //     vector<int> ans ;
    //     while(!stk.empty()){
    //         int x = stk.top();
    //         ans.push_back(x);
    //         stk.pop();
    //     }
        
    //     return ans;
    // }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
      vector<vector<int>> adj(V);
      for(auto & e : edges){
          int u = e[0], v = e[1];
          adj[u].push_back(v);
      }
      
      int n = adj.size();
      vector<int> indegree(n,0);
      queue<int> q;
      vector<int> ans;
      
      for(int i=0;i<n;i++){
          for(auto k : adj[i]){
              indegree[k]++;
          }
      }
      
      for(int i=0;i<n;i++){
        if(indegree[i] == 0)
            q.push(i);
      }
      
      while(!q.empty()){
          int front = q.front();
          q.pop();
          ans.push_back(front);
          
          for(auto k : adj[front]){
              indegree[k]--;
              if(indegree[k] == 0){
                  q.push(k);
              }
          }
      }
      return ans;
    }
};
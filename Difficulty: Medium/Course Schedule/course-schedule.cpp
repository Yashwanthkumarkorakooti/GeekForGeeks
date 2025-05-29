class Solution {
  public:
    vector<int> topologicalSort(vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> indegree(n,0);
        queue<int> q ;
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
                if(indegree[k] == 0)
                    q.push(k);
            }
        }
        if (ans.size() == n) return ans;
        return {};
    }
    
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(n);
        for(auto k : prerequisites){
            int u = k[0] , v = k[1] ;
            adj[v].push_back(u);
        }

        return topologicalSort(adj);
    }
};
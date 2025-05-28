// User function Template for C++

class Solution {
  public:
    bool dfs(int cur, vector<int> adj[], vector<int>&visited,vector<int>&path,vector<int>&ans){
        visited[cur] = 1 ;
        path[cur] = 1 ;
        
        for(auto k : adj[cur]){
            if(!visited[k]){
                if(dfs(k,adj,visited,path,ans))
                    return true;
            }else if(path[k]){
                return true;
            }
        }
        
        path[cur] = 0 ;
        ans.push_back(cur);
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs(i,adj,visited,path,ans);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& e: edges){
            if(e[0] < 1 || e[0] > n || e[1] < 1 || e[1] > n)
                return {-1}; 
            
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        int start = 1;
        int end = n;
        
        vector<int> dist(n+1, INT_MAX);
        dist[start] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});
        
        vector<int> parent(n+1, -1);
        
        int countPushes = 0;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int d = x.first;
            int cur = x.second;
            
            if(d > dist[cur]) continue;
            
            for(auto k : adj[cur]){
                int neighbour = k.first;
                int weight = k.second;
                if(dist[cur] + weight < dist[neighbour]){
                    dist[neighbour] = dist[cur] + weight;
                    pq.push({dist[neighbour], neighbour});
                    parent[neighbour] = cur;

                    if(++countPushes > 1e7) return {-1}; 
                }
            }
        }
        
        if(dist[end] == INT_MAX) return {-1};
        
        vector<int> ans;
        for(int temp = end; temp != -1; temp = parent[temp]){
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());

        vector<int> res = {dist[end]};
        res.insert(res.end(), ans.begin(), ans.end());
        return res;
    }
};

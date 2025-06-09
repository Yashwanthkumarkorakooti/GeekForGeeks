class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> visited(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});
        int mst_weight = 0;

        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;

            visited[u] = 1;
            mst_weight += weight;

            for (auto &edge : adj[u]) {
                int v = edge[0];
                int w = edge[1];
                if (!visited[v]) {
                    pq.push({w, v});
                }
            }
        }

        return mst_weight;
    }
};

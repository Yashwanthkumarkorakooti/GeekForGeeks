class DisjointSet {
private:
    vector<int> parent;
public:
    DisjointSet(int size) {
        parent.resize(size, -1);
    }

    int find(int node) {
        if (parent[node] < 0)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionSize(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a != parent_b) {
            if (parent[parent_a] < parent[parent_b]) {
                parent[parent_a] += parent[parent_b];
                parent[parent_b] = parent_a;
            } else {
                parent[parent_b] += parent[parent_a];
                parent[parent_a] = parent_b;
            }
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;

        for (int a = 0; a < V; a++) {
            for (auto &k : adj[a]) {
                int b = k[0];         
                int weight = k[1];    
                if (a < b)
                    edges.push_back({weight, {a, b}});
            }
        }

        sort(edges.begin(), edges.end());
        int mst_weight = 0;
        DisjointSet dis_set(V);

        for (auto &x : edges) {
            int weight = x.first;
            int a = x.second.first;
            int b = x.second.second;

            if (dis_set.find(a) != dis_set.find(b)) {
                mst_weight += weight;
                dis_set.unionSize(a, b);
            }
        }

        return mst_weight;
    }
};

    // int spanningTree(int V, vector<vector<int>> adj[]) {
    //     vector<int> visited(V, 0);
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //     pq.push({0, 0});
    //     int mst_weight = 0;

    //     while (!pq.empty()) {
    //         int weight = pq.top().first;
    //         int u = pq.top().second;
    //         pq.pop();

    //         if (visited[u]) continue;

    //         visited[u] = 1;
    //         mst_weight += weight;

    //         for (auto &edge : adj[u]) {
    //             int v = edge[0];
    //             int w = edge[1];
    //             if (!visited[v]) {
    //                 pq.push({w, v});
    //             }
    //         }
    //     }

    //     return mst_weight;
    // }
// };

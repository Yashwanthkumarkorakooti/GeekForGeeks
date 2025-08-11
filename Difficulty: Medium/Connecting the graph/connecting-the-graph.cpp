// User function Template for C++
class DisjointSet{
  public:
    vector<int> parent;
    DisjointSet(int n){
        parent.resize(n+1,-1);
    }
    
    int find(int node){
        if(parent[node] < 0)
            return node;
        return parent[node] = find(parent[node]);
    }
    
    void unionSize(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);
        
        if(parent_a != parent_b){
            if(parent[parent_a] < parent[parent_b]){
                int temp = parent[parent_b];
                parent[parent_b] = parent_a ;
                parent[parent_a] += temp;
            }
            else{
                int temp = parent[parent_a];
                parent[parent_a] = parent_b ;
                parent[parent_b] += temp;
            }
        }
    }
    
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        int e = edge.size();
        if(e < n-1) return -1;
        
        DisjointSet dis_set(n);
        for(auto &k : edge){
            int a = k[0];
            int b = k[1];
            dis_set.unionSize(a,b);
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(dis_set.parent[i] < 0) count++;
        }
        
        return count-1;
    }
};
// User function Template for C++
class DisjointSet{
    public:
        vector<int>parent;
        DisjointSet(int size){
            parent.resize(size,-1);
        }
        
        int find(int node){
            if(parent[node] < 0){
                return node ;
            }
            return parent[node] = find(parent[node]) ;
        }
        
        void unionSize(int a, int b){
            int parent_a = find(a);
            int parent_b = find(b);
            if(parent_a != parent_b){
                if(parent[parent_a] < parent[parent_b]){
                    int temp = parent[parent_b];
                    parent[parent_b] = parent_a ;
                    parent[parent_a] += temp ;
                }else{
                    int temp = parent[parent_a];
                    parent[parent_a] = parent_b ;
                    parent[parent_b] += temp ;
                }
            }
        }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet dis_set(n*n);
        int ans = 0 ;
        
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 1){
                    int node = n*r+c ;
                    if(r+1 < n && grid[r+1][c] == 1){
                        int adj_node = n*(r+1) + c ;
                        dis_set.unionSize(node,adj_node);
                    }
                    if(c+1 < n && grid[r][c+1] == 1){
                        int adj_node = n*r + c+1 ;
                        dis_set.unionSize(node,adj_node);
                    }
                }
            }
        }
        
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 0){
                    set<int> s;
                    if(r > 0 && grid[r-1][c] == 1){
                        int adj_node = n*(r-1)+c ;
                        s.insert(dis_set.find(adj_node));
                    }
                    if(r+1 < n && grid[r+1][c] == 1){
                        int adj_node = n*(r+1)+c ;
                        s.insert(dis_set.find(adj_node));
                    }
                    if(c > 0 && grid[r][c-1] == 1){
                        int adj_node = n*r+(c-1) ;
                        s.insert(dis_set.find(adj_node));
                    }
                    if(c+1 < n && grid[r][c+1] == 1){
                        int adj_node = n*r+(c+1) ;
                        s.insert(dis_set.find(adj_node));
                    }
                    
                    int count = 1 ;
                    for(auto x : s){
                        count += (-dis_set.parent[dis_set.find(x)]);
                    }
                    ans = max(ans,count);
                }
            }
        }
        
        if(ans == 0) ans = n*n;
        return ans;
    }
};

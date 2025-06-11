// User function Template for C++
class DisjointSet {
    
    private:
    
        vector<int> parent;
    
    public:
        DisjointSet(int size) {
            parent.resize(size, -1);
        }
    
        int find(int node) {
            if (parent[node] < 0) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }
    
    
        void unionSize(int a, int b) {
            
            int parent_a = find(a);
            int parent_b = find(b);
        
            if (parent_a != parent_b) {
                if (parent[parent_a] < parent[parent_b]) {
                    
                    int temp = parent[parent_b];
                    parent[parent_b] = parent_a;
                    parent[parent_a] += temp;
                } else {
                    
                    int temp = parent[parent_a];
                    parent[parent_a] = parent_b;
                    parent[parent_b] += temp;
                }
            }
       }
};

class Solution {
  public:
    vector<int> numOfIslands(int m, int n, vector<vector<int>> &operators) {
        DisjointSet dis_set(m*n);
    
        vector<vector<int>> grid(m, vector<int>(n, 0));
    
        vector<int> ans;
    
        int count=0;
        for(auto x: operators)
        {
            int r=x[0];
            int c=x[1];
            if(grid[r][c]==0)
            {
                count++;
                grid[r][c]=1;
                int node=n*r+c;
    
                if(r>0 && grid[r-1][c]==1)
                {
                    int adj_node=n*(r-1)+c;
                    if(dis_set.find(adj_node)!=dis_set.find(node))
                    {
                        count--;
                        dis_set.unionSize(node, adj_node);
                    }
                }
    
                if(r+1<m && grid[r+1][c]==1)
                {
                    int adj_node=n*(r+1)+c;  
                    if(dis_set.find(adj_node)!=dis_set.find(node))
                    {
                        count--;
                        dis_set.unionSize(node, adj_node);
                    }
                }
    
    
                if(c>0 && grid[r][c-1]==1)
                {
                    int adj_node=n*r+(c-1);
                    if(dis_set.find(adj_node)!=dis_set.find(node))
                    {
                        count--;
                        dis_set.unionSize(node, adj_node);
                    }
                }
    
                if(c+1<n && grid[r][c+1]==1)
                {
                    int adj_node=n*r+(c+1);
                    if(dis_set.find(adj_node)!=dis_set.find(node))
                    {
                        count--;
                        dis_set.unionSize(node, adj_node);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};








































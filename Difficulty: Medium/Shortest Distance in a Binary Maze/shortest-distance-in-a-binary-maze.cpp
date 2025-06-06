// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, pair<int,int>> > q;
        q.push({0,{source.first,source.second}});
        
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[source.first][source.second] = 0 ;
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int d = x.first;
            int row = x.second.first ;
            int col = x.second.second ;
            
            if(row == destination.first && col == destination.second)
                return d ;
                
            
            if(row > 0 && grid[row-1][col]){
                if(dist[row][col]+1 < dist[row-1][col]){
                    dist[row-1][col] = dist[row][col]+1;
                    q.push({dist[row-1][col],{row-1,col}});
                }
            }
            if(row+1 < m && grid[row+1][col]){
                if(dist[row][col]+1 < dist[row+1][col]){
                    dist[row+1][col] = dist[row][col]+1;
                    q.push({dist[row+1][col],{row+1,col}});
                }
            }
            if(col > 0 && grid[row][col-1]){
                if(dist[row][col]+1 < dist[row][col-1]){
                    dist[row][col-1] = dist[row][col]+1;
                    q.push({dist[row][col-1],{row,col-1}});
                }
            }
            if(col+1 < n && grid[row][col+1]){
                if(dist[row][col]+1 < dist[row][col+1]){
                    dist[row][col+1] = dist[row][col]+1;
                    q.push({dist[row][col+1],{row,col+1}});
                }
            }
        }
        return -1;
        
    }
};

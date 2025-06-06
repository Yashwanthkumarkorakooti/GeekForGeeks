
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &grid) {
        int m = rows;
        int n = columns;

        pair<int,int> start = {0,0};
        pair<int,int> end = {m-1,n-1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{start.first,start.second}});

        vector<vector<int>>diff(m, vector<int>(n,INT_MAX));
        diff[start.first][start.second] = 0 ;

        while(!pq.empty()){
            auto x = pq.top() ;
            pq.pop();
            int d = x.first ;
            int row = x.second.first ;
            int col = x.second.second;

            if(row > 0){
                int delta = abs(grid[row][col] - grid[row-1][col]);
                int effort = max(delta, diff[row][col]);

                if(effort < diff[row-1][col]){
                    diff[row-1][col] = effort;
                    pq.push({effort,{row-1,col}});
                }
            }

            if(row+1 < m){
                int delta = abs(grid[row][col] - grid[row+1][col]);
                int effort = max(delta, diff[row][col]);

                if(effort < diff[row+1][col]){
                    diff[row+1][col] = effort;
                    pq.push({effort,{row+1,col}});
                }
            }

            if(col > 0){
                int delta = abs(grid[row][col] - grid[row][col-1]);
                int effort = max(delta, diff[row][col]);

                if(effort < diff[row][col-1]){
                    diff[row][col-1] = effort;
                    pq.push({effort,{row,col-1}});
                }
            }

            if(col+1 < n){
                int delta = abs(grid[row][col] - grid[row][col+1]);
                int effort = max(delta, diff[row][col]);

                if(effort < diff[row][col+1]){
                    diff[row][col+1] = effort;
                    pq.push({effort,{row,col+1}});
                }
            }
        }
        return diff[end.first][end.second];
    }
};

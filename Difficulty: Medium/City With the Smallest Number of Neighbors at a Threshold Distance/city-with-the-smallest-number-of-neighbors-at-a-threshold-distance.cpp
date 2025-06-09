class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            matrix[i][i] = 0 ;
        }

        for(auto &e:edges){
            int a = e[0];
            int b = e[1];
            int wt = e[2];
            matrix[a][b] = wt;
            matrix[b][a] = wt ;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9)
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int minCities = 1e9;
        int ans = -1;

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(i != j && matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }

            // Correct tie-breaker: prefer higher index
            if(count < minCities || (count == minCities && i > ans)){
                minCities = count;
                ans = i;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prior(3);
        vector<int> cur(3);
        
        prior[0] = arr[0][0];
        prior[1] = arr[0][1];
        prior[2] = arr[0][2];
        
        for(int i=1;i<=n-1;i++){
            for(int j=0;j<=2;j++){
                cur[j] = arr[i][j] + max(prior[(j+1)%3] , prior[(j+2)%3]);
            }
            for(int j=0;j<=2;j++){
                prior[j] = cur[j];
            }
        }
        
        int a = cur[0];
        int b = cur[1];
        int c = cur[2];
        
        return max(max(a,b),c);
    }
};
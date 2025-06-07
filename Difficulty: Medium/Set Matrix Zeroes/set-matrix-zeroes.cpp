//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();   // row
        int n = matrix[0].size();  // col

        int firstRow = -1;
        int firstCol = -1 ;

        for(int j=0;j<n;j++){
            if(matrix[0][j] == 0) firstRow = 0 ;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0] == 0) firstCol = 0 ;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0 ;
                    matrix[0][j] = 0 ;
                }
            }
        }


        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0 ;
                }
            }
        }

        if(firstRow == 0){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0 ;
            }
        }
        if(firstCol == 0){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0 ;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends